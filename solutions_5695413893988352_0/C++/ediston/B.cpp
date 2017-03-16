#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)

bool static comparedesc(const long &stud1, const long &stud2){
    return stud1 > stud2;
}

long long num1, num2;
string fs1, fs2;

void solve(long long tnum1, long long tnum2, long long pow, string &s1, string &s2, int ind, string &news1, string &news2){
    if(ind <0){
        if(num1 < 0  || abs(num1-num2) > abs(tnum1-tnum2)){
            num1 = tnum1;
            num2 = tnum2;
            fs1 = news1;
            fs2 = news2;
        }else if(abs(num1-num2) == abs(tnum1-tnum2)){
            if(num1 > tnum2){
                num1 = tnum1;
                num2 = tnum2;
                fs1 = news1;
                fs2 = news2;
            }else if(num1==tnum2 && num2 > tnum2){
                num1 = tnum1;
                num2 = tnum2;
                fs1 = news1;
                fs2 = news2;
            }
        }
        return;
    }
    if(s1[ind] != '?' && s2[ind] != '?'){
        solve(tnum1 + (s1[ind] - '0')*pow, tnum2 + (s2[ind] - '0')*pow, pow*10, s1, s2, ind-1, news1, news2);
    }
    else if(s1[ind] != '?' && s2[ind] == '?'){
        for(int i=0 ;i<=9; i++){
            news2[ind] = '0' + i;
            solve(tnum1 + (s1[ind] - '0')*pow, tnum2 + (news2[ind] - '0')*pow, pow*10, s1, s2, ind-1, news1, news2);
        }
    }else if(s1[ind] == '?' && s2[ind] != '?'){
        for(int i=0 ;i<=9; i++){
            news1[ind] = '0' + i;
            solve(tnum1 + (news1[ind] - '0')*pow, tnum2 + (s2[ind] - '0')*pow, pow*10, s1, s2, ind-1, news1, news2);
        }
    }else{
        for(int j=0; j<=9; j++){
            for(int i=0 ;i<9; i++){
                news1[ind] = '0' + i;
                news2[ind] = '0' + j;
                solve(tnum1 + (news1[ind] - '0')*pow, tnum2 + (news2[ind] - '0')*pow, pow*10, s1, s2, ind-1, news1, news2);
                news1[ind] = '0' + j;
                news2[ind] = '0' + i;
                solve(tnum1 + (news1[ind] - '0')*pow, tnum2 + (news2[ind] - '0')*pow, pow*10, s1, s2, ind-1, news1, news2);
            }
        }
    }
}

int main(){
    int t ;
    cin >> t;
    for(int _t=1; _t<=t; _t++){
        printf("Case #%d: ", _t);
        num1 = -1, num2 = -1;
        string s1, s2;
        cin >> s1 >> s2;
        string news1 =s1,  news2 = s2;
        solve(0, 0, 1, s1, s2, s1.length()-1, news1, news2);
        cout << fs1 << " " << fs2 << endl;
    }
    return 0;
}