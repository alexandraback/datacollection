//
//  main.cpp
//  round3_2
//
//  Created by wangdongfang on 15/5/10.
//  Copyright (c) 2015年 _. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>



using namespace std;
typedef pair<int, int> Pair;


int K;
int L;
int S;
int keys[30];
int target[30];

vector<char> target_str;

vector<char> keys_str;

long long max_num;
long long expect;

int keys_kind = 0;


long long cal(string& type) {
    long long num = 0;
       for (int i = 0; i < S; i++) {
        char a = type[i];
        int j = 0;
        int k = i;
  
        while (a == target_str[j]) {
   //         cout << "i "<< i << " j " << j << " a " << a << " target " << target_str[j] << endl;
            j++;
            if (j == L) {
                num++;
     
   //             cout << "nUm: " << num << endl;
                break;
            }
            k++;
            if (k == S)break;
            a = type[k];
        }
           if (max_num < num)
           {
               max_num = num;
           }
        
    }
    return num;
}

void dfs(string& type) {
    if (strlen(type.c_str()) == S) {
        
        expect += cal(type);
        return;
    }
//    cout << "type " << type << endl;
    for (int i = 0; i < keys_str.size(); i++) {
       
            char key_char = keys_str[i];
            string new_type = type + key_char;
    //        cout << "new: " << new_type << endl;
            dfs(new_type);
       
    }
    
}

void solve(int round) {
   //check
    for (int i = 0; i < 30; i++) {
        int tar_num = target[i];
        if (tar_num > 0 && keys[i] == 0) {
            cout << "Case #" << round << ": 0.0" << endl;
            return;
        }
    }
    string type = "";
    dfs(type);
    double prob = (1.0 * expect) / pow(K, S);
    double take = max_num - prob;
 //   cout << "expect: " << expect << endl;
  //  cout << "max: " << max_num << endl;
    cout << "Case #" << round << ": ";
    printf("%.7f\n", take);
    
    
}


int main() {
    
  //  freopen("/Users/wangdongfang/Myprogram/codejam2015/round3/round3_2/round3_2/sampledata", "r", stdin);
    
    int T;
    
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        scanf("%d%d%d", &K, &L, &S);
        max_num = 0;
        expect = 0;
        target_str.clear();
        keys_str.clear();
        keys_kind = 0;
        for (int j = 0;j < 30; j++) {
            keys[j] = 0;
            target[j] = 0;
        }
        for (int j = 1; j <= K; j++) {
            char key;
            cin >> key;
            if (keys[key - 'A'] == 0)keys_kind++;
            keys[key - 'A']++;
            keys_str.push_back(key);
            
        }
        for (int j = 1; j <= L; j++) {
            char tar;
            cin >> tar;
            target_str.push_back(tar);
            target[tar - 'A']++;
        }
        solve(i);
        
    }
    
    return 0;
}
