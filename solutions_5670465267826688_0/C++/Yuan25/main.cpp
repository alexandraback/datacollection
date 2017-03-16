//Author: Yuan25
//I THINK THEREFORE I AM

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int, int> P;

int T;
long long L,X;
string use;
string str;

int tra[1000];
int sig[4][4] = {{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};
int mul[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};

int main(void) {
    
    //优化IO速度
    std::ios::sync_with_stdio(false);
    
    tra['1'] = 0;tra['i'] = 1;tra['j'] = 2;tra['k'] = 3;
    tra[0] = '1';tra[1] = 'i';tra[2] = 'j';tra[3] = 'k';
    
    cin >> T;int t = 0;
    while (T--) {
        t++;
        
        cin >> L >> X;
        if (X >= 4) {
            X = X % 4 + 4;
        }else{
            X = X % 4;
        }
        
        cin >> use;
        str.clear();
        for (int i = 0; i < X; i++) {
            str += use;
        }
        
        int cur_sig = 1;
        int cur_num = 0;
        for (int i = 0; i < str.length(); i++) {
            cur_sig *= sig[cur_num][tra[str[i]]];
            cur_num = mul[cur_num][tra[str[i]]];
        }

        if (!(cur_num == 0 && cur_sig == -1)) {
            cout << "Case #"<< t << ": " << "NO" <<endl;
            continue;
        }
        
        cur_sig = 1;
        cur_num = 0;
        int first_i = -1;
        for (int i = 0; i < str.length(); i++) {
            cur_sig *= sig[cur_num][tra[str[i]]];
            cur_num = mul[cur_num][tra[str[i]]];
            if(cur_num == 1 && cur_sig == 1){
                first_i = i;
                break;
            }
        }
        
        cur_sig = 1;
        cur_num = 0;
        int first_j = -1;
        for (int i = str.length()-1; i >= 0 ; i--) {
            cur_sig *= sig[tra[str[i]]][cur_num];
            cur_num = mul[tra[str[i]]][cur_num];
            if(cur_num == 3 && cur_sig == 1){
                first_j = i;
                break;
            }
        }
        
        if (first_i != -1 && first_j != -1 && first_i < first_j) {
            cout << "Case #"<< t << ": " << "YES" <<endl;
        }else{
            cout << "Case #"<< t << ": " << "NO" <<endl;
        }
        
    }
   
    
    return 0;
}

