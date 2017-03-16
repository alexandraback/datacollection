#include <iostream>
#include <algorithm>
#include <vector>

int N, cc;
std::vector<int> G;
std::vector<bool> m;
std::vector<std::vector<int>> Gv, Gu, C;

void dfs(int i, bool f=false){
	if(m[i]) return;
	m[i]=true;
	if(f) C.push_back({});
	C[cc].push_back(i);
	for(int s: Gu[i])
		dfs(s);
	if(f) ++cc;
}

int dfsc(int i, int n){
	int j=G[i];
	int x;
	for(x=0; x<n && j!=i; ++x)
		j=G[j];
	if(j==i)
		return 1+x;
	return 0;
}

int max_cycle(std::vector<int> c){
	int M=0;
	for(int i: c)
		M=std::max(M, dfsc(i, c.size()));
	return M;
}

std::pair<int, int> de(std::vector<int> c){
	int n=c.size();
	for(int j=0; j<n; ++j){
		int i=c[j];
		if(Gv[i].empty())
			continue;
		auto it=find(begin(Gv[i]), end(Gv[i]), G[i]);
		if(it!=end(Gv[i]))
			return std::pair<int,int>(G[i], i);
	}
	return {-1, -1};
}

int dfsd(int i, int z){
	int M=0;
	for(int j: Gv[i])
		if(j!=z)
			M=std::max(M, dfsd(j, z));
	return 1+M;
}

int max_de(std::vector<int> c){
	auto DE=de(c);
	//std::cerr << "DE : " << DE.first << " " << DE.second << "\n";
	if(DE.first==-1) return 0;
	int left=dfsd(DE.first, DE.second);
	int right=dfsd(DE.second, DE.first);
	//std::cerr << "MAX_DE : " << left << " " << right << "\n";
	return left+right;
}

int main(){
	int T;
	std::cin >> T;
	for(int t=1; t<=T; ++t){
		std::cout << "Case #" << t << ": ";
		cc=0;
		std::cin >> N;
		G.clear(); Gv.clear(); Gu.clear(); m.clear();
		G.resize(N);
		Gv.resize(N);
		Gu.resize(N);
		C.clear();
		m.resize(N, false);
		for(int i=0; i<N; ++i){
			std::cin >> G[i];
			--G[i];
			Gv[G[i]].push_back(i);
			Gu[G[i]].push_back(i);
			Gu[i].push_back(G[i]);
		}

		for(int i=0; i<N; ++i) dfs(i, true);
		int max_c=0;
		int tt=0;
		m.clear();
		m.resize(N);
		for(auto c: C){
			//std::cerr << "FOR COMPONENT: ";
			//for(int i: c) std::cerr << i;
			//std::cerr << "\n";

			int mde=max_de(c);
			//std::cerr << "mde = " << mde << "\n";
			if(mde==0){
				int mt=max_cycle(c);
				//std::cerr << "mcycle = " << mt << "\n";
				max_c=std::max(max_c, mt);
			} else
				tt+=mde;
		}

		std::cout << std::max(tt, max_c) << '\n';
	}
}
