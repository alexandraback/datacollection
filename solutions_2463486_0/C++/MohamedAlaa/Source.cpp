#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <stack>
#include <sstream>
#include <math.h>
using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("Text.txt","a",stdout);
	int tc;
	cin >> tc;
	for ( int i = 1 ; i <= tc ; i++ )
	{
		long long a,b;
		cin >> a >> b;
		int sum=0;
		for ( int p = a ; p <= b ; p++ )
		{
			string res;
			stringstream convert;
			convert<<p;
			res = convert.str();
			if ( res == string ( res.rbegin() , res.rend() ) )
			{
				float k=sqrt(p);
				int l=sqrt(p);
				if ( l == k )
				{
					string h;
					stringstream co;
					co<<l;
					h = co.str();
					if ( h == string ( h.rbegin() , h.rend() ) )
					{
						sum++;
					}
				}
			}
		}

		cout<<"Case #"<<i<<": ";
		cout<<sum<<endl;
	}
	return 0;
}