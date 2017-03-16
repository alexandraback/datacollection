#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000

#define maxn 10000005

typedef long long  LL;
//typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;


char str[maxn];
LL dp[maxn];

int isvowel(char ch)
{

	if(ch=='a' || ch=='i' || ch=='e' || ch=='o' || ch=='u') return 1;
	return 0;
}

int main()
{
	int i,j,k,tests,cs=0,n;

	freopen("E:\\GCJ\\A-small-attempt0.in","r",stdin);
	freopen("E:\\GCJ\\A-small-attempt0.out","w",stdout);

	
	cin>>tests;

	while(tests--)
	{

		scanf("%s%d",str+1,&k);

		LL ans=0;
		int last=0;
		str[0]='a';

		for(i=1;str[i];i++)
		{
			dp[i]=dp[i-1];
			

			if(!isvowel(str[i]) && i-last>=k)
			{
				LL bad= i-k - dp[i-k] ;

				if(isvowel(str[i-k])) dp[i]+=bad;
				dp[i]++;
			}

			if(isvowel(str[i])) last=i;
			//printf("%d %I64d\n",i,dp[i]);
			ans+=dp[i];
		}
		
		if(k==0) ans = (LL)i*(i-1)/2;
		printf("Case #%d: %lld\n",++cs,ans);
	
	}


	return 0;
} 
