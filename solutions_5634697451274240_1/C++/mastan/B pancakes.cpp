#include <cstdio>
#include <algorithm>

using namespace std;

void solvetc()
{
    char base[1005];
    int ln=0;
    scanf("%s",base+1);
    while (base[ln+1])
        ln++;
    while (base[ln]=='+' && ln>0)
        ln--;
    if (ln==0)
        printf("%d\n",0);
    else
    {
        int ret=1;
        for (int i=ln-1; i>=1; i--)
            if (base[i]!=base[i+1])
                ret++;
        printf("%d\n",ret);
    }
    return;
}

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int it=1; it<=t; it++)
    {
        printf("Case #%d: ",it);
        solvetc();
    }

}
