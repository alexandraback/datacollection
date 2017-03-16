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

int mul[4][4]={{0,1,2,3}, {1,0,3,2}, {2,3,0,1}, {3,2,1,0}};
int sig[4][4]={{1,1,1,1}, {1,-1,1,-1}, {1,-1,-1,1}, {1,1,-1,-1}};

int main()
{
#ifdef ACMTUYO
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int s=1, d=0;
		tint l, x;
		cin >> l >> x;
		string ss;
		cin >> ss;
		
		tint t=0;
		forn(i, 4*l)
		{
			if(t>=l*x) break;
			int d2=ss[t%l]-'i'+1;
			s*=sig[d][d2];
			d=mul[d][d2];
			
			//cout << t << " " << s << " " << d << endl;
			t++;
			
			if(s==1 && d==1) break;
		}
		
		if(!(s==1 && d==1)){ cout << "Case #" << tc+1 << ": " << "NO" << endl; continue; }  
		
		s=1, d=0;
		forn(i, 4*l)
		{
			if(t>=l*x) break;
			int d2=ss[t%l]-'i'+1;
			s*=sig[d][d2];
			d=mul[d][d2];
			
			//cout << t << " " << s << " " << d << endl;
			t++;
			
			if(s==1 && d==2) break;
		}
		
		if(!(s==1 && d==2)){ cout << "Case #" << tc+1 << ": " << "NO" << endl; continue; } 
		s=1, d=0;
		forn(i, l)
		{
			int d2=ss[i%l]-'i'+1;
			s*=sig[d][d2];
			d=mul[d][d2];
		}
		//cout << s << " " << d << endl;
		
		int p=x%4;
		int f=1, e=0;
		forn(i, p)
		{
			f*=s*sig[e][d];
			e=mul[e][d];
		}
		//cout << f << " " << e << endl;
		
		if(!(f==-1 && e==0)){ cout << "Case #" << tc+1 << ": " << "NO" << endl; continue; } 
		
		cout << "Case #" << tc+1 << ": " << "YES" << endl;
	}
	return 0;
}
