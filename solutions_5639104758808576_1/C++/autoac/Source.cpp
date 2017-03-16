#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<string>
using namespace std;
int total, a[1005];

int main()
{
	ifstream file1("A-large.in");
	int T;
	file1 >> T;
	ofstream file2("op.txt");
	for (int t = 1; t <= T; t++)
	{
		string s;
		file1 >> total>>s;
		for (int i = 0; i <= total; i++)
		{
			a[i] = s[i] - '0';
		}
		int cur = 0, ans = 0;
		for (int i = 0; i <= total; i++)
		{
			if (a[i]>0&&cur < i)
			{
				ans += i - cur; cur = i;
			}
			
				cur += a[i];
		
		}
		file2 << "Case #" << t << ": " << ans << endl;
	}

}