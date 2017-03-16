#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define MULTI 2

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int L, X;
char VV[10240];

int dd[4][4] = {
    { 0, 1, 2, 3},
    { 1, 4, 3, 6},
    { 2, 7, 4, 1},
    { 3, 2, 5, 4}
};

int qs(int a, int b) {
    int aa = (a>=4) ^ (b>=4);
    return (dd[a%4][b%4] + (aa*4)) % 8;
}

bool go(LL &pos, int mdist, int target) {
    int cur = 0;
    for(int i=0;i<mdist;i++) {
        cur = qs(cur, VV[pos%L]);
        // cerr << pos << " = " << cur << endl;
        pos++;
        if(cur == target) return true;
    }
    return false;
}

bool gg() {
    long long len = L*X;
    long long pos = 0;
    if(!go(pos, L*5, 1)) return false;
    cerr << pos << endl;
    if(!go(pos, L*5, 2)) return false;
    cerr << pos << endl;
    if(!go(pos, L*5, 3)) return false;
    cerr << pos << endl;
    if(pos > len) return false;

    LL rem = (len - pos) % (L*4);
    // cerr << rem << endl;
    int cur = 0;
    while(rem) {
        cur = qs(cur, VV[pos % L]);
        pos++;
        rem--;
    }
    // cerr << pos << " = " << cur << endl;
    return cur == 0;
}

void solve(int dataId)
{
    for(int i=0;i<L;i++) VV[i] -= 'h';
    printf("Case #%d: %s\n", dataId, gg() ? "YES" : "NO");
}

void process(int dataId)
{
    scanf(" %d %d", &L, &X);
    scanf(" %s", VV);
}

class ForkSolver {
public:
    ForkSolver() : nchilds(0) { }

    vector<pair<pid_t,int> > outfds;
    void _solve(int dataId);
    int nchilds;
} solver;

int main(void)
{
    int N;
    cin >> N;
    solver.outfds.resize(N+1);
    for(int i=1;i<=N;i++)
    {
        process(i);
        solver._solve(i);
    }
    for(int i=1;i<=N;i++)
    {
        int status;
        char buffer[8192];
        waitpid(solver.outfds[i].first, &status, 0);
        ssize_t sz;
        while((sz = read(solver.outfds[i].second, buffer, sizeof(buffer))))
        {
            ssize_t iter = 0, outsz;

            while(iter != sz)
            {
                outsz = write(1, buffer + iter, sz - iter);
                if(outsz == -1)
                {
                    perror("write");
                    exit(-1);
                }
                iter += outsz;
            }
        }
    }
}

void ForkSolver::_solve(int dataId)
{
    int pipefd[2];

    while(nchilds >= MULTI)
    {
        int status = 0;
        int ret = waitpid(-1, &status, 0);
        if(ret == -1)
            perror("waitpid");
        else
            nchilds--;
    }

    pipe(pipefd);
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(-1);
    }

    if(pid) // I'm parent!
    {
        close(pipefd[1]); // close write end, i'll only read
        outfds[dataId] = mp(pid, pipefd[0]);
    }
    else
    {
        if(close(pipefd[0]) == -1) perror("close");
        if(dup2(pipefd[1], 1) == -1) perror("dup2");
        if(close(pipefd[1]) == -1) perror("close");
        solve(dataId);
        fprintf(stderr, "%d\n", dataId);
        exit(0); // force exit
    }
}


