using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
/*
?
zero        o        e                      r
one         o   n   e
two         o           w   t
three               e       t    h          r
four        O                       f   u   r
five                e               f           i   v
six                                             i       x   s
seven           n   e                               v       s
eight               e       t    h              i               g
nine            n   e                           i
*/
typedef long long LL;
int getnum(char ch){
    return (int)ch-(int)('A');
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cerr<<getnum('B');
    cin>>t;
    cerr<<t;
    for (int i=1;i<=t;i++){
        string s;
        cin>>s;
        int cnt[30];
        memset(cnt,0,sizeof cnt);
        for (char ch: s){
            cnt[getnum(ch)]++;
        }
        int a[10];
        a[0]=cnt[getnum('Z')];
        a[8]=cnt[getnum('G')];
        a[6]=cnt[getnum('X')];
        a[7]=cnt[getnum('S')]-a[6];
        a[5]=cnt[getnum('V')]-a[7];
        a[4]=cnt[getnum('F')]-a[5];
        a[3]=cnt[getnum('H')]-a[8];
        a[2]=cnt[getnum('T')]-a[3]-a[8];
        a[1]=cnt[getnum('O')]-a[2]-a[4]-a[0];
        a[9]=cnt[getnum('I')]-a[5]-a[6]-a[8];
        cout<<"case #"<<i<<": ";
        for (int j=0;j<10;j++)
            for (int k=0;k<a[j];k++)
            cout<<j;
        cout<<endl;
    }

    return 0;
}
