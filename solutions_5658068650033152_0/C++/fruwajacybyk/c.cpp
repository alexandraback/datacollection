#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

int plansza[10][10];
int n,m;
int kolor[10][10];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(int x,int y){
	if(kolor[x][y]==1) return false;
	kolor[x][y] = 1;
	if(plansza[x][y]==1) return false;
	if(x==0 || y==0 || x==(n-1) || y==(m-1)) return true;

	FOR(i,0,4){
		if(check(x+dx[i],y+dy[i])) return true;
	}
	return false;
}

void wypisz(){
	FOR(j,0,n){
		FOR(v,0,m) cout<<plansza[j][v];
		cout<<endl;
	}
	int x; cin>>x;
}

int main(){
	int z; scanf("%d",&z);
	int casenr=0;
	while(z--){
		casenr++;
		printf("Case #%d: ",casenr);
		int k;
		scanf("%d%d%d",&n,&m,&k);
		int u = n*m;
		int best = min(k,2*m+2*n);
		FOR(i,0,1<<u){
			int mask = i;
			int ile = 0;
			FOR(j,0,n) FOR(v,0,m) plansza[j][v] =0;

			FOR(j,0,n){
				FOR(v,0,m){
					int l = mask%2;
					mask = mask/2;
					plansza[j][v] = l;
					ile+=l;
				}
			}
			if(ile>best) continue;
			
//			wypisz();

			int dupa = 0;
			FOR(j,0,n) FOR(v,0,m)
				kolor[j][v] = 0;
			
			FOR(j,0,n) FOR(v,0,m){
				if(!check(j,v)) dupa++;
				FOR(x,0,n) FOR(y,0,m) kolor[x][y] = 0;
			}
//			cout<<dupa<<endl;

			if(dupa>=k) best = min(ile,best);
		}
		printf("%d\n",best);

		
		


	}
	return 0;
}
  

