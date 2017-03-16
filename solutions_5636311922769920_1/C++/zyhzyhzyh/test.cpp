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
int T,K,C,S;
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
LL get(int x,int y)
{
	if (y==1) return x;
	return get(min(x+1,K-1),y-1)*K+x;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d:",_);
		read(K);read(C);read(S);
		if (C*S<K) printf(" IMPOSSIBLE\n");
		else
		{
			for(int i=0;i<K;i+=C) printf(" %lld",get(i,C)+1);
			printf("\n");
		}
	}
}

