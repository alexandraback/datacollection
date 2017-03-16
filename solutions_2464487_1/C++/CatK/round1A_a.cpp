#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;

bool cal(long long i, long long r, ll n) {
     //return i*(2*i + 2*r -1) <= n;
     n/=i;
     n++;
     n -=2*r;
     if(n < 0) {
        return false;
     } else {
        n-=i;
        if(n < 0) 
           return false;
        n-=i;
        if(n < 0)
            return false;
     }
     return true;
}

long long solve(long long n , long long R) {
     ll l = 1 , r = n, ans = 0 ,mid;
     while(l <= r) {
        mid = (l+r)/2;
        if(cal(mid, R, n)) {
            ans = mid;
            l = mid +1;
        } else {
            r = mid -1;
        }
     }
     return ans;
}

int main() {
    freopen("C:/Users/wangkun/Downloads/A-large(1).in", "r" , stdin);
    freopen( "D:/result.out",  "w",stdout); 
    int T , cas = 0;
    long long r , n , x;
    cin >> T;
    while(T--) {
         cas ++;
         cin >> r >> n;
         cout << "Case #"<<cas <<": " << solve(n,r) << endl;
    }
    return 0;
}
