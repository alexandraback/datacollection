#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("B-small-attempt1.in","r",stdin);
    freopen("op1.txt","w",stdout);
	int t;
	cin>>t;
	int q=0;
	while(t--)
	{
		int a,b,k,ans=0;
		q++;
		cin>>a>>b>>k;
		int i,j;
		for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if((i&j)<k)
                    ans++;
                    //cout<<i<<" "<<j<<"\n";}
            }
        }
        printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
