#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)
#define pi M_PI

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

int n;
VI e;
VVI e2;
int d[50][50];

int dfs(int now, int past){
	int res = -1;
	REP(i,e2[now].size()){
		int next = e2[now][i];
		if (next == past) continue;
		res = max(res,dfs(next,now));
	}
	if (res>=0)
		return res+1;
	else
		return 0;

}

int main(void) {
	ifstream ifs("input.txt");
	FILE *fp;
	fp = fopen("out.txt","w");
	int t;
	ifs >> t;
	REP(cas,t){		
		fprintf(fp,"Case #%d: ",cas+1);

		string s;
		ifs >> s;
		int n = s.length();
		map<char,int> M;
		REP(i,n){
			M[s[i]]++;
		}
		int ans[10]={};
		ans[0] = M['Z'];
		ans[2] = M['W'];
		ans[6] = M['X'];
		ans[7] = M['S']-ans[6];
		ans[5] = M['V']-ans[7];
		ans[4] = M['F']-ans[5];
		ans[8] = M['G'];
		ans[3] = M['H']-ans[8];
		ans[1] = M['O']-ans[0]-ans[2]-ans[4];
		ans[9] = M['I']-ans[5]-ans[6]-ans[8];

		REP(i,10){
			REP(j,ans[i]) fprintf(fp,"%d",i);
		}

		fprintf(fp,"\n");
	}

	return 0;
}