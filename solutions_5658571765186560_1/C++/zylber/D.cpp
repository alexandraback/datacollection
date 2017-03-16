#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

int tot[1024];

int main()
{
#ifdef ACMTUYO
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int x,r,c;
		cin >> x >> r >> c;
		
		if((r*c)%x) 
		{
			cout << "Case #" << tc+1 << ": RICHARD" << endl;
			continue;
		}
		
		if(x<=2) 
		{
			cout << "Case #" << tc+1 << ": GABRIEL" << endl;
			continue;
		}
		
		if(x>=7)
		{
			cout << "Case #" << tc+1 << ": RICHARD" << endl;
			continue;
		}
		
		if(x==3)
		{
			if(min(r,c)>1)
			{
				cout << "Case #" << tc+1 << ": GABRIEL" << endl;
			}
			else
			{
				cout << "Case #" << tc+1 << ": RICHARD" << endl;
			}
			continue;
		}
		
		if(x==4)
		{
			if(min(r,c)>2)
			{
				cout << "Case #" << tc+1 << ": GABRIEL" << endl;
			}
			else
			{
				cout << "Case #" << tc+1 << ": RICHARD" << endl;
			}
			continue;
		}
		
		if(x==5)
		{
			if(min(r,c)>3 || (min(r,c)==3 && max(r,c)>5))
			{
				cout << "Case #" << tc+1 << ": GABRIEL" << endl;
			}
			else
			{
				cout << "Case #" << tc+1 << ": RICHARD" << endl;
			}
			continue;
		}
		
		if(x==6)
		{
			if(min(r,c)>4)
			{
				cout << "Case #" << tc+1 << ": GABRIEL" << endl;
			}
			else
			{
				cout << "Case #" << tc+1 << ": RICHARD" << endl;
			}
			continue;
		}
	}
	return 0;
}
