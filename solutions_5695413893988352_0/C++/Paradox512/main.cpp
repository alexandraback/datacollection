#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int toInt(string s){
    int ans = 0;
    int power = 1;
    for(int i=0; i<s.size()-1; i++) power *= 10;
    for(int i=0; i<s.size(); i++){
        ans += (((int)s[i])-48) * power;
        power /= 10;
    }
    return ans;
}

string toString(int x, int length){
    string ans = "";
    while(x > 0){
        ans = (char)(x%10 + 48) + ans;
        x /= 10;
    }
    for(int i=ans.size(); i<length; i++){ ans = '0' + ans; }
    return ans;
}

void solve(int& minDiff, int& minC, int& minJ, string& c, string& j){
    bool found = false;
    for(int i=0; i<c.size(); i++){
        if(c[i] == '?'){
            found = true;
            for(int k=0; k<=9; k++){
                c[i] = (char)(k+48);
                solve(minDiff, minC, minJ, c, j);
                c[i] = '?';
            }
        }
    }
    if(!found){
        for(int i=0; i<j.size(); i++){
            if(j[i] == '?'){
                found = true;
                for(int k=0; k<=9; k++){
                    j[i] = (char)(k+48);
                    solve(minDiff, minC, minJ, c, j);
                    j[i] = '?';
                }
            }
        }
    }
    if(!found){
        int x = toInt(c);
        int y = toInt(j);
        int diff = abs(x-y);
        if(minDiff > diff){
            minDiff = diff;
            minC = x;
            minJ = y;
        }else if(minDiff == diff){
            if(minC > x){
                minC = x;
                minJ = y;
            }else if(minC == x && minJ > y){
                minJ = y;
            }
        }
    }
}

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    for(int i=0; i<t; i++){
        string c, j;
        cin >> c >> j;
        int length = c.size();
        int minDiff = 100000;
        int minC = 1000;
        int minJ = 1000;
        solve(minDiff, minC, minJ, c, j);
        cout << "Case #" << i+1 << ": " << toString(minC, length) << " " << toString(minJ, length) << endl;
    }
    return 0;
}
