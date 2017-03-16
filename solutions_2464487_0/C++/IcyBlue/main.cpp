#include <iostream>
#include <stdio.h>
#define UPPER 2147483648
using namespace std;

int main()
{
    int t;
    freopen("data.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    scanf("%d",&t);
    for (int times=1;times<=t ;times++)
    {
        long long r,paint;
        cin >> r >> paint;
        long long u = UPPER;
        long long d = 0;
        long long ans;
        long long check;
        bool flag = false;
        while (!flag)
        {
            ans = (u+d) / 2;
            long long check = 2*ans*r+ans+2*(ans-1)*(ans);
            if (check > paint || check < 0) u = ans;
            if (check <= paint) d = ans;
            if (u == d || u-1 == d) break;
        }
        printf("Case #%d: ",times);
        cout << d << endl;
    }
}
