/*    SHUBHAM SINHA    */



#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <math.h>

#define ll long long int
#define maxN 100000
#define maxVal 100000000
#define minVal -100000000
#define mod 1000000007LL

#define gcd(a,b) __gcd(a,b)

using namespace std;

string a,b;
set<pair<ll,pair<string,string> > > s;
set<pair<ll,pair<string,string> > >::iterator it;
int n;

void compute(int i,ll x,ll y,string f,string g)
{
	if(i==n)
	{
		s.insert(make_pair(abs(x-y),make_pair(f,g)));
		return;
	}
	int l,k;
	if(a[i]=='?')
	{
		if(b[i]=='?')
		{
			for(l=0;l<=9;l++)
				for(k=0;k<=9;k++)
					compute(i+1,x*10+l,y*10+k,f+(char)('0'+l),g+(char)('0'+k));
		}
		else
		{
			for(l=0;l<=9;l++)
				compute(i+1,x*10+l,y*10+(b[i]-'0'),f+(char)('0'+l),g+b[i]);
		}
	}
	else
	{
		if(b[i]=='?')
		{
			for(k=0;k<=9;k++)
				compute(i+1,x*10+(a[i]-'0'),y*10+k,f+a[i],g+(char)('0'+k));
		}
		else
			compute(i+1,x*10+(a[i]-'0'),y*10+(b[i]-'0'),f+a[i],g+b[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef LOCAL_SYS
        freopen("B-small-attempt0.in","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
    	s.clear();
    	cin>>a>>b;
    	n=a.length();
    	compute(0,0,0,"","");
    	it=s.begin();
    	cout<<"Case #"<<i<<": "<<(*it).second.first<<" "<<(*it).second.second<<"\n";
    }
    return 0;
}