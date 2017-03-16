#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstring>
#define FOR(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define FORQ(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define FORD(x,y,z) for(int (x)=(y);(x)>(z);(x)--)
#define FORDQ(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define REP(x,z) for(int (x)=1;(x)<=(z);(x)++)
#define UNIQUE(x) sort(ALL((x))); (x).resize(unique(ALL((x)))-(x).begin());
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define PII pair<int,int>
#define PACKS(Z,IdzieSobieBladWielbladMaWrotkiNaKopytachJESTNIENORMALNY) int Z;scanf("%d",&Z);FORQ(IdzieSobieBladWielbladMaWrotkiNaKoptyachJESTNIENORMALNY,1,Z)
using namespace std;
int in[111][111];
int main(){
	int Z;
	scanf("%d",&Z);
	FORQ(cases,1,Z){
		int n,m;
		scanf("%d%d",&n,&m);
		vector< pair< int , PII > > fields;
		FOR(i,0,n)FOR(j,0,m){scanf("%d",&in[i][j]);fields.PB(MP(in[i][j],MP(i,j)));}
		sort(ALL(fields));
		bool YES=true;
		FOR(i,0,fields.size()){
			bool fail=false;
			FOR(x,0,n){
				if(in[x][fields[i].S.S]>fields[i].F)
					fail=true;
			}
			if(fail){
				fail=false;
				FOR(x,0,m)
					if(in[fields[i].S.F][x]>fields[i].F)
						fail=true;
			}
			if(fail){
				YES=false;
				break;
			}
		}
		printf("Case #%d: %s\n",cases,YES?"YES":"NO");
	}
	return 0;
}

