#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[7000000];
int que[80000000];
int qt[100];
int reverseNum(int p)
{
    int i = 1;
    while ( p )
    {
        qt[i] = p % 10;
        p /= 10;
        i ++;
    }
    int ans = 0;
    for (int j = 1 ; j <= i - 1; j ++)
    {
        ans *= 10;
        ans += qt[j];

    }
    return ans;
}
bool v[1000002];
int bfs(int theEnd)
{
    for (int i = 1; i <= theEnd ; i ++)
        f[i] = 60000000;
    int l = 0 , r = 1;
    que[1] = 1;
    f[1] = 1;
    memset(que,0,sizeof(que));
    memset(v, 0 , sizeof(v));
    while (r != l)
    {
        l ++;
        if ( l == 80000000 - 5) l = 1;
        int x = que[l];
        int y = reverseNum(x);
        //cout <<"x " << x << "y " << y << endl;

        if (y > x && y <= theEnd && v[y] == false)
        {
            r ++;
            if ( r == 80000000 - 5) r = 1;
            que[r] = y;
            v[y] = 1;
            f[y] = min(f[y],f[x] + 1);
        }
        if (x + 1 > theEnd ) continue;
        if ( x + 1 <= theEnd && v[x + 1] == false)
        {
            r++;
            if ( r == 80000000 - 5 ) r = 1;
            que[r] = x + 1;
            v[x + 1] = 1;
            f[x + 1] = min(f[x + 1], f[x] + 1);
        }




    }
    return f[theEnd];
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int caseTest;
    scanf("%d",&caseTest);
    for (int _ = 1 ; _ <= caseTest ; _ ++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",_,bfs(n));
        /*for (int i = 1; i <= n ; i ++)
            cout << "f " << f[i] << endl;*/
    }
    fclose(stdin);
    fclose(stdout);
}
