#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>

#define ll long long
#define endl '\n'
#define INF 1000000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	for(int t = 1 ; t <= T ; t++)
	{
		string s;
		cin >> s;
		int n = s.size();
		deque<char> list;
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(list.empty() || s[i] >= list.front())
				list.push_front(s[i]);
			else
				list.push_back(s[i]);
		}
		
		cout << "Case #" << t << ": ";
		for(int i = 0 ; i < s.size() ; i++)
			cout << list[i];
		cout << endl;
	}
	
	return 0;
}


