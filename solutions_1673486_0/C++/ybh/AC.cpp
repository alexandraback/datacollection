#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXA 5
#define MAXB 110

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		int A,B;
		cin>>A>>B;
		double p[MAXA];
		p[0]=1;
		for (int i=1;i<=A;i++)
		{
			double r;
			cin>>r;
			p[i]=p[i-1]*r;
		}
		double ans=2+B;
		for (int i=1;i<=A;i++)
		{
			double num=p[i]*(A-i+(B-i)+1)+(1-p[i])*(A-i+(B-i)+1+B+1);
			if (num<ans) ans=num;
		}
		cout<<"Case #"<<T<<": ";
		cout<<setiosflags(ios::fixed)<<setprecision(6)<<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
