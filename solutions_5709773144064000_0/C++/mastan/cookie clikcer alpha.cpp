#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("D:/tp.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int id=1; id<=tc; id++)
    {
        double c,f,x;
        scanf("%lf%lf%lf",&c,&f,&x);
        double cgain,ctime;
        ctime=0;
        cgain=2.0;
        double addtime=c/f;
        while (1)
        {
            if (c+c*cgain/f<x)
            {
                ctime=ctime+c/cgain;
                cgain=cgain+f;
            }
            else
                break;
        }
        printf("Case #%d: %.7lf\n",id,ctime+x/cgain);
    }
}
