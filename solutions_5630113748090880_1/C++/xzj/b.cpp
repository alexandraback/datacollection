#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
typedef long long LL;
int a[2600];
int ans[1000];
int main() {
	freopen("bb.in","r",stdin);
	freopen("bb.out","w",stdout);
	int numcase;
	cin>>numcase;
	for(int ii=1;ii<=numcase;ii++)
	{
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=2 * n - 1;i++){
			for(int j=1;j<=n;j++)
			{
				int p;
				scanf("%d",&p);
				a[p]++;
			}
		}
		printf("Case #%d:",ii);
		int t= 0;
		for(int i=1;t<n;i++){
		if(a[i] % 2){
			t++;
			printf(" %d",i);
		}
	}	
		puts("");
	}
	return 0;
}
