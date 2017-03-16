#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define fe(a, b, c) for(int a = b, __ = c; a <= __; a++)
#define gr(a, b) fr(a, 0, b)
#define ge(a, b) fe(a, 0, b)

#define rp(a, b) gr(a, b)

#define iter(c) __typeof((c).begin())
#define tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define iz(a) if(a == 0) { break; }

#define FASTIO ios_base::sync_with_stdio(0);

#define F first
#define S second

#define clr(a, b) memset(a, b, sizeof(a))

#define mp make_pair
#define pb push_back

#define sqr(x) ((x)*(x))

#define sd(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define slf(x) scanf("%lf", &x)
#define sii(x) scanf("%d%d", &x.F, &x.S)
#define sc(x) scanf(" %c", &x)
#define ss(x) scanf(" %s", x)
#define sn(x) scanf(" %[^\n]", x)

#define sd1(a) scanf("%d", &a)
#define sd2(a,b) scanf("%d %d", &a, &b)
#define sd3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sd4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define dbg(x) cout << x << endl;
#define db2(x) cout << #x << " = " << x << endl;
#define _ << ", " <<
#define line(x) { fr(i, 0, x) putchar('-'); puts(""); }
#define hello dbg("hello");

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }

typedef long long ll;;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;

template<class T1, class T2>
ostream& operator<< (ostream& c, pair<T1, T2> p)
{
	return c << "(" << p.F << ", " << p.S << ")";
}

const int inf = 0x3f3f3f3f;
const double eps = 1e-7;

int x, r, c;

int bt(vector<int> v)
{
    if(v.empty() || (*min_element(v.begin(), v.end()) == 0 && *max_element(v.begin(), v.end()) == 0))return 0;

    int ans = inf;

    tr(i, v)
    {
        fr(qt, 1, *i)
        {
            *i -= qt;
            tr(j, v)
            {
                if(i == j) continue;
                if(*j < qt) continue;
                *j += qt;
                ans = min(ans, bt(v));
                *j -= qt;
            }
            v.pb(qt);
            ans = min(ans, bt(v));
            v.pop_back();
            *i += qt;
        }
    }

    tr(i, v)
    {
        (*i)--;
    }

    ans = min(ans, bt(v));

    return ans + 1;
}

int main()
{
    FASTIO
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    cin >> T;

    fe(cas, 1, T)
    {
        int x, r, c;

        cin >> x >> r >> c;

        bool ok = 1;

        if(x >= 7 || (r * c)%x != 0)
        {
            ok = 0;
            printf("Case #%d: %s\n", cas, ok?"GABRIEL":"RICHARD");
            continue;
        }

        if(x == 3)
        {
            ok &= min(r, c) > 1;
        }
        else if(x == 4)
        {
            ok &= min(r, c) > 2;
        }
        else if(x == 5)
        {
            ok &= min(r, c) > 2;
            if(min(r, c) == 3)
            {
                ok &= max(r, c) >= 10;
            }
        }else if(x == 6)
        {
            ok &= min(r, c) > 3;
        }

        printf("Case #%d: %s\n", cas, ok?"GABRIEL":"RICHARD");
    }
}
