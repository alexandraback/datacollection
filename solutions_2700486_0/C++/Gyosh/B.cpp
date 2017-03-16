#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>
#include <set>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 1023123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 
#define PDD pair<double,double>

#define __ puts("")
#define MAX 21
#define MAXY 100
#define SMP(a,b,c) MP(MP(a,b),c)
using namespace std;

int nkasus;
int n,x,y;
set<PII> di;
map<pair<PII,int>, int> peta;
int ada[22];
double a,b;

void rek(int xp, int yp, int t){
	if (t == MAX) return;
	
	//selese?
	if ((yp == 0) || 
	    (((yp == 1) || di.count(MP(xp,yp-2))) && di.count(MP(xp-1,yp-1)) && di.count(MP(xp+1,yp-1)))){
		di.insert(MP(xp,yp));
		
		for (set<PII>::iterator it = di.begin(); it != di.end(); it++){
			if (peta.count(SMP(it->F,it->S,t)) == 0){
				peta[SMP(it->F,it->S,t)] = 0;	
			}
			peta[SMP(it->F,it->S,t)]++;
		}
		ada[t]++;
		
		
		rek(0, MAXY, t+1);
		di.erase(MP(xp,yp));
	}else{
		//turun?
		if ((yp >= 2) && !di.count(MP(xp,yp-2)) && !di.count(MP(xp-1,yp-1)) && !di.count(MP(xp+1,yp-1))){
			rek(xp, yp-2, t);
		}else{
			//kiri?
			if (!di.count(MP(xp-1,yp-1))){
				rek(xp-1, yp-1, t);
			}	
			
			//kanan?
			if (!di.count(MP(xp+1,yp-1))){
				rek(xp+1, yp-1, t);
			}
		}
	}
}

int main(){
	peta.clear();
	di.clear();
	rek(0,MAXY,0);

	scanf("%d", &nkasus);
	REP(jt,nkasus){
		scanf("%d%d%d", &n, &x, &y);
		n--;
		printf("Case #%d: %.9lf\n", jt+1, (double)peta[SMP(x,y,n)]/ada[n]);
	}
	/*
	for (map<pair<PII,int>,int>::iterator it = peta.begin(); it != peta.end(); it++){
		printf("peta[SMP(%d,%d,%d)] = %d\n", (it->F).F.F, (it->F).F.S, (it->F).S, it->S); 
	}
	REP(i,MAX){
		printf("ada[%d] = %d\n",i,ada[i]);
	}
	*/
	return 0;
}
