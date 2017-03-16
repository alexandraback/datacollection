
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
bool check(long long n)
{
	static char buf[100];
	sprintf(buf,"%lld",n);
	int l=strlen(buf);
	for(int i=0;i<l;i++)if(buf[i]!=buf[l-1-i])return 0;
	return 1;
}
long long a[1000];
int cnt=39;
int main()
{
a[1]=1LL;
a[2]=4LL;
a[3]=9LL;
a[4]=121LL;
a[5]=484LL;
a[6]=10201LL;
a[7]=12321LL;
a[8]=14641LL;
a[9]=40804LL;
a[10]=44944LL;
a[11]=1002001LL;
a[12]=1234321LL;
a[13]=4008004LL;
a[14]=100020001LL;
a[15]=102030201LL;
a[16]=104060401LL;
a[17]=121242121LL;
a[18]=123454321LL;
a[19]=125686521LL;
a[20]=400080004LL;
a[21]=404090404LL;
a[22]=10000200001LL;
a[23]=10221412201LL;
a[24]=12102420121LL;
a[25]=12345654321LL;
a[26]=40000800004LL;
a[27]=1000002000001LL;
a[28]=1002003002001LL;
a[29]=1004006004001LL;
a[30]=1020304030201LL;
a[31]=1022325232201LL;
a[32]=1024348434201LL;
a[33]=1210024200121LL;
a[34]=1212225222121LL;
a[35]=1214428244121LL;
a[36]=1232346432321LL;
a[37]=1234567654321LL;
a[38]=4000008000004LL;
a[39]=4004009004004LL;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		long long L,R;
		scanf("%lld %lld",&L,&R);
		int ans=0;
		for(int i=1;i<=cnt;i++)if(a[i]>=L&&a[i]<=R)ans++;
		printf("Case #%d: %d\n",++cas,ans);
	}
}
