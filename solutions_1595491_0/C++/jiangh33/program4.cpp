#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 100 + 5;
int scores[MAX];
int n, s, p;

int main()
{
	fstream in("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\data.txt", ios::in), 
		out("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\ans.txt", ios::out);
	int ntest;
	in>>ntest;
	for(int t = 1; t <= ntest; ++ t)
	{
		in>>n>>s>>p;
		out<<"Case #"<<t<<": ";
		int i, cnt, ans = 0;
		for(i = 0; i < n; ++ i)
			in>>scores[i];
		sort(scores, scores + n);
		for(i = n-1, cnt = 0; i >= 0; -- i)
		{
			if(scores[i] >= 3 * p - 2)
				++ ans;
			else if(cnt < s 
				&& scores[i] >= p + 2 * (p > 2 ? p - 2 : 0))
				++ ans, ++ cnt;
			else
				break;
		}
		out<<ans<<endl;
	}
	in.close(), out.close();

	return 0;
}