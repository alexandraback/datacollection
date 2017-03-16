#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mk make_pair

vector <pair<int , pair<int , int> > > trp;

int main()
{
	int t;
	cin >> t;
	int test = 1;
	while(t--)
	{
		trp.clear();
		int n , s , p;
		cin >> n >> s >> p;
		for(int i=0 ; i<n ; i++)
		{
			int q;
			cin >> q;
			int m = q/3;
			trp.pb(mk(m , mk(m , m)));
			if(q % 3 >= 1)
				trp[i].x++;
			if(q % 3 >= 2)
				trp[i].y.x++;
		}
		sort(trp.begin() , trp.end());
		int a = 0;
		int b = n-1;
		while(b+1 > s && trp[b].x >= p)
			b--;
		for(int i=b ; i>=0 ; i--)
		{
			if(a < s && trp[i].x > 0)
			{
				if(trp[i].x != trp[i].y.x)
				{
					trp[i].y.x--;
					trp[i].y.y++;
				}
				else
				{
					trp[i].x--;
					trp[i].y.x++;
				}
				a++;
			}
			//cout << trp[i].x << " " << trp[i].y.x << " " << trp[i].y.y << endl;
		}
		int ans = 0;
		for(int i=0 ; i<n ; i++)
			if(trp[i].x >= p || trp[i].y.x >= p || trp[i].y.y >= p)
				ans++;
		cout << "Case #" << test << ": " << ans << endl;
		test++;
	}
}

