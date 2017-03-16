#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;


int main()
{
	int T, A = 0, B = 0;
	cin >> T;

	for(int i = 0; i < T ; ++i)
	{
		cin >> A >> B;
		stringstream ss;
		ss << A;

		string str;
		ss >> str;
		int n = str.length() - 1;
		int a = (int)pow((double)10, (double)n);

		map<int, int> m;
		for(int j = A; j <= B; j++)
		{
			int tmp = j, minvalue = j;
			for(int k = 0; k < n; k++)
			{
				tmp = (tmp%10)*a + (tmp/10);
				if(minvalue > tmp ) minvalue = tmp;
			}
			m[minvalue]++;
		}

		long long ans = 0;

		for(map<int ,int>::iterator it = m.begin(); it != m.end(); it++)
		{
			long long x = it->second;
			ans += (x-1)*x/2;
		}
	   
		cout << "Case #" << i + 1 << ": " << ans << endl;

	}


	return 0;
}