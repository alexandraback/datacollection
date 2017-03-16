#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;
void test(int num)
{
	int n;
	cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	map<int,int> sums;
	bool possible = false;
	int id1, id2;
	for(int i = 0; i < (2 << n); i++)
	{
		int csum = 0;
		for(int j = 0; j < n; j++)
			if(i & (1 << j))csum += s[j];
		if(sums.find(csum) != sums.end())
		{
			id1 = sums[csum];
			id2 = i;
			possible = true;
			break;
		}
		sums[csum] = i;
	}
	cout << "Case #" << num << ":";
	if(!possible)
		cout << "Impossible\n";
	else
	{
		cout << "\n";
		bool first = true;
		for(int i = 0; i < n; i++)
			if(id1 & (1 << i))
			{
				if(first) first = false;
				else cout << " ";
				cout << s[i];
			}
		cout << "\n";
		first = true;
		for(int i = 0; i < n; i++)
			if(id2 & (1 << i))
			{
				if(first) first = false;
				else cout << " ";
				cout << s[i];
			}
		cout << "\n";
	}
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
		test(i);
	return 0;
}
