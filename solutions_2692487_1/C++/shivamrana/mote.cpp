/* shivamrana */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
#define f0r(i,n) for(int i=0;i<n;i++)
#define fOr(i,n) for(int i=1;i<=n;i++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%I64d",a)
#define n(l) cout<<endl
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;
int main()
{
    freopen("mote.in","r",stdin);
    freopen("mote1.out","w",stdout);
    int t;
si(t);
	for (int cs = 0; cs < t; cs++)
	{
		ll beg;
		int n;
		cin>>beg;
		si(n);
		int ans=n;
		vector<int> mot,val;
		val = vector<int>(n);
		for(int j=0;j<n;j++)
		{
			int t;
			cin>>t;
			mot.push_back(t);
		}
		sort(mot.begin(),mot.end());
		if(beg!=1)
		{
		int c=0;
		for(int j=0;j<n;j++)
		{
			while(beg<=mot[j])
			{
				beg=(2*beg)-1;
				c++;
			}
			val[j]=c;
			beg=beg+mot[j];
		}
		for(int j=0;j<n;j++)
		{
			if((val[j]+n-j-1)<ans)
				ans=(val[j]+n-j-1);
		}
		}
		cout<<"Case #"<<cs+1<<": "<<ans<<endl;
	}
	//system("pause");
	return 0;
}
