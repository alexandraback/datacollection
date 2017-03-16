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
char ydir[2] = { 'N', 'S'}; // up 0 , down 1
int dir[2] = { 1, -1}; // up 0 , down 1
char xdir[2] = { 'E', 'W'}; // left 0 , right 1

pair<int, int> check(const string& str) {
     int x= 0 ,y =0;
     for(int i = 0 ; i < str.size(); i ++) {
        switch(str[i]) {
            case 'N' : y+=i+1;break;
            case 'S' : y-= i+1;break;
            case 'E' : x+=i+1;break;
            case 'W' : x-=i+1;break;
        }
    //    cout << x << " " << y <<  " l = " << i+1 << endl;
     //   system("pause");
     }
     return make_pair(x,y);
}
string solve_small() {
     string ans ;
     int x , y ,sx , sy, l , i;
     cin >> x >> y;
     sx = 0 ;
     sy = 0;
     l = 1;
     for(i = 0; sy != y; i = (i+1)%2, l++) {
        sy = sy + dir[i]*l;
        //cout  << sy << endl;
       // system("pause");
        ans.push_back(ydir[i]);
     }
     if(x > 0) {
        i =1;
     } else {
        i =0;
     }
     for(; sx != x; i = (i+1)%2, l++) {
        sx = sx + dir[i]*l;
       // cout  << sx << endl;
       // system("pause");
        ans.push_back(xdir[i]);
     }
     if(ans.size() > 500) {
        return "Wrong";
     }
   // pair<int,int> v = check(ans);
    // cout << v.first << " : " << v.second << endl;
    /*
     if(v.first != x  || v.second != y) {
        return "Wrong";
     } else {
        return "Rright";
     }
     */
     return ans;
}
int main() {
    freopen("C:/Users/wangkun/Downloads/B-small-attempt1.in", "r" , stdin);
   freopen( "D:/result.out",  "w",stdout); 
    int T , cas = 0;
    cin >> T;
    while(T--) {
         cas ++;
         cout << "Case #"<<cas <<": " << solve_small()<< endl;
    }
    return 0;
}
