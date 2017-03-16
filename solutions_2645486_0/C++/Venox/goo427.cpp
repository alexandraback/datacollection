#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <math.h> 
#include <algorithm> 
#include <stdio.h> 
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
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())


struct hashnode{
	__int64 key;
	__int64 value;
	hashnode* next;
};
struct hashl{
	hashnode** poi;
	hashnode* datas;
	__int64 n;
	__int64 m;
	__int64 c;
	void init(__int64 nn,__int64 m);
	bool insert(__int64 k,__int64 v);
	__int64 get(__int64 k);
	void clear();
	void release();

};
void hashl::init(__int64 nn,__int64 mm){
	n=nn;m=mm;c=0;
	if(!(datas=(hashnode* )malloc(n*sizeof(hashnode))))exit(0);
	if(!(poi=(hashnode** )malloc(m*sizeof(hashnode*))))exit(0);
	memset(datas,0,n*sizeof(hashnode));
	memset(poi,NULL,m*sizeof(hashnode*));


}

bool hashl::insert(__int64 k,__int64 v){
	hashnode* p=poi[k%m];
	hashnode** f=poi+k%m;
	while(p!=NULL){
		if(p->key==k){
			//p->value=v;
			return false;
		}
		f=&(p->next);
		p=p->next;

	}
	if(p==NULL){
		p=*f=datas+c++;
		p->key=k;
		p->value=v;
		p->next=NULL;
	}
	return true;
}

__int64 hashl::get(__int64 k){
	
	hashnode* p=poi[k%m];
	while(p!=NULL){
		if(p->key==k){
			return p->value;
		}
		p=p->next;

	}
	return -1;
}
void hashl::clear(){
	c=0;
	memset(datas,0,sizeof(datas));
	memset(poi,NULL,m*sizeof(hashnode*));
}
void hashl::release(){
	c=0;
	free(datas);
	free(poi);
}


int data[100][100];
int mut[100];
int judge(){
	int ans;
	int e,r,n;
	scanf("%d%d%d",&e,&r,&n);
	REP(i,n){
		scanf("%d",mut+i);
	}
	memset(data,0,10000*sizeof(int));
	REP(j,e+1){
		data[0][j]=mut[0]*(e-j);
	}
	FORI(i,1,n){
		REP(j,e+1){
			int max=0;
			REP(u,e+1-j){
				if(u+j-r>=0){
					if(max<data[i-1][u+j-r]+mut[i]*(u))max=data[i-1][u+j-r]+mut[i]*(u);
				}

			}
			data[i][j]=max;
		}
	}

	return data[n-1][0];

	

}

int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		__int64 x=judge();
		printf("Case #%d: %I64d\n",tt+1,x);
	}
		



	return 1;



}