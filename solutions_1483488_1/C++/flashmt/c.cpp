#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> p[2000200];
int d[2000200];

void calcPair(int n)
{
	int nn=n;
	string s="";
	while (nn) s+=char(nn%10+'0'), nn/=10;
	reverse(s.begin(),s.end());
	
	for (int i=1;i<int(s.size());i++)
	{
		string t=s;
		rotate(t.begin(),t.begin()+i,t.end());
		if (t[0]!='0')
		{
			int m=0;
			for (int j=0;j<int(t.size());j++) m=m*10+t[j]-'0';
			if (n<m && m<=2000000 && d[m]!=n) p[n].push_back(m), d[m]=n;
		}
	}
}

int main()
{
	freopen("clarge.in","r",stdin);
	freopen("clarge.out","w",stdout);
	
	for (int i=1;i<=2000000;i++) calcPair(i);
	
	int test;
	cin >> test;
	for (int it=1;it<=test;it++)
	{
		int a,b,ans=0;
		cin >> a >> b;
		for (int n=a;n<=b;n++)
			for (int i=0;i<int(p[n].size());i++)
				ans+=(p[n][i]<=b);
		cout << "Case #" << it << ": " << ans << endl;
	}
}
