#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using namespace std;

typedef long long LL;
typedef double ld;

int rev(LL a)
{
	int num=0;
	int b[100];
	while(a)
	{
		b[num++]=a%10;
		a/=10;
	}
	int i;
	REP2(i,0,num/2)
		if(b[i]!=b[num-i-1])
			return 0;
	return 1;
}

vector< pair<int,LL> > t;

int Main(int T)
{
	printf("Case #%d: ",T);
	LL A,B;
	cin>>A>>B;
	int i;
	int ans=0;
	REP2(i,0,t.size())
		if(t[i].y<=B && t[i].y>=A)
			++ans;
	cout<<ans<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	int i;
	REP(i,1,10000000)
		if(rev(i) && rev((LL)i*i))
			t.pb(mp(i,(LL)i*i));
	int T;
	scanf("%d",&T);
	REP(i,1,T)
		Main(i);
	return 0;
}
