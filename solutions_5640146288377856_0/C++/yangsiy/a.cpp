#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("A-small-attempt0.in");
ofstream cout("out.txt");

int r,c,w;

int main()
{
	int t,ans,caseNum=0;
	cin>>t;
	while (t--)
	{
		caseNum++;
		cin>>r>>c>>w;
		ans=(c/w-1)+w;
		if (c%w!=0)
			ans++;
		cout<<"Case #"<<caseNum<<": "<<ans<<endl;
	}
	return 0;
}