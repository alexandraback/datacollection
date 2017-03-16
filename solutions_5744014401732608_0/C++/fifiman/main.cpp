  //freopen("test.txt", "r", stdin);
#include <bits/stdc++.h>
using namespace std;

#define llj(a,b,c) for (int (a) = (b); (a) < (c); (a)++)
#define lli(a,b) llj(i,a,b)
#define lll(i, x) llj(i, 0, x)
#define fori(x) lll(i, x)
#define forj(x) lll(j, x)
#define fork(x) lll(k, x)

#define all(X) (X).begin(), (X).end()
#define ever ;;
#define fe(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)

#define LINF ((ll) 1e18 + 10)
#define pb push_back
#define mp make_pair
#define ms(arr,val) memset(arr , val , sizeof(arr))
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))
#define endl "\n"
#define trace(X) cout << (X) << endl;
#define trace2(X,Y) cout << (X) << ' ' << (Y) << endl;
#define trace3(X,Y,Z) cout << (X) << ' ' << (Y) << ' ' << (Z) << endl;
#define trace4(X,Y,Z,A) cout << (X) << ' ' << (Y) << ' ' << (Z) << ' ' << (A) << endl;
#define tp(X) trace2(X.first ,X.second)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pvi(a) fe(thing ,a) cout << thing << ' '; cout << "\n";

typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) ((int)A.size())
#define x first
#define y second
#define read_speed ios::sync_with_stdio(false); cin.tie(0)
#define LINE cout << endl << "--------------------------" << endl
/*--------------------------THE END---------------------------------*/
const int MAX = 55;

int mat[MAX][MAX];

ll b,m;


void solve()
{
  cin >> b >> m;

  ms(mat, 0);

  int can = 1;

  if (m > (1LL << (b-2)))
  {
    can = 0;
  }
  else
  {
    // FULLY CONNECT THE GRAPH UP TO B-1

    llj(i,1,b)
    llj(j,i+1,b)
      mat[i][j] = 1;


    for (ll i = b-1; i >= 1; i--)
    {
      if (m >= max((1LL << (i-2)), 1LL))
      {
        m -= max((1LL << (i-2)), 1LL);
        mat[i][b] = 1;
      }
    }
  }

  trace( (can)?"POSSIBLE":"IMPOSSIBLE"  );

  if (can)
  {
    llj(i,1,b+1)
    {
      llj(j,1,b+1)
        cout << mat[i][j];
      cout << endl;
    }
  }

}





int main()
{
  freopen("test.txt", "r", stdin);
  //freopen("combo.in", "r", stdin);
  //freopen("combo.out", "w", stdout);
  read_speed;

  freopen("test.out", "w", stdout);

  int t;
  cin >> t;

  llj(z,1,t+1)
  {
    cout << "Case #" << z << ": ";
    solve();
  }

  


  

}


