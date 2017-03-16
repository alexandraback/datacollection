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
int me;
const int R = 1000100;
int others[R];
int n;
int outs[R];
int main(){
	int Z;
	scanf("%d",&Z);
	FORQ(tasks,1,Z){
		scanf("%d%d",&me,&n);
		FOR(i,0,n)
			scanf("%d",&others[i]);
		sort(others,others+n);
		int k=0;
		while(others[k]<me&&k<n){
			me+=others[k];
			k++;
		}
		if(k==n){
			printf("Case #%d: %d\n",tasks,0);
			continue;
		}
		FOR(i,0,k)outs[i]=INT_MAX;
		int moves=0;
		FOR(i,k,n){
			outs[i]=n-i+moves;
			if(me==1){moves++;continue;}
			while(me<=others[i]){
				me+=me-1;
				moves++;
			}
			me+=others[i];
		}
		int wynik=moves;
		FOR(i,0,n)
			wynik=min(wynik,outs[i]);
		printf("Case #%d: %d\n",tasks,wynik);
	}
	return 0;
}

