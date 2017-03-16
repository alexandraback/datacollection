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

template<typename T> int size(const T &a) { return a.size(); } 

int K, L, S;
char kbd[1024];
char tgt[1024];
int overlap = 0;

double memo[105][105];

int maxpos(char *str, int len) {
    for(int i=len;i>0;i--) {
        bool fail = false;
        for(int j=0;j<i;j++) {
            if(tgt[j] != str[len - i + j]) {
                fail = true;
                break;
            }
        }
        if(!fail) return i;
    }
    return 0;
}

double expect(int space, int pos) {
    if(memo[space][pos] >= 0) return memo[space][pos];
    if(pos == L) {
        return memo[space][pos] = expect(space, overlap) + 1;
    }
    if(space == 0) return 0;

    char backlog[105];
    for(int i=0;i<pos;i++) backlog[i] = tgt[i];

    double ret = 0;
    for(int i=0;i<K;i++) {
        backlog[pos] = kbd[i];
        int np = maxpos(backlog, pos + 1);
        ret += (1.0 / K) * expect(space-1, np);
    }
    cerr << " " << space << " " << pos << " = " << ret << endl;
    return memo[space][pos] = ret;
}

void solve(int dataId)
{
    for(int i=0;i<105;i++) for(int j=0;j<105;j++) memo[i][j] = -1;
    overlap = 0;
    for(int i=1;i<L;i++) {
        bool fail = false;
        for(int j=i;j<L;j++) {
            if(tgt[j] != tgt[j-i]) { fail=true; break; }
        }
        if(!fail) {
            overlap = L-i;
            break;
        }
    }

    for(int i=0;i<L;i++) {
        bool found = false;
        for(int j=0;j<K;j++) {
            if(tgt[i] == kbd[j]) { found = true; break; }
        }
        if(!found) {
            printf("Case #%d: 0.0\n", dataId);
            return;
        }
    }

    int bring = 0;

    int pos = 0;
    for(int i=0;i <= S;) {
        i += (L - pos);
        bring++;
        pos = overlap;
    }
    bring--;

    cerr << dataId << " " << overlap << " " << bring << endl;

    double tmp = expect(S, 0);

    printf("Case #%d: %.12lf\n", dataId, (double)bring - tmp);
}

void process(int dataId)
{
    scanf(" %d %d %d %s %s", &K, &L, &S, kbd, tgt);
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
        nchilds++;
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


