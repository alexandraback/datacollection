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
    freopen("B-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i,n,T,e,r,j,a,ans,pos,to,k,M,E;
	vector <int> v;
	cin>>T;
	for (i=0; i<T; i++)
	{
		v.clear();
		ans=0;
		cin>>e>>r>>n;
		E=e;
		for (j=0; j<n; j++)
		{
			cin>>a;
			v.push_back(a);
		}
		if (e%r) pos=e/r+1; else pos=e/r;
		for (j=0; j<n; j++)
		{
			pos=min(n-j, pos);
			//cout<<pos<<endl;
			M=v[j]; to=j;
			for (k=j; k<j+pos; k++)
				if (v[k]>M) {M=v[k]; to=k;}
			
			if (j!=to) {ans+=min(e,(to-j)*r)*v[j]; e-=min(e,(to-j)*r);}
			else {ans+=e*v[j]; e=0;}
			//cout<<ans<<endl;
			e+=r;
		}
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
    return 0;
}