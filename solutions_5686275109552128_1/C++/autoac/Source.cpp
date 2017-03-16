#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<queue>
using namespace std;
int total, a[1005];
int main()
{
	ifstream file1("B-large.in");
	//ifstream file1("sample.txt");
	int T;
	file1 >> T;
	ofstream file2("oop.txt");
	for (int t = 1; t <= T; t++)
	{
		int total, ans = 100000000,_max=0;
		file1 >> total;
		for (int i = 1; i <= total; i++)
		{
			file1 >> a[i];
			if (a[i] > _max)
				_max = a[i];
		}
		for (int i = 1; i <=_max; i++)
		{
			int res = i;
			for (int m = 1; m <= total; m++)
				if (a[m] > i)
					res += (a[m] - 1) / i;
			if (res < ans)
				ans = res;
		}
		file2 << "Case #" << t << ": "<<ans<<endl ;
	}

}