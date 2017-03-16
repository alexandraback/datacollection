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
vector<int> vlist;
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

int main() {
    freopen("C:/Users/wangkun/Downloads/B-small-attempt0 (1).in", "r" , stdin);
    freopen( "D:/result.out",  "w",stdout); 
    int T , cas = 0;
    cin >> T;
    while(T--) {
         cas ++;
         input();
         cout << "Case #"<<cas <<": " << solve_small()<< endl;
    }
    return 0;
}
