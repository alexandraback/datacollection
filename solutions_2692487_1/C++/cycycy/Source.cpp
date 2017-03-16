#include <fstream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;


int map[200];

int main()
{
	string input="1.in",output="1.out";
	ifstream infile("A-large (1).in",ios::in);
	ofstream oufile("1.out",ios::out);
	int t;
	long long n,a;
	long long ans,k,an;
	infile>>t;
	for (int loop=1;loop<=t;loop++)
	{
		infile>>a>>n;
		for (int i=0;i<n;i++)
			infile>>map[i];
		if (a==1) 
		{
			oufile<<"Case #"<<loop<<": "<<n<<"\n";
			continue;
		}
		sort(map,map+n);
		ans=10000;
		for (int i=n-1;i>=-1;i--)
		{
			k=a;
			an=n-1-i;
			for (int j=0;j<=i;)
			{
				if (k>map[j])
				{
					k+=map[j];
					j++;
				}
				else
				{
					k=k*2-1;
					an++;
				}
			}
			if (an<ans) ans=an;
		}
		oufile<<"Case #"<<loop<<": "<<ans<<"\n";
	}
}