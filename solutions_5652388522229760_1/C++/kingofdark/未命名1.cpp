#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
ifstream cin ("A-large.in");

bool v[10];
int ans;

void Judge(long long x)
{
	int k;
	while(x)
	{
		k=x%10;
		if(!v[k])
		{
			v[k]=1;
			ans++;
		}
		x=x/10;
	}

}

int main()
{
	freopen("1.out","w",stdout);
	int T;
	long long n;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		if(n==0)
		{
			printf("Case #%d: INSOMNIA\n",i);
			continue;
		}	
		memset(v,0,sizeof(v));
		ans=0;
		for(int j=1;;j++)
		{
			Judge(n*j);
			if(ans==10)
			{
				printf("Case #%d: %lld\n",i,n*j);
				break;
			}
		}
	}
	
	return 0;
}

