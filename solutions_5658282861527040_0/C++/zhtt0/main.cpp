#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream f1("B-small-attempt0.in");
	ofstream f2("out.txt");
	int T;
	f1>>T;
	for(int tt=0;tt!=T;++tt)
	{
		f2<<"Case #"<<tt+1<<": ";
		int A,B,K;
		f1>>A>>B>>K;
		int ans=0;
		for(int i=0;i<A;++i)
		{
			for(int j=0;j<B;++j)
			{
				if((i&j)<K)
					ans++;
			}
		}
		f2<<ans<<endl;
	}
	return 1;
}