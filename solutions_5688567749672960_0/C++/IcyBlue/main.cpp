#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int te[10];
int data[20];

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.txt","w",stdout);
    int times;
    cin >> times;
    te[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        te[i] = te[i-1]*10;
    }
    memset(data,0,sizeof(data));
    data[0] = 1;
    data[1] = 10;
    for (int i = 2; i < 20; i++)
    {
        data[i] = data[i-1] + te[i/2] + te[(i+1)/2] - 1;
    }
    for (int t = 0; t < times; t++)
    {
        long long n;
        scanf("%lld",&n);
        int cnt = 0;
        ;
        bool flag = false;
        if (n % 10 == 0)
        {
            n = n - 1;
            flag = true;
        }
        long long tt = n;
        while (tt != 0)
        {
            tt = tt / 10;
            cnt ++;
        }
        int ans = 0;
        if (cnt == 1) ans = n;
        else
        {
            tt = n;
            int temp = 0;
            for (int i = 0; i < cnt - cnt / 2; i++)
            {
                temp += (tt % 10) * te[i];
                tt = tt / 10;
            }
            ans += temp;
            temp = 0;
            for (int i = 0; i < cnt/2; i++)
            {
                temp += (tt % 10) * te[cnt/2 - 1 - i];
                tt = tt / 10;
            }
            ans += temp;
            if (temp == 1) ans --;
            ans += data[cnt-1];
        }
        if (flag) ans++;
        printf("Case #%d: %d\n",t+1,ans);
    }
}
