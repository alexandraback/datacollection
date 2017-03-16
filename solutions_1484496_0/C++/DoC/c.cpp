#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t= 0; t< T; t++)
	{
		int N;
		cin >> N;
		vector<int> s;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			s.push_back(temp);
		}
		map<long long int, int> f;
		long long int s1,s2; 
		for (int i = 0; i < 1024*1024; i++)
		{
			vector<bool> which;
			int temp = i;
			long long int sum = 0;
			for (int j = 0; j < 20; j++)
			{
				if((temp % 2)==0)
				{
					sum += s[j];
				}
				temp = temp >> 1;
			}
			if(f[sum] != 0)
			{
				s1 = f[sum];
				s2 = i;
				break;
			}
			else
			{
				f[sum] = i;
			}
		}
		cout << "Case #" << t+1 << ":" << endl;
		int temp = s1;
		bool started = false;
		for (int j = 0; j < 20; j++)
		{
			if((temp % 2)==0)
			{
				if(started)
				{
					cout << " ";
				}
				started = true;
				cout << s[j];
			}
			temp = temp >> 1;
		}
		cout << endl;
		
		temp = s2;
		started = false;
		for (int j = 0; j < 20; j++)
		{
			if((temp % 2)==0)
			{
				if(started)
				{
					cout << " ";
				}
				started = true;
				cout << s[j];
			}
			temp = temp >> 1;
		}
		cout << endl;
	}
	
	
}
