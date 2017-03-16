//
//  main.cpp
//  1
//
//  Created by Wanjia He on 4/15/16.
//  Copyright © 2016 Wanjia He. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool head(string s, char ch){
    if (ch > s[0])
        return true;
    if (ch < s[0])
        return false;
    return head(s.substr(1, s.length()-1), s[0]);
}

int main(int argc, const char * argv[]) {
    ifstream fin("1.in"); ofstream fout("1.out");
    int l, t, i;
    string ans, s;
    fin >> t;
    for (l=1; l<=t; l++){
        fin >> s;
        ans = s[0];
        for (i=1; i<s.length(); i++){
            if (head(ans, s[i])){
                ans = s[i] + ans;
            }else{
                ans = ans + s[i];
            }
        }
        fout << "Case #" << l << ": " << ans << endl;
    }
    fin.close(); fout.close();
    return 0;
}
