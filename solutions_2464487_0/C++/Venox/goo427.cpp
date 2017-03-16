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


static __int64 ffs(__int64 x)
{
    __int64 i;
    for (i = 0; i < 64; i++) {
        if (!x)
            return i;
        x >>= 1;
    }
    return 64;
}
__int64 SquareRoot(__int64 x)
{
    /* Binary search... */
    __int64 hi, lo, a, b;
    if (x < 2)
        return x;
    a = ffs(x);
    // printf("ffs=%d\n", a);

    hi = 1 << a/2;
    lo = 1 << (a-1)/2;

    for(;;) {
        a = (hi - lo + 1) / 2;
        if (a == 0) {
            /* TUNE, but I can't come up w/ test case */
            return lo;
        }
        b = lo + a;
        b *= b;
        // printf("lo=%d hi=%d x=%d a=%d b=%d\n", lo, hi, x, a, b);

        if (b <= x)
            lo += a;
        else
            hi -= a;
    };
}


__int64 s(__int64 r,__int64 n){
	__int64 sum=(n+1)*(r*2+1+n);
	return sum;
}
__int64 judge(){
	__int64 ans;
	__int64 r,t;
	scanf("%I64d%I64d",&r,&t);
	
	long double x=sqrt( (long double)(8*t+(2*r-1)*(2*r-1)));
	__int64 y=x;
	y-=2*r-1;
	y/=4;
	return y;
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