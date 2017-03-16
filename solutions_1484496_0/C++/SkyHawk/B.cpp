//SkyHawk, CMC MSU

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;++i)
#define PII pair<int,int>
#define EPS 1e-9

int ar[1000];
int ruk[1000010];

int main(int argc, char** argv)
{
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	int t;
	cin >> t;
	FOR(count,t)
	{
		int n;
		cin >> n;
		memset(ruk,0,sizeof(ruk));
		FOR(i,n)
			cin >> ar[i];
		cout << "Case #" << count+1 << ": ";
		int ans = -1;
		FOR(i,1<<n)
		{
			int s = 0;
			FOR(j,n)
				if(i&(1<<j))
					s+=ar[j];
			if(ruk[s])
			{
				cout << endl;
				FOR(j,n)
					if(i&(1<<j))
						cout << ar[j] << " ";
				cout << endl;
				FOR(j,n)
					if(ruk[s]&(1<<j))
						cout << ar[j] << " ";
				cout << endl;
				ans = 1;
				break;
			}
			ruk[s] = i;
		}
		if(ans == -1)
			cout << "Impossible" << endl;
	}
	return 0;
}
