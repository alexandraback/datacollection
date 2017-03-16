#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int n,a[500];
bool hasres;
int resa,resb;

void DFS(int now,int suma,int sumb,int usea,int useb)
{
    if (hasres == true) return;
    if (now > n)    return;
    if (usea != 0 && useb != 0 && suma == sumb)
    {
        hasres = true;
        resa = usea;
        resb = useb;
        return;
    }
    DFS(now+1,suma,sumb,usea,useb);
    DFS(now+1,suma+a[now],sumb,usea|(1<<now),useb);
    DFS(now+1,suma,sumb+a[now],usea,useb|(1<<now));
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        hasres = false;
        DFS(0,0,0,0,0);
        printf("Case #%d:\n",cas);
        if (hasres == false)
            puts("Impossible");
        else
        {
            for (int i = 0;i < n;i++)
                if (((resa>>i)&1) == 1)
                    printf("%d ",a[i]);
            printf("\n");
            for (int i = 0;i < n;i++)
                if (((resb>>i)&1) == 1)
                    printf("%d ",a[i]);
            printf("\n");
        }
	}
	return 0;
}
