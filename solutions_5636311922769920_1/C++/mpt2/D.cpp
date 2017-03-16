#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <iomanip>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;

ll K,C,S;
ll KK[128];

int main()
{
  ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>K>>C>>S;
		cout<<"Case #"<<t+1<<":";
		
		KK[0] = 1LL;
		for(int i=1;i<=C;i++) KK[i] = KK[i-1] * K;
			
		int ming = max(1LL, (K+C-1LL)/C);
		if(ming > S) {cout << " IMPOSSIBLE\n"; continue;}
		
		ll r = 0;
		for(int i=0;i<ming;i++)
		{
			ll c = C-1;
			ll erg = 0;
			while(c >=0)
			{
				erg += (r * KK[c]);
				if(r < K-1) r++;
				c--;
			}
			cout << " " << erg+1;
		}
		cout << "\n";		
	}
  return 0;
}
