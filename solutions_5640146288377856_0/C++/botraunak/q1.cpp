#include <iostream>
using namespace std;
int main()
{
	int t,r,c,w,i=1;
	cin>>t;
	while(i<=t)
	{
		cin>>r>>c>>w;
		int moves = 0;
		cout<<"Case #"<<i<<": ";
			if(w==c)
			{
				cout<<w<<endl;
			}
			else
			{
				moves = c/w;
				moves*= r;
				moves += w - 1;
				if(c%w!=0)
					moves+=1;
				cout<<moves<<endl;
			}
		i++;
	}
}

