#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
#pragma comment(linker, "/STACK:167772160")

#define sz(x) int((x).size())
const int inf = 1000000000;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
typedef long long Int;

int a[2001];
map<int,vector<int>> q;


void pr(int mask,int n)
{
	bool ok=false;
	FOR(i,0,n-1)
		if(mask&(1<<i))
		{
			if(!ok){cout<<a[i];ok=true;}else
			cout<<" "<<a[i];
		}
	cout<<endl;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tes;
	cin>>tes;
	FOR(o,1,tes)
	{
		int n;
		cin>>n;
		FOR(i,0,n-1)cin>>a[i];
		cout<<"Case #"<<o<<":"<<endl;

		q.clear();
		
		FOR(i,0,(1<<n)-1)
		{
			int s;
			s=0;
			FOR(j,0,n-1)
				if(i&(1<<j))
					s+=a[j];
			q[s].pb(i);

			if(sz(q[s])==2)
			{
				int id=q[s][0];
				pr(id,n);
				id=q[s][1];
				pr(id,n);
				break;
			}
		}
	}
	
	return 0;
}