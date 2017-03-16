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

static const int MAXG = 200;

struct box
{
    int type;
    vector<int> keys;
    bool open;
};

static void dfs(vector<int> &have, vector<bool> &seen, int cur, const vector<box> &boxes, const vi *groups)
{
    if (!seen[cur])
    {
        seen[cur] = true;
        for (int i : groups[cur])
        {
            const box &b = boxes[i];
            if (!b.open)
            {
                for (int k : b.keys)
                {
                    have[k]++;
                    dfs(have, seen, k, boxes, groups);
                }
            }
        }
    }
}

static bool possible(const vector<box> &boxes, const vi *groups, const vi &ikeys, const vi &need)
{
    vector<bool> seen(MAXG);
    vector<int> have = ikeys;
    for (int i = 0; i < MAXG; i++)
    {
        if (ikeys[i])
            dfs(have, seen, i, boxes, groups);
    }
    for (int i = 0; i < MAXG; i++)
        if (have[i] < need[i])
            return false;
    return true;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d:", cas + 1);
        int K, N;
        cin >> K >> N;
        vi ikeys(MAXG);
        vi need(MAXG);
        for (int i = 0; i < K; i++)
        {
            int kt;
            cin >> kt;
            ikeys[kt - 1]++;
        }
        vector<box> boxes(N);
        vi groups[MAXG];
        for (int i = 0; i < N; i++)
        {
            int t, k;
            cin >> t >> k;
            t--;
            boxes[i].type = t;
            boxes[i].keys.resize(k);
            boxes[i].open = false;
            for (int j = 0; j < k; j++)
            {
                int kt;
                cin >> kt;
                boxes[i].keys[j] = kt - 1;
            }
            groups[t].push_back(i);
            need[t]++;
        }

        if (!possible(boxes, groups, ikeys, need))
            printf(" IMPOSSIBLE\n");
        else
        {
            for (int i = 0; i < N; i++)
            {
                int best = -1;
                for (int j = 0; j < N; j++)
                    if (!boxes[j].open && ikeys[boxes[j].type])
                    {
                        box &b = boxes[j];
                        ikeys[b.type]--;
                        for (int k : b.keys)
                            ikeys[k]++;
                        b.open = true;
                        need[b.type]--;
                        if (possible(boxes, groups, ikeys, need))
                        {
                            best = j;
                            break;
                        }
                        need[b.type]++;
                        b.open = false;
                        for (int k : b.keys)
                            ikeys[k]--;
                        ikeys[b.type]++;
                    }
                assert(best != -1);
                printf(" %d", best + 1);
            }
            printf("\n");
        }
    }
    return 0;
}
