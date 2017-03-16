#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
char s[1010];
int main()
{
	int T, Smax,Cas = 1,ans;
	int i, j,t;
	ifstream in("A-small-attempt1.in");
	ofstream out("out.txt");
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	in >> T;
	while (T--)
	{
		in >> Smax;
		in >> s;
		ans = 0; t = 0;
		for (i = 0; s[i]; i++)
		{
			if (t >= i)
			{
				t += s[i] - '0';
			}
			else
			{
				ans += i - t;
				t += i-t + s[i] - '0';
			}
		}
		out << "Case #" << Cas++ << ": " << ans << endl;
	}

}