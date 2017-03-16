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

#define FASTIO std_base::sync_with_stdio(0);

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

int l, x;
char s[10111];

int mult[5][5] =
{
    {
        0, 0, 0, 0, 0
    },
    {
        0, 1, 2, 3, 4
    },
    {
        0, 2, -1, 4, -3
    },
    {
        0, 3, -4, -1, 2
    },
    {
        0, 4, 3, -2, -1
    }
};

int mul(int a, int b)
{
    int sign = 1;
    if(a < 0) sign *= -1;
    if(b < 0) sign *= -1;

    return sign * mult[abs(a)][abs(b)];
}

map<char, int> m;

int expo(int b, ll e)
{
    int a = 1;

    while(e)
    {
        if(e&1) a = mul(a, b);
        b = mul(b, b);
        e >>= 1ll;
    }

    return a;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    m['1'] = 1;
    m['i'] = 2;
    m['j'] = 3;
    m['k'] = 4;

    int T;
    sd(T);
    fe(cas, 1, T)
    {
        sd(l);
        sd(x);
        ss(s);

        int ans = 1;

        int ma = 2;

        rp(k, x)
        {
            fr(i, 0, strlen(s))
            {
                ans = mul(ans, m[s[i]]);
                if(ans == ma)
                {
                    ans = 1;
                    ma++;
                }
            }
        }

        printf("Case #%d: %s\n", cas, ma > 4 && ans == 1?"YES":"NO");
    }
}
