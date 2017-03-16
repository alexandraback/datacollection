#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
//	#define D(x...) 0
#endif
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <string>
#include <limits.h>
#include <iterator>

#include <cctype>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);

	for (int test=1;test<=nTests;test++) 
	{
		int N, S, P;
		cin >> N >> S >> P;
		//N num of googlers, S num of surprising scores, want number of scores with best result of at least P
		
		int numGood = 0;
		for (int i = 0; i<N; i++)
		{
			int num;
			cin >> num;
			//points.push_back(num);

			int regMax = (num / 3) + (num % 3 > 0);
			if (regMax >= P)
			{
				numGood++;
			}
			else if (num == 0)
			{}
			else
			{
				int surpriseMax = num / 3 + 1 + (num % 3 == 2);
				if (surpriseMax >= P && S > 0)
				{
					numGood++; 
					S--;
				}
			}
		}

		int output = numGood;
		printf("Case #%d: %d\n",test,output);
	}
}

/*
string line;
std::map<char,char> mapping;
string available = "q";

int Replace()
{
	string missing;
	for (auto it=line.begin(); it!=line.end(); it++)
	{
		if (*it == 32 || *it >= 97)
		{}
		else
		{
			auto newcharIter = mapping.begin();
			if ((newcharIter = mapping.find(*it)) != mapping.end())
			{
				*it = newcharIter->second;
			}
			else
			{
				if (missing.find(*it) == string::npos)
					missing += *it;
			}
		}
	}
	if (missing.size() > 0)
		fprintf(stderr,"[%s] - still missing %s with %s available\n", line.c_str(), missing.c_str(), available.c_str());
	else
		fprintf(stderr,"[%s] - Done\n", line.c_str());
	return missing.size();
}

int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);

	mapping['Y'] = 'a';
	mapping['E'] = 'o';
	mapping['Q'] = 'z';

	mapping['J'] = 'u';
	mapping['P'] = 'r';
	mapping['M'] = 'l';
	mapping['S'] = 'n';
	mapping['L'] = 'g';
	mapping['C'] = 'e';
	mapping['K'] = 'i';
	mapping['D'] = 's';
	mapping['X'] = 'm';
	mapping['V'] = 'p';
	mapping['R'] = 't';
	mapping['N'] = 'b';
	mapping['I'] = 'd';
	mapping['B'] = 'h';
	mapping['T'] = 'w';
	mapping['A'] = 'y';
	mapping['H'] = 'x';
	mapping['W'] = 'f';
	mapping['F'] = 'c';
	mapping['O'] = 'k';
	mapping['U'] = 'j';
	mapping['G'] = 'v';
	mapping['Z'] = 'q';

	/*ejp mysljylc kd kxveddknmc re jsicpdrysi
	rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
	de kr kd eoya kw aej tysr re ujdr lkgc jv

	Case #1: our language is impossible to understand
	Case #2: there are twenty six factorial possibilities
	Case #3: so it is okay if you want to just give up
	*//*
	std::vector<string> lines;
	for (int test=1;test<=nTests;test++) 
	{
		getline(cin,line);
		lines.push_back(line);
	}

	for (int test=1;test<=nTests;test++) 
	{
		line = lines[test-1];

		//capitalize
		for (auto it=line.begin(); it!=line.end(); it++)
		{
			if (*it != ' ')
				*it = (char)*it - 32;
		}

		while (Replace() > 0)
		{
			//char char1, char2;
			//fprintf(stderr, "Enter two chars, first one is the capital. Enter a lowercase first to skip to the next input: ");
			//std::cin >> char1 >> char2;
			//if (char1 >=96)
				break;
			//mapping[char1] = char2;
			//available.erase(available.find(char2));
		}

		string output = line;
		printf("Case #%d: %s\n",test,output.c_str());
	}
}

/*
int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);

		int N;
		std::cin >> N;
		
		std::map<int,int> right;
		int crossings = 0;

		for (int i=0; i<N; i++)
		{
			int a, b;
			std::cin >> a >> b;

			auto insertIter = right.insert(std::map<int,int>::value_type(b,a)).first;
			for (auto it=right.begin(); it != insertIter; it++)
			{
				if (it->second > a)
					crossings++;
			}
			for (auto it=++insertIter; it!=right.end(); it++)
			{
				if (it->second < a)
					crossings++;
			}
		}

		int ans = crossings;
		printf("Case #%d: %d\n",test,ans);
	}
}

/*
int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);

		//R runs, holds up to K people. 
		__int64 R, K, N;
		std::cin >> R >> K >> N;
		
		std::vector<__int64> queue;
		for (int i=0; i<N; i++)
		{
			__int64 rider;
			std::cin >> rider;
			queue.push_back(rider);
		}

		std::map<std::vector<__int64>::iterator, std::pair<__int64,std::vector<__int64>::iterator>> memo;

		__int64 numRides = 0;
		auto iter = queue.begin();
		auto found = memo.begin();
		for (__int64 i=0; i<R; i++)
		{
			if ((found = memo.find(iter)) != memo.end())
			{
				numRides += found->second.first;
				iter = found->second.second;
			}
			else
			{	//not found yet
				__int64 riders = 0;
				int numAdded = 0;
				auto startIter = iter;

				while(1)
				{
					if (numAdded < N && *iter + riders <= K)
					{
						riders += *iter;
						numAdded++;
						iter++;
						if (iter == queue.end())
							iter = queue.begin();
					}
					else
						break;
				}
				memo[startIter] = std::pair<__int64,std::vector<__int64>::iterator>(riders,iter);
				numRides += riders;
			}
		}

		__int64 ans = numRides;
		printf("Case #%d: %lld\n",test,ans);
	}
}

/*
int mod = 100003;
typedef std::pair<int,int> param;
std::map<param, long long> binom;
std::map<param, long long> memo;

long long BinomialCoeff(int n, int k)
{
	if (k==0 && n>=0)
		return 1;
	if (n==0 && k > 0)
		return 0;
	if (binom.find(param(n,k)) != binom.end())
		return binom[param(n,k)];
	long long ret = (BinomialCoeff(n-1,k-1) + BinomialCoeff(n-1,k)) % mod;
	binom[param(n,k)] = ret;
	return ret % mod;
}

long long Solve(int top, int size)
{
	//find all subsets 2..top with size elements that are themselves pure
	//to be pure, element with value size must be in the set
	if (size >= top)
		return 0;
	if (size == top-1)
		return 1;
	if (size == 1)
		return 1;
	if (size == 0)
		return 0;
	if (memo.find(param(top,size)) != memo.end())
		return memo[param(top,size)];

	//otherwise we'll need to calculate
	//could have 2..size, top
	// or some smaller pure subset of 2..size with k elements, size-k-1 C space, top
	long long ret = 0;
	int space = top - size - 1;	//number of possible spots between top and size
	ret += Solve(size, size-1);		//covers the first case
	for (int i=1; i<=space && i<size-1; i++)
	{	
		ret += (Solve(size, size-i-1) * max(BinomialCoeff(space,i), 1)) % mod;
	}

	//save result and return
	memo[param(top,size)] = ret;
	return ret;
}

int main()
{
	int a,b,c,d;

	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);

		int N;
		std::cin >> N;
		
		long long numSubsets = 0;
		for (int i=1; i<N; i++)
		{
			numSubsets += Solve(N, N-i);
		}

		long long ans = numSubsets % mod;
		printf("Case #%d: %d\n",test,ans);
	}
}

/*
struct TrieElement
{
	TrieElement() {m_Children.clear();}

	std::map<std::string,TrieElement *> m_Children;
};

class Trie
{
public:
	Trie() {m_root = new TrieElement;}

	int Insert (std::string i_Path)
	{
		TrieElement * node = m_root;
		int numInserts = 0;

		std::stringstream strstr(i_Path);
		std::string elem;
		while(std::getline(strstr, elem, '/'))
		{
			if (elem == "")
			{
			}
			else if (node->m_Children.count(elem))
			{
				node = (node->m_Children[elem]);
			}
			else
			{
				TrieElement * newElem = new TrieElement;
				node->m_Children[elem] = newElem;
				node = newElem;
				numInserts++;
			}
		}
		return numInserts;
	}

	TrieElement * m_root;
};

int main()
{
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);

		int N,M;
		std::cin >> N >> M;
		Trie trie;
		std::string input;
		for (int i=0; i<N; i++)
		{
			std::cin >> input;
			trie.Insert(input);
		}

		int numInserts = 0;
		for (int i=0; i<M; i++)
		{
			std::cin >> input;
			numInserts += trie.Insert(input);
		}

		int ans = numInserts;
		printf("Case #%d: %d\n",test,ans);
	}
}

/*
int main() 
{
	Util::CMSGTime l_CurrentTime = Util::CMSGTime::GetTheCurrentSTTime();
	Util::CMSGTime l_DstTime = Util::StTimeToDstTime(l_CurrentTime);
	std::wcout << l_CurrentTime.ReadableForm().c_str() << "   " << l_DstTime.ReadableForm().c_str();
}

/*
int main() {
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);

		long int N,K;
		std::cin >> N >> K;
		std::string ans = "ON";
		for (int i=0; i<N && ans == "ON"; i++)
		{
			if (!(K & 1))
				ans = "OFF";
			K = K >> 1;
		}

		printf("Case #%d: %s\n",test,ans.c_str());
	}
}
/*
int main() {
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);

		long int N,K;
		std::cin >> N >> K;
		std::string ans = "ON";
		for (int i=0; i<N && ans == "ON"; i++)
		{
			if (!(K & 1))
				ans = "OFF";
			K = K >> 1;
		}

		printf("Case #%d: %s\n",test,ans.c_str());
	}
}

/*
bool Check(int a,int b)
{
	if (b > a)
	{
		int temp = b;
		b=a; a=temp;
	}
	if (a==b) return false;
	if (b==1) return true;
	if (a-b==1) return false;
	if (a%b==0) return true;
	if (a>=2*b) return true;
	fprintf(stderr, "D(%d,%d): %s\t", a,b,"Unknown");
	return !Check(b,a-b);
}

int main() {
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		int A1,A2,B1,B2;
		//std::cin >> A1 >> A2 >> B1 >> B2;
		A1 = 1; A2 = 20;

		for (int i=A1; i<=A2; i++)
		{
			for (int j=1; j<=i; j++)
			{
				bool ret = Check(i,j);
				fprintf(stderr, "(%d,%d): %s\n", i,j,(ret?"Win":"Loss"));
			}
		}		

		int best = 1;
		printf("Case #%d: %d\n",test,best);
	}
}

/*
int D,I,M,N;
typedef std::pair<int,int> solvecall;
std::map<solvecall, int> memo;

int Solve(int * arr, int numElements, int lastValue)
{
	if (numElements == 0) return 0;
	auto iter = memo.find(solvecall(numElements,lastValue));
	if (iter != memo.end())
		return iter->second;
	int best = Solve(arr, numElements-1, lastValue) + D;

	int move_cost = abs(lastValue - arr[numElements-1]);
	if (M>0)
	{
		if (move_cost < best)
		{
			for (int i=0; i<=255; i++)
			{		
				int prev_cost = Solve(arr, numElements - 1, i);
				int diff = abs(lastValue - i);
				int num_inserts;
				if (diff > 0) num_inserts = (diff - 1) / M;
				else num_inserts = 0;
				int insert_cost = I * num_inserts;			
				int cost = move_cost + prev_cost + insert_cost;
				if (cost < best) best = cost;
			}
		}
	}
	else
	{
		int cost = move_cost + Solve(arr, numElements - 1, lastValue);
		if (cost < best) best = cost;
	}

	memo[solvecall(numElements, lastValue)] = best;
	return best;
}

int main() {
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		std::cin >> D >> I >> M >> N;
		int * a = new int[N];
		memo.clear();

		for (int i=0; i<N; i++)
		{
			std::cin >> a[i];
		}

		int best = std::numeric_limits<int>::max();
		for (int i=0; i<=255; i++)
		{
			int ret = Solve(a, N, i);
			if (ret<best) best = ret;
		}

		printf("Case #%d: %d\n",test,best);
	}
}
/*
int main() {
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) 
	{
		fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		int N, K;
		scanf("%d%d\n",&N,&K);
		fprintf(stderr,"%d %d\n", N, K);

		int ** rows = new int*[N];
		
		for (int i=0; i<N; i++)
		{
			int * row = new int[N];
			memset(row, 0, sizeof(int) * N);
			int insertionPoint = N-1;
			std::string line;

			for (int j=0; j<N; j++)
			{
				char ch;
				scanf("%c", &ch);
				if (ch == 'B' || ch == 'R')
					line.push_back(ch);
			}
			for (int j=line.size()-1;j>=0; j--)
			{
				if (line[j] == 'B')
					row[insertionPoint--] = 1;
				else if (line[j] == 'R')
					row[insertionPoint--] = 2;
			}
			rows[i] = row;

			scanf("\r\n");
		}

		bool Won[2] = {0, 0};

		for (int i=0; i<N; i++)
		{
			for (int j=0; j<N; j++)
			{
				int curr = rows[i][j];
				fprintf(stderr, "%d", curr);

				if (curr == 0)
					continue;
				if (Won[curr-1] == true)
					continue;
				//search right
				if (j+K <= N && Won[curr-1] == false)
				{
					bool isLine = true;
					for (int k=1; k<K; k++)
					{
						if (rows[i][j+k] != curr)
						{
							isLine = false;
							break;
						}
					}
					if (isLine)
					{
						Won[curr-1] = true;
						continue;
					}
				}
				//search down
				if (i+K <= N && Won[curr-1] == false)
				{
					bool isLine = true;
					for (int k=1; k<K; k++)
					{
						if (rows[i+k][j] != curr)
						{
							isLine = false;
							break;
						}
					}
					if (isLine)
					{
						Won[curr-1] = true;
						continue;
					}
				}
				//search diagonally down and to the right
				if (i+K <= N && j+K <= N && Won[curr-1] == false)
				{
					bool isLine = true;
					for (int k=1; k<K; k++)
					{
						if (rows[i+k][j+k] != curr)
						{
							isLine = false;
							break;
						}
					}
					if (isLine)
					{
						Won[curr-1] = true;
						continue;
					}
				}
				//search diagonally up and to the right
				if (i+1-K >= 0 && j+K <= N && Won[curr-1] == false)
				{
					bool isLine = true;
					for (int k=1; k<K; k++)
					{
						if (rows[i-k][j+k] != curr)
						{
							isLine = false;
							break;
						}
					}
					if (isLine)
					{
						Won[curr-1] = true;
						continue;
					}
				}
			}
			fprintf(stderr, "\n");
		}

		std::string output;
		if (Won[0] && Won[1])
			output = "Both";
		else if (Won[0])
			output = "Blue";
		else if (Won[1])
			output = "Red";
		else
			output = "Neither";

		printf("Case #%d: %s\n",test,output.c_str());
	}
}
/*
int main() {
	int nTests;
	scanf("%d\r\n",&nTests);
	for (int test=1;test<=nTests;test++) {
		fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		std::string line;
		std::getline(std::cin, line);
		//char * str;
		//if (0 == gets(str))
		//	fprintf(stderr, "Error");
		
		//std::string line(in);
		std::deque<std::string> words;

		int pos1=0, pos2;
		while ((pos2=line.find(' ', pos1)) != std::string::npos)
		{
			words.push_front(line.substr(pos1, pos2-pos1));
			pos1=pos2+1;
		}
		words.push_front(line.substr(pos1));

		std::string output;
		for (int i=0; i<words.size()-1; i++)
		{
			output += words[i] + " ";
		}
		output += words.back();
		
		printf("Case #%d: %s\n",test,output.c_str());
	}
}
/*
int main() {
	int nTests;
	scanf("%d",&nTests);
	for (int test=1;test<=nTests;test++) {
		fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		int C, numPrices;
		scanf("%d%d",&C,&numPrices);
		
		int newint;
		std::vector<int> l_Prices;
		for (int i=0; i<numPrices; i++)
		{
			scanf("%d",&newint);
			l_Prices.push_back(newint);
		}

		//solve
		bool l_Found = false;
		int i=0,j;
		for (i=0; i<l_Prices.size()-1 && !l_Found; i++)
		{
			if (l_Prices[i]>C) continue;
			for (j=i+1; j<l_Prices.size(); j++)
			{
				if (l_Prices[i]+l_Prices[j] == C)
				{
					l_Found = true;
					break;
				}
			}
			if (l_Found) break;
		}		
		
		printf("Case #%d: %d %d\n",test,i+1,j+1);
	}
}
*/