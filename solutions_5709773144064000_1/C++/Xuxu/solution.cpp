#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
	ifstream fin("B-large.in");
	ofstream fout("Cookie Clicker Alpha.out");
	int n;
	fin>>n;
	for (int i=0;i<n;++i)
	{
		double c,f,x;
		double k = 2;
		double ans = 0;
		fin>>c>>f>>x;
		while ((k+f)*(x-c) > k * x)
		{
			ans += c/k;
			k+=f;
		}
		ans += x/k;
		fout<<setiosflags(ios::fixed)<<setprecision(7)<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}