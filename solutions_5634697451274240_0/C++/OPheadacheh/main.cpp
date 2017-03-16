//
//  main.cpp
//  2
//
//  Created by Wanjia He on 4/9/16.
//  Copyright © 2016 Wanjia He. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin;
    ofstream fout;
    fin.open("2.in");
    fout.open("2.out");
    int i, j, n, ans;
    string s;
    fin >> n;
    char now;
    for (i = 1; i <= n; i++){
        fin >> s;
        ans = 0;
        now = '+';
        for (j = s.length(); j > 0; j--){
            if (s[j-1] == now){
                continue;
            }else{
                ans++;
                now = s[j-1];
            }
        }
        fout << "Case #" << i << ": " << ans << endl;
    }
    cout << "done" << endl;
    fin.close();
    fout.close();
}
