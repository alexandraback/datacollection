#include<iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int countConst(string s)
{
	int i=0, count;
	while(s[i] != '\0')
	{
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
			count++;
		i++;
	}
	return count;
}

bool isConst(char c)
{
		if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
			return true;
		return false;
}

int main()
{
	int T, c=1;
	ofstream myfile;
	myfile.open ("3A-small.out");
	scanf("%d", &T);
	while(T--)
	{
		string s;
		int l, ans=0;
		cin >> s >> l;
		int i=0;
		int cl=0;
		int ii=0;
		while(s[i] != '\0')
		{
			if(isConst(s[i]))
			{
				cl++;
			}
			else
				cl=0;
			if(cl>=l)
			{
				int n = (i-l+1) - ii;
				int m = (s.length() - i - 1);
				ans += m+n+m*n+ 1;

				//cout << "m = " << m << " n = " << n << " i = " << i << " ii = " << ii << " cl = " << cl << " ans = " << ans << endl;
				ii = i-l+2;
			}
			i++;
		}

		myfile << "Case #"<< c << ": " << ans << endl;
		cout << "Case #"<< c << ": " << ans << endl;
		c++;
	}
	return 0;
}
