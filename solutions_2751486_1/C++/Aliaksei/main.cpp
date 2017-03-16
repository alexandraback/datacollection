#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

int bins(vector<int> &v, int val)
{
	int lo = 0, hi = v.size(), med;
	while(lo + 1 < hi)
	{
		med = (lo + hi) / 2;
		if(med < val)
		{
			lo = med;
		}
		else
		{
			hi = med;
		}
	}
	return lo;
}



int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int st;
	cin >> st;	
	vector<int>::iterator it;
	for(int steps = 0; steps< st; steps++)
	{
		string s; int k;
		cin >> s >> k;
		vector<int> v(s.size()+1, 0);
		vector<int> cur;
		vector<int> pred(s.size()+1, -1);
		int n = s.size();
		long long ans = 0;
		if(s[0]!='a' && s[0]!= 'e' && s[0] != 'i' && s[0]!= 'o' &&s[0]!= 'u'){
			v[0] = 1;			
			if(k == 1)
				pred[0] = 0;
				//cur.push_back(0);
		}
		for(int i = 1; i < n; ++i){
			if(s[i]!='a' && s[i]!= 'e' && s[i] != 'i' && s[i]!= 'o' &&s[i]!= 'u'){
				v[i] = v[i-1]+1;
				if(v[i] >= k){
					//cur.push_back(i);
					pred[i] = i;
				}
				else
					pred[i] = pred[i-1];
			}
			else
				pred[i] = pred[i-1];
		}

		for(int i = 0; i < n; ++i)
		{
			if(v[i] >= k)
			{
				ans+=i+1-k+1;
				continue;
			}
			
			if(pred[i]!=-1)
				ans+=i+1-(i-pred[i]) -  k + 1;
		}

		printf("Case #%d: %lld\n", steps+1, ans);		
	}

}