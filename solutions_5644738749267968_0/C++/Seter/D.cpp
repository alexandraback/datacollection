//Orz Sevenkplus
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#define un using namespace
un std;
#define pb push_back
#define pf pop_front

#define mp make_pair

#define c0 first
#define c1 second
#define sqr(x)((x)*(x))
#define clr(x)memset(x,0,sizeof(x))
#define clr1(x)memset(x,-1,sizeof(x))
#define clr80(x)memset(x,0x80,sizeof(x))
#define clr7F(x)memset(x,0x7F,sizeof(x))

#define ll long long
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define pii pair<int,int>
#define pip pair<int,pii>
#define vi vector<int>
#define vpi vector<pii>
#define pq priority_queue

template<typename T>inline bool chkmin(T&a,T b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T&a,T b){return a<b?a=b,1:0;}
#define modadd(a,b,c)(((a)+(b))%(c))
#define modmul(a,b,c)((int)(((ll)(a)*(b))%(c)))

#define P 1000000007

int n;
double a[1000],b[1000];

int DW(){
	deque<double>X(b,b+n);
	int ans=0;
	for(int i=-1;++i!=n;){
		if(a[i]>X.front()){
			ans++;
			X.pf();
		}else{
			X.pop_back();
		}
	}
	return ans;
}

int W(){
	set<double>X1(b,b+n);
	int a1=0;
	for(int i=n;i--;){
		set<double>::iterator it=X1.lower_bound(a[i]);
		if(it==X1.end())it=X1.begin();
		a1+=*it<a[i];
		X1.erase(it);
	}
	set<double>X2(b,b+n);
	int a2=0;
	for(int i=-1;++i!=n;){
		set<double>::iterator it=X2.lower_bound(a[i]);
		if(it==X2.end())it=X2.begin();
		a2+=*it<a[i];
		X2.erase(it);
	}
	return max(a1,a2);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		for(int i=n;i--;)scanf("%lf",a+i);
		for(int i=n;i--;)scanf("%lf",b+i);
		sort(a,a+n);
		sort(b,b+n);
		printf("Case #%d: %d %d\n",t,DW(),W());
	}
	return 0;
}
