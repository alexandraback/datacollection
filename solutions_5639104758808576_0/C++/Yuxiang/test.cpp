#include <iostream>
#include <fstream>
using namespace std;

int number(char c){	return int(c - '0'); }

int main(){
	ifstream in("A-small-attempt0.in");
	ofstream out("out");
	int t;
	in >> t;
	for (int x = 1 ; x <= t ; x++)
	{
		int m;
		in >> m;
		string s;
		in >> s;
		int count = number(s[0]);
		int ans = 0;
		for (int i = 1 ; i <= m ; i++)
		{
			int tmp = number(s[i]);
			if (i > count)
			{
				ans += i - count;
				count += i - count;
			}
			count += tmp;
		}
		out << "Case #" << x << ": " << ans << endl;
	}
	in.close();
	out.close();
	return 0;
}
