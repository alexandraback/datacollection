#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }

    ios::sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
}

/*** END OF TEMPLATE CODE ***/

static ll reversi(ll n)
{
    ll r = 0;
    while (n > 0)
    {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return r;
}

static ll p10(int dig)
{
    return dig == 0 ? 1 : 10 * p10(dig - 1);
}

static ll dist10(int dig)
{
    if (dig == 1)
        return 1;
    else if (dig == 2)
        return 10;
    else
        return dist10(dig - 1) + p10(dig / 2) + p10((dig - 1) / 2) - 1;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    vi dist(1000001, INT_MAX);
    queue<int> q;
    dist[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        if (n + 1 < 1000000 && dist[n + 1] == INT_MAX)
        {
            dist[n + 1] = dist[n] + 1;
            q.push(n + 1);
        }
        int r = reversi(n);
        if (dist[r] == INT_MAX)
        {
            dist[r] = dist[n] + 1;
            q.push(r);
        }
    }
    dist[1000000] = dist[999999] + 1;
    assert(dist[1000000] == dist10(7));
    for (int cas = 0; cas < cases; cas++)
    {
        ll ans = 0;
        ll Ni;
        cin >> Ni;
        if (Ni <= 100)
            ans = dist[Ni];
        else
        {
            bool tens = false;
            if (Ni % 10 == 0)
            {
                tens = true;
                Ni--;
            }

            string N = to_string(Ni);
            int D = SZ(N);
            ll base = dist10(D);
            ans = base + Ni - p10(D - 1);
            if (Ni >= p10(D - 1) + p10((D + 1) / 2))
            {
                ll alt = base;
                for (int i = 0; i < D; i++)
                    alt += (N[i] - '0') * p10(min(i, D - 1 - i));
                ans = min(ans, alt);
            }
            if (tens)
                ans++;
        }
        cout << "Case #" << cas + 1 << ": " << ans << "\n";
    }
    return 0;
}
