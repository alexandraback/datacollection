#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>

#define For(i,a,n) for(int i =a ; i < n ; ++i )
#define all(x) (x).begin(),(x).end()
#define n(x) (int)(x).size()
#define pb(x) push_back(x)

using namespace std;
typedef pair<int,int> pii;
const int maxn = 550;
map <int,int> mp;
int n;
int a[maxn];

int main()
{
	int t;
	cin >>t ;
	For(it,0,t)
	{
		cin >> n;
		mp.clear();
		For(i,0,n)
			cin >> a[i];
		bool bo = false;
		cout << "Case #" << it+1 << ":" << endl;
		For(i,1,(1<<n))
		{
			int s= 0 ;
			int i2 = i;
			For(j,0,n)
			{
				if((i2&1))
					s+=a[j];
				i2>>=1;
			}
			if(mp[s])
			{
				i2 = mp[s];
				For(j,0,n)
				{
					if((i2&1))
						cout << a[j] << " ";
					i2>>=1;
				}
				cout << endl;
				i2 =i;
				For(j,0,n)
				{
					if((i2&1))
						cout << a[j] << " ";
					i2>>=1;
				}
				cout << endl;
				bo = true;
				break;
			}
			else
				mp[s]= i;

		}
		if(bo)
			continue;
		cout <<  "Impossible"  << endl;
	}
	return 0;
}
