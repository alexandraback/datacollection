#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;


int main (){
    int T,ans,flag;
    long long g,p,q,k;
    char c;
    cin >> T;
    for(int ca=1;ca<=T;ca++){
        cout << "Case #" << ca << ": ";
        cin >> p >> c >> q;
        g = __gcd(p,q);
        p = p/g;
        q = q/g;
        k = 1;
        flag = 0;
        ans = 0;
        for(int i=0;i<41;i++,k*=2){
            if(q == k){
                flag = 1;
                break;
            }
        }
        if(flag){
            ans = 1;
            while(q/2 > p){
                q = q / 2;
                ans++;
            }
            cout << ans << "\n";
        }else{
            cout << "impossible\n";
        }
    }
    return 0;
}

