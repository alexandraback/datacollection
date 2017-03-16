#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int T, M, R, C;

int good(char _has[50][50], int r, int c)
{
    char has[50][50] = {{}};
    char rev[50][50]={{}};
    memcpy(has, _has, sizeof(has));
    if(has[r][c]) return 0;
    int res=0;
    queue<pair<int, int> > q;
    rev[r][c]=1;
    for(q.push(make_pair(r, c));!q.empty(); q.pop())
    {
        res++;
        r=q.front().first;
        c=q.front().second;
        bool adj=false;
        for(int rr=-1; rr<=1; rr++)
        for(int cc=-1; cc<=1; cc++)
        {
            int nr=r+rr;
            int nc=c+cc;
            if(0<=nr && nr<R && 0<=nc && nc<C && has[nr][nc])
                adj=true;
        }
        if(!adj)
        for(int rr=-1; rr<=1; rr++)
        for(int cc=-1; cc<=1; cc++)
        {
            int nr=r+rr;
            int nc=c+cc;
            if(0<=nr && nr<R && 0<=nc && nc<C && !rev[nr][nc])
            {
                rev[nr][nc]=1;
                q.push(make_pair(nr,nc));
            }
        }
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d%d%d", &R, &C, &M);
        printf("Case #%d:\n", t);
        int RC = R*C;
    if(RC > 30) continue;
        bool found=false;
        int cnt=0;
        for(int m=0; m<1<<RC; )
        {
            int c=__builtin_popcount(m);
            if(c<M)
            {
                m|=(m+1);
                continue;
            }
            else if(c>M)
            {
                m+=m&~(m-1);
            }
            else
            {
                char has[50][50] = {};
                for(int r=0; r<R; r++)
                for(int c=0; c<C; c++)
                {
                    has[r][c]=(m>>(r+c*R))&1;
                }
                for(int r=0; r<R; r++)
                for(int c=0; c<C; c++)
                {
                    if(good(has, r, c) == RC-M)
                    {
                        found=true;
                        for(int rr=0; rr<R; rr++)
                        {
                            for(int cc=0; cc<C; cc++)
                            {
                                putchar(has[rr][cc] ? '*' : rr==r && cc==c ? 'c' : '.');
                            }
                            puts("");
                        }
                        goto done;
                    }
                }
                m++;
            }
        }
        done:
        if(!found) puts("Impossible");
    }
    return 0;
}
