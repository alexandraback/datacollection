#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
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
}

static int ssum(const vi &V, int mask)
{
    int t = 0;
    for (int i = 0; i < SZ(V); i++)
        if (mask & (1 << i))
            t += V[i];
    return t;
}

static void dump(const vi &V, int mask)
{
    bool first = true;
    for (int i = 0; i < SZ(V); i++)
        if (mask & (1 << i))
        {
            if (!first)
                printf(" ");
            first = false;
            printf("%d", V[i]);
        }
    printf("\n");
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d:\n", cas + 1);
        int N;
        cin >> N;
        vi V(N);
        for (int i = 0; i < N; i++)
            cin >> V[i];

        map<int, int> sols;
        int ma = -1, mb = -1;
        for (int m = 1; m < (1 << N); m++)
        {
            int t = ssum(V, m);
            if (sols.count(t))
            {
                ma = sols[t];
                mb = m;
                goto found;
            }
            sols[t] = m;
        }

        printf("Impossible\n");
        continue;
found:
        int com = ma & mb;
        ma ^= com;
        mb ^= com;
        dump(V, ma);
        dump(V, mb);
    }
    return 0;
}
