#include <fstream>
#include <algorithm>
using namespace std;
const double PI=3.1415926;
int T;
int r,t;
int main()
{
	
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	fin>>T;
	for(int c=1;c<=T;c++)
	{
		fin>>r>>t;
		int sum=0;
		int n;
		//s[n]=PI*(2*r+4*n-3)
		for(n=1;;n++)
		{
			sum+=(2*r+4*n-3);
			if(sum>t) break;
		}
		fout<<"Case #"<<c<<": "<<n-1<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}

