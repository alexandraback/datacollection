#include <bits/stdc++.h>
using namespace std;
int x,r,c;
bool works(int abv,int bel)
{
    for (int i=0;i<=r;i++)
    {
        if ((i*c-abv)%x==0 && ((r-i-1)*c-bel)%x==0) return false;
    }
    return true;
}

int main()
{
    freopen("D-small-attempt4.in","r",stdin);
    freopen("D.out","w",stdout);
    int T;
    cin >> T;
    for (int qq=0;qq<T;qq++)
    {

        cin >> x >> r >> c;
        if (r<c)
        {
            swap(r,c);
        }
        if (r*c % x !=0)
        {
            printf("Case #%d: RICHARD\n",qq+1);
            continue;
        }
        if (x>=7)
        {
            printf("Case #%d: RICHARD\n",qq+1);
            continue;
        }
        if (x>min(r,c)*2-1)
        {
            printf("Case #%d: RICHARD\n",qq+1);
            continue;
        }
        if (x<r)
        {
            printf("Case #%d: GABRIEL\n",qq+1);
            continue;
        }
        bool f = false;
        for (int abv = 0;abv<=x-c;abv++)
        {
            if (works(abv,x-c-abv))
            {
                printf("Case #%d: RICHARD\n",qq+1);
                f = true;
                break;
            }
        }
        if (!f)
        {
            printf("Case #%d: GABRIEL\n",qq+1);
            continue;
        }
    }
}
