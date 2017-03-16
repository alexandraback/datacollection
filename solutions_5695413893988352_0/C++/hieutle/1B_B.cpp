#include <bits/stdc++.h>
#include <string>

using namespace std;
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

#pragma comment(linker, "/STACK:16777216")

typedef long long int64;
typedef unsigned long long uint64;

bool can(int num, string s)
{
	ostringstream convert;   // stream used for the conversion
	convert << num;
	string tmp = convert.str();
	
	if (tmp.length() > s.length()) return false;
	int nn = tmp.length();
	for (int i = 1; i <= s.length() - nn; i++)
		tmp = '0' + tmp;


	for (int i = 0; i < tmp.length(); i++)
		if ((s[i] != '?') and (s[i] != tmp[i])) return false;
	return true;
}

int main()
{
	int t;
	cin>>t;

	
	for (int tt = 1; tt <= t; tt++)
	{
		int m = 1000;
	int r1 = 1000, r2 = 1000;
		string c, j;
		cin>>c>>j;
		//cout<<c<<"#"<<j<<"#"<<endl;
		for (int a = 0; a <= 999; a++)
		{
			if (can(a,c))
			{
				for (int b = 0; b <= 999; b++)
					if (can(b,j))
					{
						if (abs(a-b) < m)
						{
							m = abs(a-b);
							r1 = a; r2 = b;
						}
						else if (abs(a-b) <= m)
						{
							if (a < r1)
							{
								r1 = a;
								r2 = b;
							}
							else if (a == r1)
							{
								if (b < r2) r2 = b;
							}
						}
					}	
			}
		}

		//cout<<r1<<" "<<r2<<endl;
		string rr1, rr2;
		ostringstream convert;   // stream used for the conversion
		convert << r1;
		rr1 = convert.str();
		int nn = rr1.length();
		for (int i = 1; i <= c.length() - nn; i++)
			rr1 = '0' + rr1;


		ostringstream convert2;   // stream used for the conversion
		convert2 << r2;
		rr2 = convert2.str();

		nn = rr2.length();
		for (int i = 1; i <= j.length() - nn; i++)
			rr2 = '0' + rr2;

		for (int i = 0; i < rr1.length(); i++)
			if (c[i] == '?') c[i] = rr1[i];
		for (int i = 0; i < rr2.length(); i++)
			if (j[i] == '?') j[i] = rr2[i];	

		
		cout<<"Case #"<<tt<<": "<<c<<" "<<j<<endl;
	}
	return 0;
}