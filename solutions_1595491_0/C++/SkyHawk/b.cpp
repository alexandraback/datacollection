//SkyHawk, CMC MSU

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;++i)

int ar[1000];

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	FOR(i,t)
	{
		cout << "Case #" << i+1 << ": ";
		int n,s,p;
		cin >> n >> s >> p;
		FOR(i,n)
			cin >> ar[i];		
		int ans = 0,sur = 0;
		if(p==0)
		{
			cout << n << endl;
			continue;
		}
		if(p==1)
		{
			int ans = 0;
			FOR(i,n)
				if(ar[i]>0)
					++ans;
			cout << ans << endl;
			continue;
		}
		FOR(i,n)
			if(ar[i]-p>=2*(p-1))
				++ans;
			else if(ar[i]-p>=2*(p-2))
				++sur;
		ans += min(sur,s);
		cout << ans << endl;
	}
}
