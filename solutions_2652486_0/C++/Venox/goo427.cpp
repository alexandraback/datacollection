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

int pri[4]={2,3,5,7};
int cc[10];
int cm[10];
int mut[100];

void updata(int a,int m,int n){
	int co[10]={0,0,0,0,0,0,0,0,0,0};
	
	int sum=0;
	REP(i,4){
		if(pri[i]>m)break;
		co[pri[i]]=0;
		while(a>1&&a%pri[i]==0){
			a/=pri[i];
			co[pri[i]]++;
		}
		sum+=co[pri[i]];
	}
	
	if(cm[5]<co[5])cm[5]=co[5];
	if(cm[7]<co[7])cm[7]=co[7];
	if(cm[3]<co[3])cm[3]=co[3];

	if(co[2]%2==1)cm[2]=1;
	while(co[2]>1){
		co[2]-=2;
		co[4]+=1;
		sum--;
	}
			
	if(cm[4]<co[4])cm[4]=co[4];

}
string judge(int n,int m,int k){
	string ans;
	
	memset(cm,0,10*sizeof(int));
	REP(i,k){
		scanf("%d",mut+i);
		updata(mut[i],m,n);
	}
	int sum=0;
	FORI(i,2,m+1){
		sum+=cm[i];
		REP(j,cm[i]){
		ans.push_back(i+48);
		}

	}
	FORI(i,sum,n){
		ans.push_back(2+48);

	}
	return ans;

	

}

int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		int r,n,m,k;
		scanf("%d%d%d%d",&r,&n,&m,&k);
		
		printf("Case #%d:\n",tt+1);
		REP(rr,r){
			string x=judge(n,m,k);
			cout<<x<<endl;
		}
	}
		



	return 1;



}