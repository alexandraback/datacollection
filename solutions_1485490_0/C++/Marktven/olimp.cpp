#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); (i) <= (b); ++(i))
#define mp make_pair
#define inf 2000000000
#define pb push_back
#define X first
#define Y second
#define LL long long
const double eps = 0.0000000001;

int n,m;
pair<LL, LL> a[1000], b[1000];
long long one[1000], two[1000], three[1000];
long long ans;

int main()
{
	freopen("A.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin >> T;
	FOR(test,1,T)
	{
		cin >> n>> m;
		FOR(i,1,n)
			cin >> a[i].Y >> a[i].X;
		if (n >= 2 && a[1].X == a[2].X)
		{
			a[1].Y += a[2].Y;
			a[2] = a[3];
			n--;
		}
		if (n >= 3 && a[2].X == a[3].X)
		{
			a[2].Y += a[3].Y;
			n--;
		}
		if (n >= 2 && a[1].X == a[2].X)
		{
			a[1].Y += a[2].Y;
			a[2] = a[3];
			n--;
		}

		FOR(i,1,m)
			cin >> b[i].Y >> b[i].X; 

		ans = 0LL;
		if (n == 1)
		{
			FOR(i,1,m)
				if (b[i].X == a[1].X)				
					ans += b[i].Y;
			if (ans > a[1].Y) ans = a[1].Y;
		} else
		if (n == 2)
		{
			one[0] = two[0] = 0LL;
			FOR(i,1,m)
			{
				one[i] = one[i-1];
				two[i] = two[i-1];
				if (b[i].X == a[1].X) one[i] += b[i].Y;
				if (b[i].X == a[2].X) two[i] += b[i].Y;			
			}
			FOR(i,0,m)
			{
				LL x = one[i];
				LL y = two[m] - two[i];
				LL ch = min(x,a[1].Y) + min(y,a[2].Y);
				if (ch > ans) ans = ch;
			}
		}
		else
		{
		one[0] = two[0] = three[0] = 0LL;
		FOR(i,1,m)
		{
			one[i] = one[i-1];
			two[i] = two[i-1];
			three[i] = three[i-1];
			if (b[i].X == a[1].X) one[i] += b[i].Y;
			if (b[i].X == a[2].X) two[i] += b[i].Y;
			if (b[i].X == a[3].X) three[i] += b[i].Y;
			//cout << " suma "<< one[i] << " " << two[i] << " " << three[i] << endl;
		}
		if (a[1].X == a[3].X)
		{
			FOR(i,1,m)
				if(b[i].X == a[1].X) ans += b[i].Y;
			LL suma = a[1].Y + a[3].Y;
			if (suma < ans) ans = suma;
		}
		for (int i = 0; i <= m; ++i)
			for(int j = i; j <= m; ++j)				
				{
					LL x = one[i];
					LL y = two[j] - two[i];
					LL z = three[m] - three[j];
					LL ch = min(x,a[1].Y) + min(y,a[2].Y) + min(z,a[3].Y);
					//cout << i << " " << j << "   " << x << " " << y << " " << z << "   " <<  ch << endl;
					if (ch > ans) ans = ch;
				}
		}
		cout<<"Case #"<<test<<": "<<ans<<endl;			
	}	
    return 0;
}