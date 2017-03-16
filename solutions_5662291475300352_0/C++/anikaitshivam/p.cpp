#include<bits/stdc++.h>
#define ll long long int
#define PI 3.14159265
#define r 1.0
using namespace std;

int main()
{
    int T;cin>>T;for(int t=0;t<T;t++)
    {
	int N;cin>>N;
	int s1, s2;
	int t1, t2;
	int ans;
	if(N==1)
	{
	    cin>>s1>>N>>t1;
	    s2=s1;
	    t2=t1+1;
	    double sp1=2*PI*r/t1;
	    double sp2=2*PI*r/t2;

	    if(N==1)
		ans=0;
	    else
	    {
		double ds=2*PI*r*(360-s2)/360;
		double ts=ds/sp2;

		double df=ts*sp1;
		if(df>ds+2*PI*r)
		    ans=1;
		else
		    ans=0;
	    }
	}
	else
	{
	    cin>>s1>>N>>t1;
	    cin>>s2>>N>>t2;
	    N=2;

	    if(t2<t1)
	    {
		swap(s1,s2);
		swap(t1,t2);
	    }
	    double sp1=2*PI*r/t1;
	    double sp2=2*PI*r/t2;
	    double ds=2*PI*r*(360-s2)/360;
	    double dsn=2*PI*r*(360-s1)/360;
	    double ts=ds/sp2;

	    double df=ts*sp1;
            if(df>dsn+2*PI*r)
		ans=1;
	    else
		ans=0;
	}
	cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
    return 0;
}
