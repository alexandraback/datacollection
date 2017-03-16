/*Author : Vineet Kumar */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int main()
{
	int i,j,n,t;
	si(t);
	printf("Case #1:\n");
	si(t);
	int m,k;
	si(n);
	si(m);
	si(k);
	priority_queue<pair<int,string> > q,e;
	while(t--)
	{
		q = e;
		scan(Q,k);
		int done[10];
		FOR(i,2,9)
		{
			FOR(j,2,9)
			{
				FOR(l,2,9)
				{
					string s="";
					s = (char)(i+48);
					s += (char)(j+48);
					s += (char)(l+48);
					int x,c=0;
					fill(done,0);
					rep(p,13)
					{
						x = 1;
						if(p & 1)
							x *= (s[2]-48);
						if(p & 2)
							x *= (s[1]-48);
						if(p & 4)
							x *= (s[0]-48);
						rep(z,13)
							if(!done[z])
							{
								if(x==Q[z])
								{
									done[z]=1;
									c++;
								}
							}
					}
					q.push(mp(c,s));
					//cout << s << " " << c << endl;
				}
			}
		}
		cout << q.top().second << endl;
	}
	return 0;
}

