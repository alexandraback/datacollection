#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1

bool cons(char ch){
     if (ch=='a') return 0;
     if (ch=='i') return 0;
     if (ch=='u') return 0;
     if (ch=='e') return 0;
     if (ch=='o') return 0;
     return 1;
}
void solve(){
     string str;
     int n,len,ctr,ma,ret;
     ret=0;
     cin >> str >> n;
     len=str.size();
     for (int i=0;i<len;++i){
         for (int j=i+1;j<=len;++j){
             ctr=0;
             ma=-1;
             for (int k=i;k<j;++k){
                 if (!cons(str[k])){
                    ma=max(ma,ctr);
                    ctr=0;
                 }
                 else
                     ctr++;
             }
             ma=max(ma,ctr);
             ctr=0;
             //cout << i << " " << j << ": " << ma << endl;
             if (ma>=n) ret++;
         }
     }
     printf("%d\n",ret);
}

int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d: ",test);
        solve();
    }
    return 0;
}
