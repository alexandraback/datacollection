#include <iostream>
#include <stdio.h>
#include <math.h>

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
        double lpaint = log(paint);
        while (true)
        {
            ans = (u+d) / 2;
            long long check = (2*r+1+2*(ans-1))*ans;
            double cc = log(2*r+1+2*(ans-1));
            double cans = log(ans);
            if (cc+cans > lpaint) u = ans;
            if (cc+cans <= lpaint) d = ans;
            if (u == d || u-1 == d) break;
        }
        printf("Case #%d: ",times);
        d = d - 10;
        if (d <= 0) d = 1;
        while (true)
        {
            long long check = (2*r+1+2*(d-1))*d;
            if (check <= paint) {d++;flag = true;}
            else break;
        }
        if (flag) d--;
        cout << d << endl;
    }
}
