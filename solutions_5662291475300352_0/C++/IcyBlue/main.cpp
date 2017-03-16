#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int s1,s2,n1,n2,t1,t2;
    freopen("c.in","r",stdin);
    freopen("c.txt","w",stdout);
    int times;
    cin >> times;
    for (int t = 0; t < times; t++)
    {
        int n;
        scanf("%d",&n);
        if (n == 1)
        {
            scanf("%d %d %d",&s1,&n1,&t1);
            printf("Case #%d: 0\n",t+1);
        }
        else
        {
            scanf("%d %d %d",&s1,&n1,&t1);
            scanf("%d %d %d",&s2,&n2,&t2);
            if (t1 > t2)
            {
                swap(t1,t2);
                swap(s1,s2);
            }
            s1 = s1 - 360;
            double de = (double)((double)s2*(double)t2 - (double)s1*(double)t1) / double(t2-t1);
            if (de <= 360) printf("Case #%d: 1\n",t+1);
            else printf("Case #%d: 0\n",t+1);
        }
    }
}
