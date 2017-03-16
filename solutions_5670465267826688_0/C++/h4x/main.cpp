//#define PARALLEL
#define PARALLEL_Threads 8

#include <iostream>
#include <cstring>
#include <cstdio>
#ifdef PARALLEL
#   include <pthread.h>
#   include <unistd.h>
#endif


using namespace std;


struct ttask
{
    int begin, end;
};

int mulmat[8][8] = {
//    1  i  j  k -1 -i -j -k
    { 0, 1, 2, 3, 4, 5, 6, 7 },
    { 1, 4, 3, 6, 5, 0, 7, 2 },
    { 2, 7, 4, 1, 6, 3, 0, 5 },
    { 3, 2, 5, 4, 7, 6, 1, 0 },
    { 4, 5, 6, 7, 0, 1, 2, 3 },
    { 5, 0, 7, 2, 1, 4, 3, 6 },
    { 6, 3, 0, 5, 2, 7, 4, 1 },
    { 7, 6, 1, 0, 3, 2, 5, 4 },
};

const char* elnm[] = { "1", "i", "j", "k", "-1", "-i", "-j", "-k" };

#define mul(m,n) (mulmat[m][n])
#define elem_1    0
#define elem_i    1
#define elem_j    2
#define elem_k    3
#define elem_neg1 4

int T;
int64_t tskL[110], tskX[110];
string tskSeq[110];
bool tskResult[110];

// m^n
int fastpow(int m, int n)
{
    int p = elem_1;
    int pow2n = m;
    while(n) 
    {
        if(n & 1) p = mul(p, pow2n);
        pow2n = mul(pow2n, pow2n);
        n >>= 1;
    }

    return p;
}

#ifdef PARALLEL
int fin = 0;
pthread_mutex_t finlock;
#endif

void* work_thread(void* arg)
{
    ttask* tsk = (ttask*)arg;
    int *Avec = new int[10010];
    int *Ahead = new int[10010];
    int *Atail = new int[10010];
    int from = tsk->begin;
    int to = tsk->end;

    for(int t=from; t<to; t++)
    {
        int64_t L = tskL[t];
        int64_t X = tskX[t];
        int64_t N = L*X;
        string& seq = tskSeq[t];

        for(int i=0; i<L; i++)
            Avec[i] = (int)(seq[i]-'i') + 1;

        Ahead[0] = Avec[0];
        Atail[L-1] = Avec[L-1];

        for(int i=1; i<L; i++)
            Ahead[i] = mul(Ahead[i-1], Avec[i]);
        for(int i=L-2; i>=0; i--)
            Atail[i] = mul(Avec[i], Atail[i+1]);

        int A = Ahead[L-1];
        int AX = fastpow(A, X);
        int An[4];

        An[0] = elem_1;
        for(int i=1; i<4; i++)
            An[i] = mul(An[i-1], A);

        if(AX != elem_neg1) 
        {
            //printf("Case #%d: no -1;\n", t+1);
            tskResult[t] = false;
            continue;
        }
        
        bool found_i = false;
        int64_t len_i = 0;
        for(int n=0; n<4 && n<X && !found_i; n++)
        {
            for(int j=0; j<L && !found_i; j++)
            {
                int val = mul(An[n], Ahead[j]);
                //printf("A^%d * A[0:%d] = %s\n", n, j+1, elnm[val]);
                if(val == elem_i)
                {
                    found_i = true;
                    len_i = n * L + (j + 1);
                    //printf("i: [0:%lld]\n", len_i);
                }
            }
        }

        if(!found_i)
        {
            //printf("Case #%d: no i;\n", t+1);
            tskResult[t] = false;
            continue;
        }

        bool found_k = false;
        int64_t len_k = 0;
        for(int n=0; n<4 && n<X && !found_k; n++)
        {
            for(int j=L-1; j>=0 && !found_k; j--)
            {
                int val = mul(Atail[j], An[n]);
                if(val == elem_k)
                {
                    found_k = true;
                    len_k = n * L + (L - j);
                    //printf("k: [-%lld:%lld]\n", len_k, len_k);
                }
            }
        }

        if(!found_k)
        {
            //printf("Case #%d: no k;\n", t+1);
            tskResult[t] = false;
            continue;
        }

        if(!(len_i + len_k < N))
        {
            //printf("Case #%d: overflow;\n", t+1);
        }

        tskResult[t] = (len_i + len_k < N);
    }

#ifdef PARALLEL
    pthread_mutex_lock(&finlock);
    fin++;
    pthread_mutex_unlock(&finlock);    
#endif

    return nullptr;
}

#ifdef PARALLEL
ttask taskinfo[PARALLEL_Threads];
pthread_t threads[PARALLEL_Threads];
void solve()
{
    pthread_mutex_init(&finlock, nullptr);

    int cnt = T / PARALLEL_Threads;
    for(int i=0; i<PARALLEL_Threads; i++)
    {
        taskinfo[i].begin = i * cnt;
        taskinfo[i].end = (i+1) * cnt;
    }

    taskinfo[PARALLEL_Threads-1].end = T;

    fin = 0;
    for(int i=0; i<PARALLEL_Threads; i++)
        //printf("#%d: [%d, %d)\n", i, taskinfo[i].begin, taskinfo[i].end),
        pthread_create(&threads[i], nullptr, work_thread, &taskinfo[i]);

    while(true)
    {
        int finval;
        
        pthread_mutex_lock(&finlock);
        finval = fin;
        pthread_mutex_unlock(&finlock);

        if(finval == PARALLEL_Threads) 
            break;
        
        usleep(100);
    }
}
#else
void solve()
{
    ttask tsk = { 0, T };
    work_thread(&tsk);
}
#endif

int main()
{
    cin >> T;
    
    for(int c=0; c<T; c++)
        cin >> tskL[c] >> tskX[c] >> tskSeq[c];

    solve();

    for(int c=0; c<T; c++)
        printf("Case #%d: %s\n", c+1, (tskResult[c] ? "YES" : "NO"));
    
    return 0;
}

