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
#include <string>

using namespace std;
/*5
 * 2 1
 * ik
 * 3 1
 * ijk
 * 3 1
 * kji
 * 2 6
 * ji
 * 1 10000
 * i
 */

// 'i' => 2  'j' => 3  'k' => 4
int lookup[5][5] = {
                {0, 0,  0, 0,  0},
                {0, 1,  2, 3,  4},
                {0, 2, -1, 4, -3},
                {0, 3, -4,-1,  2},
                {0, 4,  3,-2, -1},
             };

//unordered_map<string, int>hash_map;

bool s_check(string input){
    int prev = 1;
    int sign = 1;
    int len = input.length();
    int res;
    int index = 0;

    while(index < len){
        res = sign * lookup[prev][input[index]-'g'];
        if (res < 0) {sign = -1;}else{sign = 1;}
        prev = sign * res;
        index++;
    } 

    if (res == -1) return true;
    else return false;
}

//jijijijiji  
//i j k  It can be split into jij (which reduces to i), iji (which reduces to j), and jijiji (which reduces to k). 
bool check(int index, string input, int level) {
   
    int prev = 1;
    int sign = 1;
    int len = input.length();
    string str;
    
    if(index == len && level == 5) {
        return true;
    }
    if(index >= len || level > 4)
        return false;
    //cout << "level: " << level << endl;
    while(index < len){
        int tmp = sign * lookup[prev][input[index]-'g'];
        //cout << "sign: "<<sign << " prev: "<< prev ;
        //cout << " cur_char:" << input[index]; 
        //cout << " index: " << index << " value" << tmp << endl;
        //str+=input[index];
        if( tmp == level ){
            if (check(index+1, input, level+1))
                return true;
        }
        
        if (tmp < 0) {sign = -1;}else{sign = 1;}
        prev = sign * tmp;
        index++;
    }
    //cout << "exit level:"<< level << endl;
    return false;
}


int main() {
    int test_cnt;

    cin >> test_cnt;
    for(int i = 0; i < test_cnt; i++) {
        int in, repeat;
        string one_input;
        string input;
        cin >> in;
        cin >> repeat;
        cin >> one_input;
        while(repeat--){
            input+=one_input;
        }
       // cout << input << endl; 
        cout << "Case #" << i+1 << ": "; 
        if(s_check(input) && check(0, input, 2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
   
    return 0;
}
