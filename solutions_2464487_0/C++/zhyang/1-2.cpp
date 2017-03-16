#include<iostream>
#include <math.h>
using namespace std;

int main()
{
    freopen("c:\\1.in","r",stdin);
    freopen("c:\\1-out.txt","w",stdout);
    long long T, r, t;
    cin>>T;
    for(long long caseIndex = 1; caseIndex<= T; ++caseIndex)
    {
    	cin>>r>>t;
    	int ans = 0;
    	while(true)
    	{
    		if(r*2+1 > t)
    		    break;
    		t -= (r*2+1);
    		r += 2;
    		ans++;
    	}
    	cout<<"Case #"<<caseIndex<<": "<<ans<<endl;
    }
    return 0;
}
