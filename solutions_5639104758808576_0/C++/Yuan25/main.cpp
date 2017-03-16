//Author: Yuan25
//I THINK THEREFORE I AM

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int, int> P;

int T,N;
string str;

int main(void) {
    
    //优化IO速度
    std::ios::sync_with_stdio(false);
    
    int k = 1;
    cin >> T;
    while(T--){
        cin >> N >> str;
        int i = 0,cur = 0;
        int ans = 0;
        while(i <= str.length()){
            if (cur >= i) {
                cur += str[i]-'0';
            }else{
                ans += i - cur;
                cur = i;
                cur += str[i]-'0';
            }
            i++;
        }
        cout << "Case #" << k++ << ": " << ans << endl;
    }
    
    return 0;
}

