#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<array>
#include<map>

struct chest {
	int T;
	int name;
	bool open;
	bool breaker;
	std::vector<int> K;
	bool operator==(chest& c) const
	{
		return name == c.name;
	}
};


struct instance {
	std::array<int, 200> K;
	std::vector<chest> C;
	int openChests, keysLeft;
	instance() : openChests(0) {std::fill(K.begin(), K.end(), 0);};
	
	void removeKey(const int Key)
	{
		assert(K[Key]>0);
		K[Key]--;
		keysLeft--;
	}
	void openChest(const unsigned int Pos)
	{
		openChests++;
		assert(C.size()>Pos);
		removeKey(C[Pos].T);
		for (unsigned int i=0; i<C[Pos].K.size(); i++)
		{
			K[C[Pos].K[i]]++;
			keysLeft++;
		}
		C[Pos].open = 1;
	}
	void closeChest(const unsigned int Pos)
	{
		openChests--;
		assert(C.size()>Pos);
		assert(C[Pos].open==1);
		K[C[Pos].T]++;
		keysLeft++;
		for (unsigned int i=0; i<C[Pos].K.size(); i++)
		{
			K[C[Pos].K[i]]--;
			keysLeft--;
		}
		C[Pos].open = 0;
	}
};


bool cheapTest(const instance& I)
{
	std::array<int, 200> NEED, HAVE;
	std::fill(NEED.begin(), NEED.end(), 0);
	std::fill(HAVE.begin(), HAVE.end(), 0);
	for (int i=0; i<200; i++)
		HAVE[i]+=I.K[i];
	
	for (int i=0; i<I.C.size(); i++)
	{
		NEED[I.C[i].T]++;
		for (int j=0; j<I.C[i].K.size(); j++)
			HAVE[I.C[i].K[j]]++;
	}
	for (int i=0; i<200; i++)
		if (NEED[i]>HAVE[i])
			return false;
	return true;
}

long long CNT = 0;
std::vector<std::vector<int>> G;
int done = 0;
void crawl(instance& I, std::vector<int>& K)
{
	CNT++;
// 	if (CNT%10000000==0)
// 	{
// 		std::cerr << CNT << " " << K.size() << "\n";
// 	}
	if ((I.keysLeft==0) && (I.openChests!=I.C.size()))
	{
		return;
	}
	if (I.openChests==I.C.size())
	{
		G.push_back(K);
		done = 1;
		return;
	}
	
	for (unsigned int i=0; i<I.C.size() && done==0; i++)
	{
		if (I.C[i].open==0 && I.K[I.C[i].T]>0)
		{
			I.openChest(i);
			K.push_back(I.C[i].name);
			crawl(I, K);
			K.pop_back();
			I.closeChest(i);
			if (I.C[i].breaker)
				return;
		}
	}
}


std::vector<int> doit(const instance P)
{
	std::vector<int> R;
	std::vector<int> T;
	G.clear();
	done = 0;
	instance I = P;
// 	std::cerr << I.keysLeft << " " << I.C.size() << "\n";
	if (cheapTest(I))
		crawl(I, T);
	std::sort(G.begin(), G.end());
	if (G.empty())
		return R;
	return G[0];
}


std::vector<std::vector<int>> read()
{
	std::vector<std::vector<int>> R;
	
	int T;
	std::cin >> T;
	for (int i=0; i<T; i++)
	{
		int K,N, DUMMY;
		
		std::cin >> K >> N;
		instance L;
		for (int j=0; j<K; j++)
		{
			std::cin >> DUMMY;		
			L.K[DUMMY]++;
		}
		L.keysLeft = K;
		for (int j=0; j<N; j++)
		{
			int TI, KI;
			std::cin >> TI >> KI;
			L.C.push_back({});
			L.C.back().T = TI;
			L.C.back().name = j+1;
			L.C.back().open = false;
			for (int k=0; k<KI; k++)
			{
				std::cin >> DUMMY;
				L.C.back().K.push_back(DUMMY);;
			}
			if (std::find(L.C.back().K.begin(), L.C.back().K.end(), L.C.back().T)!=L.C.back().K.end())
				L.C.back().breaker = 1;
			else
				L.C.back().breaker = 0;
		}
		R.push_back(doit(L));
		std::cerr << "done " << i << "\n";
	}
	return R;
}

void output(const std::vector<std::vector<int>>& R)
{
	for (unsigned int i=0; i<R.size(); i++)
	{
		std::cout << "Case #" << i+1 << ": ";
		if (R[i].size())
		{
			for (unsigned int j=0; j<R[i].size(); j++)
				std::cout << R[i][j] << " ";
		}
		else
		{
			std::cout << "IMPOSSIBLE";
		}
		std::cout << "\n";
	}
}

int main(int argc, char* argv[])
{
	const auto R = read();
	output(R);
}
