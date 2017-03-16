#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

int t, count0, a, b, k;
long long d[55][2][2][2];
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++count0<<": ";
		cin>>a>>b>>k; --a; --b; --k;
		long long ans=0;
		memset(d, 0, sizeof(d));
		d[31][1][1][1]=1;
		for(int i=31; i>=0; --i)
			for(int ta=0; ta<2; ++ta)
				for(int tb=0; tb<2; ++tb)
					for(int tk=0; tk<2; ++tk)
					{
						if (d[i][ta][tb][tk]==0)
							continue;
						for(int c1=0; c1<2; ++c1)
							for(int c2=0; c2<2; ++c2)
							{
								if (c1==1 && (a&(c1<<i))==0 && (ta==1))
									continue;
								if (c2==1 && (b&(c2<<i))==0 && (tb==1))
									continue;
								if ((c1&c2)==1 && (((c1&c2)<<i)&k)==0 && (tk==1))
									continue;
								int nta=ta, ntb=tb, ntk=tk;
								if ((a&(c1<<i))==0 && (a&(1<<i))!=0)
									nta=0;
								if ((b&(c2<<i))==0 && (b&(1<<i))!=0)
									ntb=0;
								if ( (((c1&c2)<<i)&k)==0 && ((1<<i)&k)!=0)
									ntk=0;
								if (i==0)
									ans+=d[i][ta][tb][tk];
								else d[i-1][nta][ntb][ntk]+=d[i][ta][tb][tk];
							}
					}
		/*for(int ta=0; ta<2; ++ta)
			for(int tb=0; tb<2; ++tb)
				for(int tk=0; tk<2; ++tk)
					ans+=d[0][ta][tb][tk];*/
		cout<<ans<<endl;
	}
	return 0;
}