#include <bits/stdc++.h>
using namespace std;

const int MAXS = 4;
const int MAXREC = 2000000;

struct combination {
	int j,p,s;
}comb[MAXS*MAXS*MAXS];
int J,P,S,K,cptr,rec;

int jp[MAXS][MAXS],ps[MAXS][MAXS],js[MAXS][MAXS];
list<tuple<int,int,int>> maxSol;

int solve(int j,int p,int s,list<tuple<int,int,int>>& sol) {
	if (jp[j][p] >= K || ps[p][s] >= K || js[j][s] >= K) {
		return 0;
	}
	rec++;
	if (rec > MAXREC){
		if (sol.size() > maxSol.size())
			maxSol = sol;
		return 0;
	}
	int maxDays = 1;
	jp[j][p]++;
	ps[p][s]++;
	js[j][s]++;
	sol.push_back(make_tuple(j,p,s));
	for (int i=0; i<cptr; i++) {
		if (comb[i].j == j && 
				comb[i].p == p && 
				comb[i].s == s)
			continue;
		int nj = comb[i].j;
		int np = comb[i].p;
		int ns = comb[i].s;
		maxDays = max(maxDays,1+solve(nj,np,ns,sol));
	}
	if (sol.size() > maxSol.size()) {
		//cout << "maxSol updated with size " << sol.size() << endl;
		maxSol = sol;
	}
	jp[j][p]--;
	ps[p][s]--;
	js[j][s]--;
	sol.pop_back();
	return maxDays;
}

int main() {
	int T; scanf("%d",&T);
	for (int tt=1; tt<=T; tt++) {
		scanf("%d%d%d%d",&J,&P,&S,&K);
		cptr=0;
		maxSol.clear();
		rec = 0;
		for (int j=0; j<J; j++) {
			for (int p=0; p<P; p++) {
				for (int s=0; s<S; s++) {
					comb[cptr++] = {j,p,s};
				}
			}
		}
		memset(jp,0,sizeof(jp));
		memset(ps,0,sizeof(ps));
		memset(js,0,sizeof(js));

		list<tuple<int,int,int>> sol;
		printf("Case #%d: %d\n",tt,solve(0,0,0,sol));
		
		for (tuple<int,int,int> t:maxSol) {
			printf("%d %d %d\n",
				get<0>(t)+1,
				get<1>(t)+1,
				get<2>(t)+1);
		}
	}
	return 0;
}