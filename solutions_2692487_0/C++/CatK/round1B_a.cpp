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
const int maxn = 1000003;
const int inf = 1<<29;
int A, N;
int num[maxn];
pair<int,int> dp[maxn];
void input() {
     cin >> A >> N;
     for(int i = 0 ; i < N  ;i ++) {
         cin >> num[i];
     }
}

int cal(int& now, int goal) {
     int sum = 0;
     while(now <= goal) {
         sum ++;
         now += now-1;
     }
     return  sum;    
}

int solve() {
    int ans = inf, now = A;
    int sum = 0;
    sort(num, num + N);
    for(int i = 0 ; i < N ; i++) {
        if(now > num[N-1]) {
           break;
        }
        if(now > num[i]) {
           now +=num[i];
        } else {
           ans = min(ans, sum + (N - i));
           if(now > 1) {
              sum += cal(now, num[i]);
              now += num[i];
           } else {
              sum ++;
           }
        }
        //cout << sum <<  " " << now << endl;
       // system("pause");
    }
    return min(ans, sum);
}
int main() {
    freopen("C:/Users/wangkun/Downloads/A-small-attempt0 (1).in", "r" , stdin);
    freopen( "D:/result.out",  "w",stdout); 
    ll T , cas = 0;
    cin >> T;
    while(T--) {
         cas ++;
         input();
         cout << "Case #"<<cas <<": " << solve()<< endl;
    }
    return 0;
}
