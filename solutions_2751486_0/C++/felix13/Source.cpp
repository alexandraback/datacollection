//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
using namespace std;

typedef  long long LL;
typedef  unsigned long long ULL;
typedef  long double LD;
typedef  pair<int,int> PII;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i)) 
#define MP make_pair
#define MOD 1000000007
#define INF 1000000000
#define PB push_back

bool voc[1000];
int main()
{
	//ios_base::sync_with_stdio(0);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	voc['a']=1;
	voc['e']=1;
	voc['i']=1;
	voc['o']=1;
	voc['u']=1;
	cin>>t;
	string s; int n;
	FOR(T,0,t)
	{
		LL ans=0;
		cin>>s>>n;
		int last=0;
		int L=s.size();
		int l;
		for(int i=0;i<L;i)
		{
			if(i<L&&!voc[s[i]])
			{
				l=i;
				while(i<L&&!voc[s[i]])++i;
				int ln=i-l;
				FOR(j,0,ln-n+1)
				{
					ans+=1LL*(l-last+1)*(L-n-l+1);
					last=++l;
				}
			}
			else i++;
		}
		cout<<"Case #"<<T+1<<": "<<ans<<'\n';
	}
	return 0;
}