#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstring>

#define MAXN 100005
#define INFTY 1000000000

using namespace std;
char s[MAXN];
int n;
// a, e, i, o, and u 
long long Solve(){
    int l = strlen(s);
    int en, st;
    int run = 0;
    long long res = 0;
    st = 0;
    en = -1;
    int check = 0;
    while(en < l){
         if(run >= n){
                res += l-en;
                st++;
                if(st > check) {
                      run--;
                      check = st;
                }
         }
         else{
             en++;
             if(s[en] == 'a' || s[en] == 'e' || s[en] == 'i' || s[en] == 'o' || s[en] == 'u'){              
                  run = 0;
             }
             else{
                  if(run == 0) check = en;
                  run++;
             }
         }
    }
    return res;
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int ca=1; ca<=t; ca++){
        cin >> s >> n;            
        cout<<"Case #"<<ca<<": ";
        cout<<Solve()<<endl;
    }
    return 0;
}
