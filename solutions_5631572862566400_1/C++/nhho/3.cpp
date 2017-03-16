#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>

#define MAX 100005
#define AMAX 1500
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int t,n,x[1005],d[1005],dd[1005],ans;

void go(int a,int b,int c){
	if(d[a]){
		if(dd[a]==c)ans=max(ans,b-d[a]);
	}else{
		d[a]=b,dd[a]=c;
		go(x[a],b+1,c);
	}
}

void goo(int a){
	dd[a]=INT_MAX;
	dd[x[a]]--;
	d[x[a]]=max(d[x[a]],d[a]+1);
	if(!dd[x[a]])goo(x[a]);
}

int main(){
	scanf("%d",&t);
	F2(a,1,t){
		ans=0;
		scanf("%d",&n);
		F2(b,1,n)scanf("%d",x+b),d[b]=1,dd[b]=0;
		F2(b,1,n)dd[x[b]]++;
		F2(b,1,n)if(!dd[b])goo(b);
		F2(b,1,n)if(x[x[b]]==b&&x[b]>b)ans+=d[b]+d[x[b]];
		F2(b,1,n)d[b]=dd[b]=0;
		F2(b,1,n)if(!d[b])go(b,1,b);
		if(ans>n)while(1){}
		printf("Case #%d: %d\n",a,ans);
	}
	//system("pause");
	return 0;
}
