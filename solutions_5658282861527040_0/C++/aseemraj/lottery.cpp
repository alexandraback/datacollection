#include<bits/stdc++.h>
#define long long ll
#define loop(i, a, b)  for(int i=a;i<b;i++)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
	int t, a, b, k, c;
	cin>>t;
	loop(x, 1, t+1)
	{
		c = 0;
		cin>>a>>b>>k;
		loop(i, 0, a)
		{
		    loop(j, 0, b)
		    {
		        if((i&j)<k)
                    c++;
		    }
		}
		cout<<"Case #"<<x<<": "<<c<<endl;
	}
	return 0;
}
