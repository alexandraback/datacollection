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

static int deceit(deque<double> A, deque<double> B)
{
    int N = SZ(A);
    int score = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[0] > B[0])
        {
            score++;
            A.pop_front();
            B.pop_front();
        }
        else
        {
            A.pop_front();
            B.pop_back();
        }
    }
    return score;
}

static int war(deque<double> A, deque<double> B)
{
    int N = SZ(A);
    int score = 0;
    for (int i = 0; i < N; i++)
    {
        if (A.back() > B.back())
        {
            score++;
            A.pop_back();
            B.pop_front();
        }
        else
        {
            auto pos = lower_bound(RA(B), A.back());
            A.pop_back();
            B.erase(pos);
        }
    }
    return score;
} 

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        cin >> N;
        deque<double> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];
        sort(RA(A));
        sort(RA(B));
        printf("Case #%d: %d %d\n", cas + 1, deceit(A, B), war(A, B));
    }
    return 0;
}
