#include <cstdio>
using namespace std;

const int table[5][5] = {{0, 0, 0, 0, 0},
                        {0, 1, 2, 3, 4},
                        {0, 2,-1, 4,-3},
                        {0, 3,-4,-1, 2},
                        {0, 4, 3,-2,-1}};
int lookup[256];

long long L, X;
char str[10010];

bool solve(){
    int head, tail, now, check;
    for(head=0,now=1; head<L; ++head)
    {
        if(now > 0) now = table[now][lookup[str[head]]];
        else now = -table[-now][lookup[str[head]]];
    }
    check = 1;
    for(int i=X%4; i>0; --i)
    {
        if(check > 0)
        {
            if(now > 0) check = table[check][now];
            else check = -table[check][-now];
        }
        else
        {
            if(now>0) check = -table[-check][now];
            else check = table[-check][-now];
        }
    }
    if(check != -1) return false;

    for(head=0,now=1; head<L*10&&now!=2; ++head)
    {
        if(now > 0) now = table[now][lookup[str[head%L]]];
        else now = -table[-now][lookup[str[head%L]]];
    }
    for(tail=0,now=1; tail<L*10&&now!=4; ++tail)
    {
        if(now > 0) now = table[lookup[str[L-1-(tail%L)]]][now];
        else now = -table[lookup[str[L-1-(tail%L)]]][-now];
    }
    return head<L*10 && tail<L*10 && head+tail<L*X;
}

int main()
{
    lookup['i'] = 2;
    lookup['j'] = 3;
    lookup['k'] = 4;
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%lld %lld", &L, &X);
        scanf("%s", str);
        printf("Case #%d: %s\n", cas, solve()?"YES":"NO");
    }
    return 0;
}
