#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>

using namespace std;

#define pb push_back
#define INF 101111111
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define rep(i,n) FOR(i,0,n)
#define ford(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define CL(a,v) memset((a),(v),sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

int e[1010][1010];

int main()
{
	#ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        freopen("A-large.in","r",stdin);
        freopen("A-large.txt","w",stdout);
        //freopen("A-out.txt","w",stdout);
	#endif

    int T;
    cin >> T;

    rep(cs,T)
    {
        int N;
        cin >> N;

        CL(e,0);

        rep(i,N)
        {
            int m;
            cin >> m;

            rep(j,m)
            {
                int id;
                cin >> id;

                id --;

                e[i][id] = 1;
            }
        }

        rep(k,N) rep(i,N) rep(j,N) e[i][j] += e[i][k]*e[k][j];

//        rep(i,N)
//        {
//            rep(j,N) cout << ' ' << e[i][j];
//            cout << endl;
//        }

        bool yes = false;

        rep(i,N) rep(j,N) if(e[i][j]>1) yes = true;

        printf("Case #%d: ", cs+1);
        cout << (yes ? "Yes" : "No");
        printf("\n");
    }

	return 0;
}
