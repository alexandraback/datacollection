#include <bits/stdc++.h>

#define li long int
#define lli long long int
#define loop(i, a, b) for(i=a; i<b; i++)
#define loope(i, a, b) for(i=a; i<=b; i++)
#define loopr(i, a, b) for(i=a; i>b; i--)
#define loopre(i, a, b) for(i=a; i>=b; i--)
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define MOD 1000000007
#define vi vector<int>
#define vpi vector< pair<int, int> >
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define cin fin
#define cout fout

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, t, r, c, w, ans;
    cin>>t;
    loope(i, 1, t)
    {
		cin>>r>>c>>w;
		ans=(c/w);
		ans=(r-1)*ans;
		if(w==c) ans+=c;
		else
		{
			if(c%w!=0) ans+=(c/w)+1+w-1;
			else ans+=(c/w)+w-1;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
