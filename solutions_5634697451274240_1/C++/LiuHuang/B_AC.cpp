/* ***********************************************
Author        :oilover
Created Time  :2016/4/9 8:29:42
File Name     :
************************************************ */

#include <bits/stdc++.h>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
using namespace std;
 string s;
int main()
{
    int re, ca=1;
    cin>>re;
    while (re--) {
        cin>>s;
        printf("Case #%d: ", ca++);
        while (*s.rbegin() == '+') s.erase(s.size()-1);
        s.erase(unique(s.begin(), s.end()), s.end());
        cout<<s.size()<<endl;
    }
}
