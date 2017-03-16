#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

#define for0(i, N) for(int i = 0; i < (N); i++)
#define pb push_back
#define vec1(type) vector<type>
#define vec2(type) vector< vec1(type) >
#define UL unsigned long long
using namespace std;


int main()
{
	int kases;
	cin >> kases;	
	for0(kase, kases)
	{
		int N;
		cin >> N;
		vector<UL> num (N, 0);		
		for0(n, N)
		{			
			int t;
			cin >> t;
			num[n] = t;			
		}		
		map<UL, vector<bool> > m;
		map<UL, vector<bool> > m2;
		bool yep = false;
		vector<bool> ans;
		vector<bool> ans2;
		
		for0(i, N)
		{
			m = m2;
			map<UL, vector<bool> >::iterator it;
			it = m.find(num[i]);
			if (it != m.end())
			{
				yep = true;
				ans = it->second;
				vector<bool> temp(N, false);
				temp[i] = true;
				ans2= temp;
				break;
			}
			map<UL, vector<bool> >::iterator it2 = m.begin();
			for(; it2 != m.end(); it2++)
			{				
				vector<bool> temp = it2->second;
				int t2 = it2->first;
				it = m.find(t2 + num[i]);
				if (it != m.end())
				{
					yep = true;
					ans = it->second;
					it2->second[i] = true;
					ans2 = it2->second;
					break;
				}
				temp[i] = true;
				m2.insert(pair<UL, vector<bool> >(num[i] + it2->first, temp));
			}
			
			if (yep)
				break;	
			vector<bool> t3 (N, false);
			t3[i] = true;
			m2.insert(pair<UL, vector<bool> >(num[i], t3));			
		}
		cout << "Case #" << kase + 1 << ":" << endl;
		if (yep)
		{
			
			for0(i, N)
			{
				if (ans[i])
					cout << num[i] << " ";
			}
			cout << endl;
			for0(i, N)
			{
				if (ans2[i])
					cout << num[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}
		
	}
}
