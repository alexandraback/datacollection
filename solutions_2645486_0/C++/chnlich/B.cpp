/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int T,E,R,n,a[10010],lis[10010],o;
llint ans;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d%d",&E,&R,&n);
		if (R>E) R=E;
		for(int i=0;i<n;i++) scanf("%d",a+i);
		int now=E,head=1,tail=0,ste=E;
		ans=0;
		for(int i=0;i<n;i++)
		{
			int tmp;
			if (head<=tail) tmp=lis[head]; else tmp=i-1;
			while(head<=tail&&a[i]>a[lis[tail]]) tail--;
			if (i>0&&head>tail) ste+=(i-tmp)*R;
			lis[++tail]=i;
			if (i+1<n) now+=R;
			while (now>E)
			{
				o=min(ste,now-E);
				ans+=1ll*a[lis[head]]*o;
				ste-=o; now-=o;
				if (!ste)
				{
					if (head==tail)
						ste=0;
					else
						ste=(lis[head+1]-lis[head])*R;
					head++;
				}
			}
		}
		while(head<=tail)
		{
			o=min(ste,now);
			ans+=1ll*a[lis[head]]*o;
			ste-=o; now-=o;
			if (!ste)
			{
				ste=(lis[head+1]-lis[head])*R;
				head++;
			}
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	
	return 0;
}
