#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int ANS()
{
	vector<int> v;
	int moto;
	int n;
	cin >> moto >> n;
	v.resize(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int ans = v.size();
	if (v[0]<moto)
		ans = v.size() - 1;
	if (moto == 1)
	{
		return v.size();
	}
	for (int i = 0; i <= v.size(); i++)
	{
		int buf_ans = v.size() - i;
		int cur = moto;
		for (int j = 0; j < i; j++)
		{
			if (cur > v[j])
			{
				cur += v[j];				
			}
			else
			{
				while(cur <= v[j])
				{
					cur += cur - 1;
					buf_ans++;
				}
				cur += v[j];
			}
		}
		ans = min(buf_ans, ans);
	}
	return ans;	
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TEST = 0;
	cin >> TEST;
	for (int tt = 1; tt <= TEST; tt++)
	{
		cout <<	"Case #" << tt <<": " << ANS() << "\n";
	}
}