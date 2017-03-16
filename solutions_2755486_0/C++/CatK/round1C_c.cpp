#include <vector>
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
struct Attact {
       int day,w,e,s;
};

vector<Attact> list;

bool cmp(const Attact& a, const Attact& b) {
     return a.day < b.day;
}

void input(int add) {
     int N ,d, n , w ,e ,s ,del_d , del_p , del_s;
     cin >> N;
      list.clear();     
     for(int i = 0 ; i < N ; i++) {
         cin >> d >> n >> w >> e>> s >> del_d >> del_p >> del_s;
         w*=2;
         e*=2;
         w+=add;
         e+=add;
         del_p*=2;
         for(int i = 0 ;i < n ; i++) {
             Attact att = {d,w,e,s};
             list.push_back(att);
             d+= del_d;
             w+=del_p;
             e+=del_p;
             s+=del_s;
         }
     } 
}

int solve_small () {
    int wall[1000];
    int ans = 0;
    memset(wall, 0 ,sizeof(wall));
    sort(list.begin(), list.end(),cmp);
    int raise[1000];
    memset(raise,0 , sizeof(raise));
    for(int i = 0; i < list.size() ; i++) {
       bool flag =false;
      // cout << list[i].day << " " << (list[i].w - 500)/2 << " " << (list[i].e - 500)/2 << " " << list[i].s << endl;
       for(int j = list[i].w ; j<=list[i].e; j++ ) {
           if(j<0 || j >= 1000) {
               cout << "Wrong " << j << endl;
               return -1;
           }
           if(wall[j] < list[i].s) {
               flag = true;
           }
           raise[j] = max(raise[j], list[i].s);
       }
       
       if(flag) {
          ans++;
       }
      // cout << " flag = " << flag << endl;
      // system("pause");
       if((i == list.size()-1) || (list[i].day != list[i+1].day)) {
          for(int i = 0 ; i < 1000 ; i++) {
              wall[i] = max(raise[i], wall[i]);
          }
          memset(raise, 0 , sizeof(raise));
       }
    }
    return ans;
}

int main() {
    freopen("C:/Users/wangkun/Downloads/C-small-attempt1.in", "r" , stdin);
    freopen( "D:/result.out",  "w",stdout); 
    int T , cas = 0;
    cin >> T;
    while(T--) {
         cas ++;
         input(500);
         cout << "Case #"<<cas <<": " << solve_small()<< endl;
    }
    return 0;
}
