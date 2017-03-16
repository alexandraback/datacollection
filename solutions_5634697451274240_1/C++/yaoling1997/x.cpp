#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e4;
char s[maxn];
int T,i,j,ans,x,y,n;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int t= 1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%s",s+1);
		n= strlen(s+1);
		ans= 0;		
		for (i= 2;i<=n;i++)
			ans+= s[i]!=s[i-1];
		if (s[n]=='-') ans++;
		printf("%d\n",ans);
	}return 0;
}
