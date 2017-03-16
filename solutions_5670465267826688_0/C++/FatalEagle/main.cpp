#include <bits/stdc++.h>

using namespace std;

const int ONE=1;
const int I=2;
const int J=3;
const int K=4;
int mul[5][5];
int inv[5][5];

int N;
long long M;
char S[100001];
int A[100001];

inline int sgn(int x)
{
    if(x<0)
        return -1;
    return 1;
}

inline int multiply(int a, int b)
{
    return sgn(a)*sgn(b)*mul[abs(a)][abs(b)];
}

inline int powquat(int a, long long b)
{
    int ret=ONE;
    while(b)
    {
        if(b&1)
            ret=multiply(ret, a);
        a=multiply(a, a);
        b/=2;
    }
    return ret;
}

// y == x * ret
inline int getinv(int y, int x)
{
    return (sgn(y)/sgn(x))*inv[abs(y)][abs(x)];
}

inline int get(int l, int r)
{
    if(l==0)
        return A[r];
    return getinv(A[r], A[l-1]);
}

bool brute()
{
    for(int i=1; i<M; i++)
        for(int j=0; j<N; j++)
            A[j+i*N]=A[j];
    N*=M;
    for(int i=1; i<N; i++)
        A[i]=multiply(A[i-1], A[i]);
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N-1; j++)
            if(get(0, i)==I && get(i+1, j)==J && get(j+1, N-1)==K)
                return true;
    return false;
}

void _main()
{
    scanf("%d%lld%s", &N, &M, S);
    for(int i=0; i<N; i++)
    {
        if(S[i]=='i')
            A[i]=I;
        else if(S[i]=='j')
            A[i]=J;
        else if(S[i]=='k')
            A[i]=K;
        else
            assert(0);
    }
    if(brute())
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    mul[ONE][ONE]=ONE, mul[ONE][I]=I, mul[ONE][J]=J, mul[ONE][K]=K;
    mul[I][ONE]=I, mul[I][I]=-ONE, mul[I][J]=K, mul[I][K]=-J;
    mul[J][ONE]=J, mul[J][I]=-K, mul[J][J]=-ONE, mul[J][K]=I;
    mul[K][ONE]=K, mul[K][I]=J, mul[K][J]=-I, mul[K][K]=-ONE;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
            inv[abs(mul[i][j])][i]=sgn(mul[i][j])*j;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        _main();
    }
    return 0;
}
