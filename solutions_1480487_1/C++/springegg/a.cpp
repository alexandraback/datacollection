#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#define maxn 1010
using namespace std;

const double eps=1e-8;
pair<int,int> a[maxn];
double ans[maxn];
void solve(){
	int n,i;
	scanf("%d",&n);
	double sum,each,sum2=0;;
	for(i=1;i<=n;++i){
		scanf("%d",&a[i].first);
		a[i].second=i;
		sum2+=a[i].first;
	}
	sum=sum2*2;
	sort(&a[1],&a[n+1]);
	for(i=n;i>0;--i){
		each=sum/i;
		if(a[i].first+eps<each)break;
		ans[a[i].second]=0;
		sum-=a[i].first;
	}
	if(i==1)ans[a[i].second]=1;else 
	for(;i>0;--i){
		ans[a[i].second]=(each-a[i].first)/sum2;
	}
	for(i=1;i<=n;++i)printf(" %.8f",ans[i]*100);
	printf("\n");
}

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;++i){
		printf("Case #%d:",i);
		solve();
	}
	return 0;
}