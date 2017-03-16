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
int T,f[110][2];
char s[110],t[110];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%s",s);
		int l=strlen(s);
		f[0][0]=s[0]!='-';
		f[0][1]=s[0]!='+';
		for(int i=1;i<l;i++)
		{
			if (s[i]=='+')
			{
				f[i][0]=f[i-1][1]+1;
				f[i][1]=f[i-1][1];
			}
			else
			{
				f[i][0]=f[i-1][0];
				f[i][1]=f[i-1][0]+1;
			}
		}
		printf("%d\n",f[l-1][1]);
	}
}

