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
int T,n;
string S[20][2];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin>>S[i][0]>>S[i][1];
		}
		int Max=0;
		for(int i=0;i<(1<<n);i++)
		{
			set<string> A[2];A[0].clear();A[1].clear();
			int cnt=0;
			for(int j=0;j<n;j++)
				if ((i>>j)&1)
				{
					for(int k=0;k<2;k++) A[k].insert(S[j][k]);
				}
			bool flag=1;
			for(int j=0;j<n;j++)
				if (((i>>j)&1)==0)
				{
					cnt++;
					for(int k=0;k<2;k++)
						if (A[k].find(S[j][k])==A[k].end())
						{
							flag=0;break;
						}

				}
			if (flag) Max=max(Max,cnt);
		}
		printf("%d\n",Max);
		cerr << Max << endl;
	}
}


