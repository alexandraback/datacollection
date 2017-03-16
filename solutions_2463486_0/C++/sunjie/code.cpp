#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100010;
long long h[40]={0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--)
	{
		long long a,b;
		scanf("%I64d%I64d",&a,&b);
		int i;
		for(i=0;i<40;i++)
		{
			if(h[i]>a-1)
			{
				break;
			}
		}
		int s1=i-1;
		for(i=0;i<40;i++)
		{
			if(h[i]>b)
			{
				break;
			}
		}
		int s2=i-1;
		printf("Case #%d: %d\n",++cas,s2-s1);
	}
	fclose(stdin);
	fclose(stdout);



    return 0;
}
