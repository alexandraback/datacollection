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
#include <fstream>  
#include <sstream>  

using namespace std;

int judge(char ch) {
     return ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u';
}

long long solve_small() {
    string str;
    int n , L;
    vector<int> list;
    cin >>str>>n;
    for(int i = 0 ; i < str.size();  i++) {
        list.push_back(judge(str[i]));
       // cout << list[list.size()-1];
    }
    long long ans = 0;
    L = list.size();
    bool flag = false;
    int last = -1, index = -1;
    int sum = 0;
    for(int i = 0 ; i < L ; i++) {
       if (list[i] != last) {
           sum = 1;
           last = list[i];
       } else {
           sum++;
       }
       if(sum >=n && (last == 0)) {
           flag =true;
           index = i - n +1;
       }
       if(flag) {
          ans += index +1;
       }
    }
    return ans;
}
int main() {
    freopen("C:/Users/wangkun/Downloads/A-small-attempt0 (2).in", "r" , stdin);
    freopen( "D:/result.out",  "w",stdout); 
    int T , cas = 0;
    cin >> T;
    while(T--) {
         cas ++;
         cout << "Case #"<<cas <<": " << solve_small()<< endl;
    }
    return 0;
}
