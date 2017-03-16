#include<bits/stdc++.h>
#define ll unsigned long long int
#define loop(i, a, b)  for(int i=a;i<b;i++)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
	int t;
	ll a, b, k, temp1, temp2;
	ll c;
	cin>>t;
	loop(x, 1, t+1)
	{
		c = 0;
		cin>>a>>b>>k;
		if(a<k || b<k)
            cout<<"Case #"<<x<<": "<<a*b<<endl;
		else
        {
            c += k*max(a, b);
            temp1 = min(a, b);
            temp2 = max(a, b);
            loop(i, k, temp1)
            {
                loop(j, 0, temp2)
                {
                    if((i&j)<k)
                        c++;
                }
            }
            cout<<"Case #"<<x<<": "<<c<<endl;
        }
	}
	return 0;
}
