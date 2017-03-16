//
//  main.cpp
//  Dijkstra
//
//  Created by apple on 15/4/11.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
typedef long long ll;

string ss;

string mult(string a, string b){
    if (a == "1" && b == "1"){
        return "1";
    }
    if (a == "1" && b == "-1"){
        return "-1";
    }
    if (a == "1" && b == "i"){
        return "i";
    }
    if (a == "1" && b == "j"){
        return "j";
    }
    if (a == "1" && b == "k"){
        return "k";
    }
    if (a == "1" && b == "-i"){
        return "-i";
    }
    if (a == "1" && b == "-j"){
        return "-j";
    }
    if (a == "1" && b == "-k"){
        return "-k";
    }
    
    if (a == "-1" && b == "1"){
        return "-1";
    }
    if (a == "-1" && b == "-1"){
        return "1";
    }
    if (a == "-1" && b == "i"){
        return "-i";
    }
    if (a == "-1" && b == "j"){
        return "-j";
    }
    if (a == "-1" && b == "k"){
        return "-k";
    }
    if (a == "-1" && b == "-i"){
        return "i";
    }
    if (a == "-1" && b == "-j"){
        return "j";
    }
    if (a == "-1" && b == "-k"){
        return "k";
    }
    
    if (a == "i" && b == "1"){
        return "i";
    }
    if (a == "i" && b == "-1"){
        return "-i";
    }
    if (a == "i" && b == "i"){
        return "-1";
    }
    if (a == "i" && b == "j"){
        return "k";
    }
    if (a == "i" && b == "k"){
        return "-j";
    }
    if (a == "i" && b == "-i"){
        return "1";
    }
    if (a == "i" && b == "-j"){
        return "-k";
    }
    if (a == "i" && b == "-k"){
        return "j";
    }
    
    if (a == "-i" && b == "1"){
        return "-i";
    }
    if (a == "-i" && b == "-1"){
        return "i";
    }
    if (a == "-i" && b == "i"){
        return "1";
    }
    if (a == "-i" && b == "j"){
        return "-k";
    }
    if (a == "-i" && b == "k"){
        return "j";
    }
    if (a == "-i" && b == "-i"){
        return "-1";
    }
    if (a == "-i" && b == "-j"){
        return "k";
    }
    if (a == "-i" && b == "-k"){
        return "-j";
    }
    
    if (a == "j" && b == "1"){
        return "j";
    }
    if (a == "j" && b == "-1"){
        return "-j";
    }
    if (a == "j" && b == "i"){
        return "-k";
    }
    if (a == "j" && b == "j"){
        return "-1";
    }
    if (a == "j" && b == "k"){
        return "i";
    }
    if (a == "j" && b == "-i"){
        return "k";
    }
    if (a == "j" && b == "-j"){
        return "1";
    }
    if (a == "j" && b == "-k"){
        return "-i";
    }
    
    if (a == "-j" && b == "1"){
        return "-j";
    }
    if (a == "-j" && b == "-1"){
        return "j";
    }
    if (a == "-j" && b == "i"){
        return "k";
    }
    if (a == "-j" && b == "j"){
        return "1";
    }
    if (a == "-j" && b == "k"){
        return "-i";
    }
    if (a == "-j" && b == "-i"){
        return "-k";
    }
    if (a == "-j" && b == "-j"){
        return "-1";
    }
    if (a == "-j" && b == "-k"){
        return "i";
    }
    
    if (a == "k" && b == "1"){
        return "k";
    }
    if (a == "k" && b == "-1"){
        return "-k";
    }
    if (a == "k" && b == "i"){
        return "j";
    }
    if (a == "k" && b == "j"){
        return "-i";
    }
    if (a == "k" && b == "k"){
        return "-1";
    }
    if (a == "k" && b == "-i"){
        return "-j";
    }
    if (a == "k" && b == "-j"){
        return "i";
    }
    if (a == "k" && b == "-k"){
        return "1";
    }
    
    if (a == "-k" && b == "1"){
        return "-k";
    }
    if (a == "-k" && b == "-1"){
        return "k";
    }
    if (a == "-k" && b == "i"){
        return "-j";
    }
    if (a == "-k" && b == "j"){
        return "i";
    }
    if (a == "-k" && b == "k"){
        return "1";
    }
    if (a == "-k" && b == "-i"){
        return "j";
    }
    if (a == "-k" && b == "-j"){
        return "-i";
    }
    if (a == "-k" && b == "-k"){
        return "-1";
    }
    return "";
}

string next(string s){
    if (s == "i"){
        return "j";
    }
    if (s == "j"){
        return "k";
    }
    if (s == "k"){
        return "";
    }
    return "";
}

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/apple/Documents/coding/Xcode/Google Code Jam/Dijkstra/Dijkstra/output2.txt");
    ifstream cin("/Users/apple/Documents/coding/Xcode/Google Code Jam/Dijkstra/Dijkstra/C-large.in.txt");
    int T, t = 0;
    cin >> T;
    while (t++ != T){
        int L; string s;
        ll X;
        cin >> L >> X >> s;
        int temp = X % 12 + 12;
        X = temp > X ? X : temp;
        ss.clear();
        for (int i = 0; i < X; ++i){
            ss += s;
        }
        string target = "i";
        string cur = "1";
        for (int i = 0; i < X * L; ++i){
            cur = mult(cur, ss.substr(i, 1));
            if (cur == target){
                cur = "1";
                target = next(target);
            }
        }
        cout << "Case #" << t << ": ";
        if (target == "" && cur == "1"){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
