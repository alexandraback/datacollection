#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <queue>
using namespace std;

int slow(int result, vector<int> t, int i)
{
	if (t.size() == 0)
	{
		return min(result, i);
	}
	int m = t[0];
	for (int j = 1; j < t.size(); ++j)
	{
		m = max(m, t[j]);
	}
	if (i + m / 2 > result)
	{
		return min(result, m + i);
	}
	result = min(result, m + i);
	for (int j = 0; j < t.size(); ++j)
	{
		vector<int> t2 = t;
		t2.push_back(0);
		for (int k = 1; k < t[j]; ++k)
		{
			t2[j] = t[j] - k;
			t2[t.size()] = k;
			result = min(result, slow(result, t2, i + 1));
		}
	}
	vector<int> t2 = t;
	for (int j = t2.size() - 1; j >= 0; --j)
	{
		t2[j] -= 1;
		if (t2[j] == 0)
		{
			swap(t2[j], t2[t2.size() - 1]);
			t2.pop_back();
		}
	}
	result = min(result, slow(result, t2, i + 1));
	return result;
}

void Solve()
{
	int D;
	cin >> D;
	//priority_queue<int> P;
	vector<int> P;
	for (int i = 0; i < D; ++i)
	{
		int temp;
		cin >> temp;
		//P.push(temp);
		P.push_back(temp);
	}
	int result = 1000;
	for (int i = 1; i < 1000; ++i)
	{
		int current_result = i;
		for (int j = 0; j < D; ++j)
		{
			current_result += P[j] / i + (P[j] % i > 0 ? 1 : 0) - 1;
		}
		result = min(current_result, result);
	}
	/*for (int i = 1; i <= result; ++i)
	{
		int top_element = P.top();
		P.pop();
		if (top_element / 2 > 0)
		{
			P.push(top_element / 2);
		}
		P.push(top_element / 2 + top_element % 2);
		int new_result = P.top() + i;
		result = min(new_result, result);
	}*/
	cout << result;
	//cout << " " << slow(result, test, 0);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}
