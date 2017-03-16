#include <bits/stdc++.h>
using namespace std;
#define int long long
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
		double pos1, idc1, s1, pos2, idc2, s2;
		cin >> pos1 >> idc1 >> s1 >> pos2 >> idc2 >> s2;
		s1=(double)360/s1;
		s2=(double)360/s2;
		double maxspeed=dmin(s1*(360/(double)(360-pos1)), s2*(360/(double)(360-pos2)));
		double minspeed=dmax(s1*(360/(double)(720-pos1)), s2*(360/(double)(720-pos2)));
		if (maxspeed>minspeed)
		{
			cout << "Case #" << g+1 << ": " << 0 << '\n';  	
		}  
		else cout << "Case #" << g+1 << ": " << 1 << '\n'; 
	}
}
