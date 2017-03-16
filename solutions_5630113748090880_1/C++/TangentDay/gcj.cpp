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
		int n;
		ifs >> n;
		int a[2501]={};
		REP(i,n*(2*n-1)){
			int x;
			ifs >> x;
			a[x]++;
		}
		VI ans;
		REP(i,2501){
			if (a[i]%2==1)
				ans.push_back(i);
		}
		REP(i,n){
			fprintf(fp,"%d ",ans[i]);
		}
		fprintf(fp,"\n");
	}

	return 0;
}