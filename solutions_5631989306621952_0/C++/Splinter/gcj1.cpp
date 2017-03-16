#include <bits/stdc++.h>
using namespace std;
string s;
string now , tmp1 , tmp2;
int main()
{
	//ios::sync_with_stdio(false);
	int test;scanf("%d" , &test);
	for(int tt = 1 ; tt <= test ; tt++)
	{
		cin >> s;
		now = "";
		for(int i = 0 ; i < s.length() ; i++)
		{
			tmp1 = now + s[i];
			tmp2 = s[i] + now;
			if(tmp1 > tmp2)
				now = tmp1;
			else now = tmp2;
		}
		cout << "Case #" << tt << ": ";
		cout << now << endl;
	}
	return 0;
}