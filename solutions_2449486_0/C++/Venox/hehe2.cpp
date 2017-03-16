#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <algorithm> 
#include <map>
#include <time.h>
#include <set> 
using namespace std;
#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i!=b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())



int judge(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	int *data;
	if(!(data=(int*) malloc(n*m*sizeof(int))))exit(0);

	REP(i,n){
		REP(j,m){
			scanf("%d",data+m*i+j);
		}
	}
	int *r;
	
	if(!(r=(int*) malloc(n*sizeof(int))))exit(0);
	int *c;
	if(!(c=(int*) malloc(m*sizeof(int))))exit(0);
	memset(r,0,n*sizeof(int));
	memset(c,0,m*sizeof(int));
	REP(i,n){
		REP(j,m){
			if(r[i]<data[m*i+j])r[i]=data[m*i+j];
			if(c[j]<data[m*i+j])c[j]=data[m*i+j];
		}
	}
	bool allow=true;
	REP(i,n){
		REP(j,m){
			if(data[m*i+j]<r[i]&&data[m*i+j]<c[j]){
				allow=false;
			}
		}
	}
	free(data);
	free(r);
	free(c);
	return allow?1:0;
}
int main(){
	int t;
	cin>>t;
	REP(tt,t){
		int res=judge();
		printf("Case #%d: ",tt+1);
		switch(res){
		case 0:
			printf("NO\n");
			break;
		case 1:
			printf("YES\n");
			break;
		}
	}



	return 1;
	

	
}