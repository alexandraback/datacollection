#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    int t;

    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
	    int n,s,p,pnos,ps;
		cin>>n>>s>>p;
		pnos = (p - 1) * 2 + p;
		ps = (p - 2) * 2 + p;
		if(ps<p) ps = p;
		int g[105];
        for (int j=0;j<n;j++)
        {
        	cin>>g[j];
        }
        sort(g,g+n,greater<int>());
        int ans = 0;
        for (int j=0;j<n;j++)
        {
        	if(g[j]>=pnos) ans++;
        	else if(g[j]>=ps){
                s--;
                if(s>=0) ans++;
                else break;
        	}
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
