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
int a[100][100];
int main() {
	freopen("bb.in","r",stdin);
	freopen("bb.out","w",stdout);
	int numcase;
	cin>>numcase;
	long long n,m;
	for(int ii=1;ii<=numcase;ii++)
	{
		cin>>n>>m;
		printf("Case #%d: ",ii);
		if(m>(1LL<<(n-2))) puts("IMPOSSIBLE");
		else{
			puts("POSSIBLE");
			memset(a,0,sizeof(a));
			for(int i=1;i<n;i++)
				for(int j=i+1;j<n;j++)
					a[i][j]=1;
			a[1][n]=1;
			m--;
			long long t;
			for(long long j=50;j>=0;j--){
				t = 1LL<<(j);
				if(m>=t){
					a[j+2][n]=1;
					m-=t;
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					printf("%d",a[i][j]);
				puts("");
			}
		}
	}
	return 0;
}
