/*

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
int n, P, s, a[101];
int can(int q)
{
    for (int p=P;p<=10;p++)
    {
        int k = q-p;
        if (((k == (p-1 + p-1)) && p-1 >= 0) ||
                ((k == (p-1 + p)) && p-1 >= 0) ||
                k == (p + p) ||
                ((k == (p + p+1)) && p+1<=10) ||
                ((k == (p+1 + p+1)) && p+1 <=10)) {
            return 1;
        }
    }
    for (int p=P;p<=10;p++)
    {
        int k = q-p;
        if (((k == (p-2 + p-2)) && p-2 >= 0)||
                ((k == (p-2 + p-1)) && p-2 >= 0) ||
                ((k == (p-2 + p)) && p-2 >= 0) ||
                ((k == (p-1 + p+1)) && p-1 >= 0 && p+1<=10) ||
                ((k == (p + p+2)) && p+2 <= 10) ||
                ((k == (p+1 + p+2)) && p+1 <= 10) ||
                ((k == (p+2 + p+2)) && p+2 <= 10)) {
            return -1;
        }
    }
    return 0;
}
void display()
{
    int T;
    //scanf("%d",&T);
    //for (int t=1;t<=T;t++) {
    //printf("Case #%d: ", t);
    //}
    scanf("%d",&T);
    for (int t=1;t<=T;t++) {
        printf("Case #%d: ", t);
        scanf("%d%d%d",&n, &s, &P);
        for (int i=0;i<n;i++) 
            scanf("%d",&a[i]);
        sort(a, a+n);
        int ans = 0;
        for (int i=0;i<n;i++) {
            int ret = can(a[i]);
            if (ret==1) {
                ans++;
            }
            else if (ret == -1) {
                if (s>0) {
                    s--;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    display();
    return 0;
}

