#include <bits/stdc++.h>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ll long long
#define ull unsigned ll 
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);//redirects standard input
    freopen("output.txt","w",stdout);//redirects standard output
    int t,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
    	int r,c,w,ans,sum=0,pos;
    	cin>>r>>c>>w;
    	cout<<"Case #"<<j<<": ";
    	if(c==w)
    	{
    		cout<<w<<"\n";
    		continue;
    	}
		if(w==1)
		{
			cout<<c<<"\n";
			continue;
		}
		ll i,inc=w-1;
		for(i=0;i<c;i+=w)
			if(i!=0)sum++;
 
		pos = i;
		if(pos == c-1)
		{
			cout<<sum+w-1<<"\n";
		}
		else 
			cout<<sum+w<<"\n";	
    }
	return 0;
}