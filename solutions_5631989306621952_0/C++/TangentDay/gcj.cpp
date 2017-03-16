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
		string ans;
		ans.push_back(s[0]);
		FOR(i,1,n-1){
			if (s[i]>=ans[0])
				ans = s[i] + ans;
			else
				ans = ans + s[i];
		}
		fprintf(fp,"%s\n",ans.c_str());
	}

	return 0;
}