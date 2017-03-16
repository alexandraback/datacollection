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
vector<ll> vlist;
int E, N , R;
ll best;
void input() {
     cin  >> E >>R >> N ;
     vlist.clear();
     int v;
     for(int i = 0 ; i < N ; i++) {
         cin >> v;
         vlist.push_back(v);
     }
}

int dfs(int all, int index, ll ans) {
    if(all > E) all = E;
    if(index >=N) {
       best = max(ans, best);
    } else {
       ll v = vlist[index];
       for(int i =0 ; i <= all; i++) {
            dfs(all-i + R, index+1, ans + i*v);
       }   
    }
}

int solve_small() {
    best = 0;
    dfs(E, 0 , 0);
    return  best; 
}

ll Dfs(int l ,int r, int start, int end) {
    if (l > r) {
        return 0;
    }
    
    if(r == l) {
       ll t  = start - end;
       if(r != N-1) {
          t +=R;
       }
       if(t < 0) {
          cout << "Wrong" << endl;
       }
       return t*vlist[l];
    }
     
    int pos = -1;
    for(int i =l ; i <= r ; i++) {
        if(pos == -1 || vlist[pos] < vlist[i]) {
           pos = i;
        }
    }
    ll x = start + (pos - l)*R;
    ll sum;
    if(x > E)
       x = E;
    
    int next = (r - pos)*R - end;
    if(next < 0) {
       next = -next;
       sum = (x-next)*vlist[pos]; 
    } else {
       next = R;
       sum = x*vlist[pos];
    }
    
    if(next > E)
       next = E;
    return Dfs(l, pos -1, start, x) + Dfs(pos+1, r,  next, end) + sum; 
} 

ll solve_large() {
    return  Dfs(0,N-1,E,0);    
}

int main() {
    freopen("C:/Users/wangkun/Downloads/B-large (1).in", "r" , stdin);
freopen( "D:/result.out",  "w",stdout); 
    int T , cas = 0;
    cin >> T;
    while(T--) {
         cas ++;
         input();
         cout << "Case #"<<cas <<": " << solve_large()<< endl;
    }
    return 0;
}
