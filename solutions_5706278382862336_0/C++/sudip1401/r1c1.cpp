#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int t,tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		string s;
		cin>>s;
		stringstream ss;
		ss << s;
		int p,q;
		char c;
		ss >> p >> c >> q;
		ss.clear();
		//cout<<p<<" "<<q<<endl;

		int no = 1;
		for(int i=1;i<q;i=i*2)
			if(q == 2*i) { no = 0; break; }

		if(no == 0)
		{
			int gen = 0;
			while(1)
			{
				int q1 = q/2;
				int p1 = p - q1;
				gen++;
				if(p1 < 0)
				{
					q = q1;
				}
				else break;	
			}
			cout<<"Case #"<<t<<": "<<gen<<endl;
		}
		else
			cout<<"Case #"<<t<<": impossible"<<endl;

	}
	return 0;
}