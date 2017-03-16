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

int T,ans;
llint t,r;

const double pi=acos(-1);

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		cin>>r>>t;
		cout<<"Case #"<<tt<<": ";
		/*
		int ans=0;
		for(;;)
		{
			if (t>=2*r+1)
			{
				t-=2*r+1;
				ans++;
			} else break;
			r+=2;
		}
		*/
		llint L,R,tmp,ans;
		for(L=1,R=2000000000;L<=R;)
		{
			tmp=(L+R)>>1;
			if (2ll*r+2ll*tmp-1ll<=t/tmp) ans=tmp,L=tmp+1; else R=tmp-1;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
