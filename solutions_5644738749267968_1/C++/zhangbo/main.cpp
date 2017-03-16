#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <functional>

using namespace std;

void calc()
{
	static int caseno = 0;
	caseno++;

	int n;
	cin >> n;
	vector<double> v1(n, 0.0);
	vector<double> v2(n, 0.0);
	deque<double> d1, d2;
	unordered_map<double, bool> v2name;
	vector<double> v(n*2, 0.0);
	vector<bool> naomi(2 * n, false);	

	for (int i = 0; i < n; i++) cin >> v1[i];
	for (int i = 0; i < n; i++) cin >> v2[i];
	sort(v1.begin(), v1.end(), greater<double>());
	sort(v2.begin(), v2.end(), greater<double>());

	for (int i = 0; i < n; i++) d1.push_back(v1[i]);
	for (int i = 0; i < n; i++) d2.push_back(v2[i]);

	int gt = 0;
	int z = 0;
	while (!d1.empty())
	{
		if (d2.empty() || d1.front() > d2.front())
		{
			d1.pop_front();
			if (gt == 0)
				z++;
			else
				gt--;
		}
		else
		{
			d2.pop_front();
			gt++;
		}
	}
	while (!d2.empty()) d2.pop_front();

	for (int i = 0; i < n; i++) d1.push_back(v1[i]);
	for (int i = 0; i < n; i++) d2.push_back(v2[i]);

	int y = 0;

	while (!d1.empty())
	{
		if (d1.front() > d2.front())
		{
			d1.pop_front();
			d2.pop_front();
			y++;
		}
		else
		{
			d1.pop_back();
			d2.pop_front();
		}
	}


	cout << "Case #" << caseno << ": " << y << " " << z;
	cout << endl;
}

int main()
{
	int k = 1;
	cin >> k;
	while (k-- > 0)
	{
		calc();
	}

	return 0;
}

