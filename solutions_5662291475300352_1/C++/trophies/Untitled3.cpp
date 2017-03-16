#include <bits/stdc++.h>
using namespace std;
#define int long long
struct rat
{
	double pos, num, s; 	
};
double dmin (double a, double b)
{
	if (a<b)return a;return b;
}
double dmax (double a, double b)
{
	if (a>b)return a;return b;
}
main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
	int T; cin >> T;
	for (int g=0; g<T; g++)
	{
		int r; cin >> r;
		if (r==1)
		{
			int c,d,e;cin>>c>>d>>e;
			cout << "Case #" << g+1 << ": " << 0 << '\n'; continue; 
		}
		vector <rat> kk; 
		for (int t=0; t<r; t++)
		{
			double a,b,c;cin>>a>>b>>c;
			c=(double)360/c;
			rat n;n.pos=a;n.num=b;n.s=c;
			kk.push_back(n); 
		}
		int answer=1e9; 
		for (int g=0; g<(1<<kk.size()); g++)
		{
			double maxspeed=1e9+50;
			double minspeed=0; 
			for (int y=0; y<(kk.size()); y++)
			{
				if ((1<<y)&g)
				{
					for (int t=kk[y].s; t<kk[y].s+kk[y].num; t++)
					{
						maxspeed=dmin(maxspeed, (t)*(360/(double)(360-kk[y].pos)));
						minspeed=dmax(minspeed, (t)*(360/(double)(720-kk[y].pos)));
					}
				}
			}
			if (maxspeed>minspeed)
			{
				int r=0; 
				for (int z=0; z<(kk.size()); z++)
				{
					if ((1<<z)&g) continue;
					r+=kk[z].num;
				}
				if (r<answer)answer=r; 
			}
		}
		cout << "Case #" << g+1 << ": " << answer << '\n'; 
	}
}
