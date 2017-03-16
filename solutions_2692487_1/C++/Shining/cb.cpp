#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define ps system("pause")
#define message printf("*\n")
#define pb push_back
#define X first
#define Y second
#define PII pair<int,int>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)

typedef long long ll;

using namespace std;

int a[1000100];
int T,n,cur,cv,ans;

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	rep(vv,1,T){
		scanf("%d%d",&cur,&n);
		rep(i,1,n)	scanf("%d",&a[i]);		
		if	(cur==1){
			printf("Case #%d: %d\n",vv,n);
			continue;
		}
		sort(a+1,a+n+1);
		cv=0;ans=999999999;
		rep(i,1,n){
			ans=min(ans,cv+n-i+1);
			while	(cur<=a[i]){
				cur=cur*2-1;
				cv++;
			}
			cur+=a[i];
		}
		ans=min(ans,cv);
		printf("Case #%d: %d\n",vv,ans);
	}
}


