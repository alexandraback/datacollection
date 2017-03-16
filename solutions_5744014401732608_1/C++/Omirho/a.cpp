#include<bits/stdc++.h>

using namespace std;

#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,n,0)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf mod
#define eps 1e-4
#define int long long
#define gc getchar

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("inn.in","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int cases;
	cin >> cases;
	for (int caseno = 1; caseno <= cases; caseno++)
	{
	    cout << "Case #" << caseno << ": ";
		int b,m;
		cin>>b>>m;
		if(1<<(b-2) < m)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        bool mat[b][b];
        memset(mat,0,sizeof mat);
        for(int i=0;i<b-1;i++)
        {
            for(int j=i+1;j<b-1;j++)
                mat[i][j] = 1;
        }
        int a = 64 - __builtin_clzll(m-1);
        if(a > b-1)
        {
            cout << "IMPOSSIBLE" << endl;;
            continue;
        }
        cout << "POSSIBLE" << endl; ;

        bitset<51> bs(m-1);
        for(int i=0;i<b-1;i++)
        {
            mat[i+1][b-1] = bs.test(i);
        }
        mat[0][b-1] = 1;
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<b;j++)
                cout << mat[i][j];
            cout << endl;
        }
	}
    return 0;
}
