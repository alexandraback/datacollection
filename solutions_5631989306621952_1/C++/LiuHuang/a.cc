/* ***********************************************
Author        :oilover
Created Time  :2016/4/16 9:21:01
File Name     :
************************************************ */

#include <bits/stdc++.h>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
using namespace std;

int main()
{
    int re,ca=1; cin>>re;
    while (re--) {

        string s; cin>>s;
        printf("Case #%d: ", ca++);
        string t;
        for (auto x : s) {
            if (t=="" || x<t[0])
                t = t + string(1,x);
            else
                t = string(1,x) + t;

        }
        cout<<t<<endl;
    }
    return 0;
}
