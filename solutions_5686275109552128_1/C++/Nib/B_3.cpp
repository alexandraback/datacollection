#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(C) int(C.size())

int eat(vector<int>& D)
{
	if(D[0] < 4)
		return D[0];
	else
	{
		vector<int> a(D.begin(), D.end());

		for(int i = 0;i < sz(D);i++)
		{
			if(D[i] == 1)
				D.erase(D.begin()+i);
			else
				D[i] -= 1;
		}
		sort(D.begin(), D.end(), greater<int>());
		a.push_back(a[0] - a[0]/2);
		a[0] /= 2;
		sort(a.begin(), a.end(), greater<int>());
		return 1 + min(eat(a), eat(D));
	}	
}

int main(void)
{
	int t, d;
	scanf("%d", &t);
	for(int rep = 1;rep <= t;rep++)
	{
		scanf("%d", &d);
		vector<int> P(d);
		for(int i = 0;i < d;i++) scanf("%d", &P[i]);
		sort(P.rbegin(), P.rend());
		int ans = eat(P);
		printf("Case #%d: %d\n", rep, ans);
	}
}