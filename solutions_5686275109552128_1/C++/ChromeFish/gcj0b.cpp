#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
ifstream in("B.in");
ofstream out("B.out");

int cnt[1010];
int d, T, ans;

int main()
{
	int x, tmp;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		ans = 10000;
		in>>d;
		for (int j=0; j<d; j++)
		{
			in>>x;
			cnt[j] =x;
		}
		for (int j=1000; j>=1; j--)
		{
			tmp = 0;
			for (int k=0; k<d; k++)
				tmp+=(cnt[k]-1)/j;
			ans = min(ans, j+tmp);
		}
		out<<"Case #"<<i <<": "<<ans<<endl;
	}
}
