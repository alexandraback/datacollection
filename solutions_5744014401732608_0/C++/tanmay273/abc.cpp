#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pl;

#define sl(x) scanf("%I64d",&x)
#define pl(x) printf("%I64d\n",x)
#define sf(x) sort(x.begin(),x.end(),func)
#define s(x) sort(x.begin(),x.end())
#define all(v) v.begin(),v.end()
#define rs(v) { s(v) ; r(v) ; }
#define r(v) {reverse(all(v));}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)

const ll mod = 1000000007;
const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;
const ld eps = 1e-12;
const ll N = 1000005;
const ll LOGN = 19;
ll n, M;
struct matrix{
    ll m[7][7] = {};
}I;
matrix mul(matrix a, matrix b)
{
    matrix tmp;
    f(i, 7)
    {
        f(j, 7)
        {
            f(k, 7)
            {
               tmp.m[i][j] = (tmp.m[i][j] + (a.m[i][k] * b.m[k][j]) + mod ) % mod;
            }
        }
    }
    return tmp;
}

matrix power(matrix a, int b)
{
    if(b == 1)
    {
        return a;
    }
    matrix tmp = power(a, b >> 1);
    matrix ret = mul(tmp, tmp);
    if(b & 1)
    {
        ret = mul(ret, a);
    }
    return ret;
}
matrix addd(matrix x, matrix y)
{
    matrix ret;
    f(i, 7)
    {
        f(j, 7)
        {
            ret.m[i][j] = x.m[i][j] + y.m[i][j];
        }
    }
    return ret;
}
matrix sum1(matrix a, ll p) {
		matrix z;
		if (p == 0) {
			return z;
		}
		if (p % 2 == 0) {
			return mul(sum1(a, p / 2),addd(I, power(a, p / 2)));
		} else {
			return addd(a, mul(sum1(a, p - 1), a));
		}
	}
bool is(matrix a)
{
    matrix b = sum1(a, n);
    if(b.m[0][n - 1] == M)
        return true;
    return false;
}
bool solve(matrix &a, ll i, ll j)
{
    j++;
    if(j == n)
    {
        i++;
        j = i + 1;
    }
    if(i == n - 1)
    {
        if(is(a)) return true;
        return false;
    }
    a.m[i][j] = 0;
    if(solve(a, i, j)) return true;
    a.m[i][j] = 1;
    if(solve(a, i, j)) return true;
    return false;
}

int main()
{
    FILE *fin = freopen("B-small-attempt1.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("B-small-attempt0.out", "w", stdout);
	ll t;
	f(i, 7)
	{
	    I.m[i][i] = 1;
	}
	cin >> t;
	ll tt = 1;
	while(t--)
    {
        cin >> n >> M;
        struct matrix tmp;
        cout << "Case #" << tt++ << ": ";
        if(solve(tmp, 0, 0))
        {
            cout << "POSSIBLE\n";
            f(i, n)
            {
                f(j, n)
                {
                    cout << tmp.m[i][j];
                }
                cout << "\n";
            }

        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
