#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
ifstream in("A.in");
ofstream out("A.out");

int ans, sum, s, T;
string st;

int main()
{
	in>>T;
	for (int i=1; i<=T; i++)
	{
		sum = ans = 0;
		in>>s>>st;
		sum = st[0] -48;
		for (int j=1; j<=s; j++)
		{
			if ((st[j] > '0') &&  (sum < j))
			{
				ans+= j-sum;
				sum = j;
			}
			sum += st[j] - 48;
		}
		out<<"Case #"<<i <<": "<<ans<<endl;
	}
}