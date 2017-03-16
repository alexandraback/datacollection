#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n;
map<int, vector <int> > mp;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);        
	int test_count;
	cin >> test_count;
	for (int test = 1 ; test <= test_count; test++)
	{
		cin >> n;
		vector < int >  v;
		mp.clear();
		for (int i = 0 ; i < n ; i++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		for (int i = 1 ; i < (1 << v.size()); i++)
		{
			int sum = 0;
			for (int j = 0 ; j < v.size(); j++)
				if ((1 << j) & i)
					sum += v[j];
			mp[sum].push_back(i);
		}
		cout << "Case #" << test << ':' << '\n';
		bool flag = false;
		for (map<int, vector <int> >::iterator it = mp.begin(); it != mp.end() ; it++)
		{
			vector < int > vp = (*it).second;
			if (vp.size() < 2)
				continue;
			int temp = vp[0] ^ vp[1];
			int first = temp & vp[0];
			int second = temp & vp[1];
			for (int j = 0 ; j < n; j++)
			{
				if ((1 << j) & first)
					cout << v[j] << ' ';

			}
			cout << '\n';
			for (int j = 0 ; j < n; j++)
				if ((1 << j) & second)
					cout << v[j] << ' ';
			flag = true;
			break;
		}
		if(flag == false)
			cout << "Impossible";
		cout << '\n';
	}

    return 0;
}