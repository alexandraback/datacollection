/*
                ================================
                Author : Adnaan 'Zohran' Ahmed
                Handle: adnaan1703
                Heritage Institute of Technology
                ================================
*/

#include <bits/stdc++.h>

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF LONG_MAX
#define X first
#define Y second
#define pb push_back

using namespace std;

typedef vector<int> vint;
typedef vector<long long int> vlint;
typedef vector<vector<int> > vvint;
typedef vector<vector<long long int> > vvlint;
typedef long long int lint;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	
	#ifndef ONLINE_JUDGE
    	freopen("inp.in", "r", stdin);
    	freopen("out.txt", "w", stdout);
	#endif
	

    int t = 1;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
    	cout<<"Case #"<<i<<": ";
        solve();
    }
	return 0;
}

void solve(void)
{
	float r,c,w;
	cin>>r>>c>>w;

	lint ans = ceil(c/w);
	//cout<<ans<<endl;

	ans*=r;
	ans += (w-1);

	cout<<ans<<endl;
}