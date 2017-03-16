#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector <long long> j;
long long SUM;

bool valid(int l, long long p)
{
	long long left = SUM - p;
	for(int i = 0; i < j.size(); i ++)
	{
		if(i != l)
		{
			if(j[i] < j[l] + p)
				left -= j[l] - j[i] + p;
		}
	}
	if(left < j.size() - 1)
		return true;
	return false;
}

int main()
{
	int T;
	cin >> T;
	for(int z = 1; z <= T; z ++)
	{
		cout << "Case #" << z << ":";
		int n;
		SUM = 0;
		cin >> n;
		for(int i = 0; i < n; i ++)
		{
			long long temp;
			cin >> temp;
			j.push_back(temp * 10000000);
			SUM += j[i];
		}
		for(int i = 0; i < n; i ++)
		{
			long long low = 0, high = SUM, ans;
			while(1)
			{
				long long mid = (low + high) / 2;
				bool t = valid(i, mid), tnext = valid(i, mid + 1);
				//cout << "Ind: " << i << "Mid: " << mid << "t: " << t << "tnext: " << tnext << "\n";
				if(t == false && tnext == true)
				{
					ans = mid + 1;
					break;
				}
				else if(t == true && tnext == false)
				{
					ans = mid;
					break;
				}
				else if(t == false)
					low = mid;
				else if(mid == 0)
				{
					ans = 0;
					break;
				}
				else
					high = mid;
			}
			printf(" %.6Lf", ((long double) 100LL * ans) / ((long double) SUM));
		}
		cout << "\n";
		j.clear();
	}
}
