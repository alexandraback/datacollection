#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <set>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i,n,t,j,left,kol;
	long long int ans;
	vector <int> v;
	string s;
	cin>>t;
	for (i=1; i<=t; i++)
	{
		cin>>s>>n;
		left=0; kol=0; ans=0;
		v.clear();
		v.push_back(0);
		for (j=1; j<=s.size(); j++)
		{
			if (s.at(j-1)!='a' && s.at(j-1)!='e' && s.at(j-1)!='i' && s.at(j-1)!='o' && s.at(j-1)!='u')
				kol++;
			v.push_back(kol);
			if (v[j]>=n && v[j-n]==v[j]-n)
			{
				ans+=1ll*(j-n+1);
				left=j-n+1;
			}
			else ans+=1ll*left;
			//cout<<ans<<" ";
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
    return 0;
}