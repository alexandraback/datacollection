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

static vector<string> solve(int R, int C, int M)
{
    int K = R * C - M;
    vector<string> ans(R, string(C, '.'));
    if (C == 1)
    {
        for (int i = 0; i < M; i++)
            ans[i][0] = '*';
        ans[R - 1][0] = 'c';
    }
    else if (C == 2)
    {
        if (K == 2 || (K > 2 && K % 2 == 1))
            return {};
        for (int i = 0; i < M; i++)
            ans[i / 2][i % 2] = '*';
        ans[R - 1][C - 1] = 'c';
    }
    else
    {
        vector<int> stacks;
        switch (K)
        {
        case 2:
        case 3:
        case 5:
        case 7:
            return {};
        case 1:
            stacks.push_back(1);
            break;
        case 4:
            stacks.push_back(2);
            stacks.push_back(2);
            break;
        default:
            int S = 2;
            do
            {
                S++;
                stacks.resize(S);
                for (int i = 0; i < S; i++)
                    stacks[i] = (K + S - i - 1) / S;
                if (stacks[1] < stacks[0])
                {
                    stacks[1]++;
                    stacks.back()--;
                }
            } while (stacks[0] > R);
            break;
        }
        ans = vector<string>(R, string(C, '*'));
        for (int i = 0; i < SZ(stacks); i++)
            for (int j = 0; j < stacks[i]; j++)
                ans[j][i] = '.';
        ans[0][0] = 'c';
    }
    return ans;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int R, C, M;
        cin >> R >> C >> M;
        printf("Case #%d:\n", cas + 1);

        bool swapped = false;
        if (R < C)
        {
            swap(R, C);
            swapped = true;
        }
        auto ans = solve(R, C, M);
        if (swapped && !ans.empty())
        {
            auto other = ans;
            ans.clear();
            ans.resize(C, string(R, '?'));
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    ans[j][i] = other[i][j];
        }
        if (ans.empty())
            printf("Impossible\n");
        else
            for (const string &s : ans)
                printf("%s\n", s.c_str());
    }
    return 0;
}
