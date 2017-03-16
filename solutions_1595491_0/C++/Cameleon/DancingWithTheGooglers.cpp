#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream ofvar;
	ofvar.open("output.out");
	int T, N, S, p, in, out, rest, num;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		out=0;
		cin>>N>>S>>p;
		for(int j=0;j<N;j++)
		{
			cin>>in;
			rest=in%3;
			num=in/3;
			if(num>=p)
			{
				out++;
				continue;
			}
			if(rest>0)
			{
				if(num+1>=p)
				{
					out++;
					continue;
				}
				else if(rest==2&&S>0&&num+2>=p)
				{
					out++;
					S--;
				//	cout<<S<<endl;
					continue;
				}
			}
			if(rest==0&&S>0&&num+1>=p&&in>0)
			{
				out++;
				S--;
				continue;
			}
		}
		ofvar<<"Case #"<<i+1<<": "<<out<<endl;
	}
	return 0;
}
