#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
double a[1010],b[1010];
bool vis[1010];
int n,t;

int get() {
	int point=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++) {
		int choose=-1;
		for(int j=0;j<n;j++) {
			if(!vis[j] && b[j]>a[i]) {
				choose=j;
				vis[j]=1;
				break;
			}
		}
		if(choose==-1) {
			for(int j=n-1;j>=0;j--) {
				if(!vis[j]) {
					choose=j;
					point++;
					vis[j]=1;
					break;
				}
			}
		}
	}
	return point;
}

int trick() {
	int point=0;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++) {
		int choose=-1;
		for(int j=0;j<n;j++) {
			if(!vis[j] && a[i]>b[j]) {
				choose=j;
				vis[j]=1;
				point++;
				break;
			}
		}
		if(choose==-1) {
			for(int j=n-1;j>=0;j--) {
				if(!vis[j] && a[i]<b[j]) {
					choose=j;
					vis[j]=1;
					break;
				}
			}
		}
	}
	return point;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(int cas=1;cas<=t;cas++) {
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		printf("Case #%d: %d %d\n",cas,trick(),get());

	}
    return 0;
}
