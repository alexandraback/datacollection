#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 15;
char cn[MAX], cm[MAX];
int d[MAX] = {1,10,100,1000,10000,100000,1000000};
int flag[2000000 + 5], partner[MAX];
int n, m;

int main()
{
	fstream in("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\data.txt", ios::in), 
		out("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\ans.txt", ios::out);
	int ntest;
	in>>ntest;
	for(int t = 1; t <= ntest; ++ t)
	{
		in>>n>>m;
		out<<"Case #"<<t<<": ";
		int ans = 0;
		for(int i = n; i < m; ++ i)
		{
			int len = strlen(itoa(i, cn, 10)), cnt = 0;
			for(int j = 0, t = i; j < len - 1; ++ j)
			{
				t= t % 10 * d[len-1] + t / 10;
				if(t <= m && i < t && !flag[t])
					flag[partner[cnt++] = t] = 1;
			}
			ans += cnt;
			for(int j = 0; j < cnt; ++ j)
				flag[partner[j]] = 0;
		}
		out<<ans<<endl;
	}
	in.close(), out.close();

	return 0;
}