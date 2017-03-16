#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	freopen("/Volumes/MyPassport/GoogleDrive/ProgramDesign/GoogleCodeJam/2013/Round1/Bullseye.out","w",stdout);
	int T;
	cin>>T;
	for(int c=1;c<=T;c++)
	{
		long long r;
		long long t;
		cin>>r>>t;
		long long con=2*r-3;
		long long p=4;
		int i=1;
		while(t>=0)
		{
			t-=con+p*i;
			i++;
		}
		cout<<"Case #"<<c<<": "<<i-2<<endl;
	}
	return 0;
}