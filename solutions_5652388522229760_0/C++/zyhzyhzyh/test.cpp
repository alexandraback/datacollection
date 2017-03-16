#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int T,a[10],cnt,n;
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
void Des(int x)
{
	while (x)
	{
		int t=x%10;
		if (a[t]==0)
		{
			a[t]=1;cnt++;
		}
		x/=10;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		read(n);
		memset(a,0,sizeof(a));cnt=0;
		if (n==0) printf("INSOMNIA\n");
		else
		{
			int m=n;
			for(;;m+=n)
			{
				Des(m);
				if (cnt==10)
				{
					printf("%d\n",m);
					break;
				}
			}
		}
	}
}

