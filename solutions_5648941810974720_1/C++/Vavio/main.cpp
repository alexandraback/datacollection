//
//  main.cpp
//  CountingSheep
//
//  Created by TT on 09/04/2016.
//  Copyright © 2016 TT. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <unordered_map>

using namespace std;

typedef long long ull;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

void fMain(int t){
    string S;
    fin >> S;
    unordered_map<char, int> count;
    
    
    
    for (int i=0; i<S.length(); ++i){
        if (count.find(S[i]) == count.end()){
            count[S[i]] = 0;
        }
        
        count[S[i]]++;
    }
    
    vector<int> ret;
    
    if (count.find('Z') != count.end()){
        int c = count['Z'];
        string n = "ZERO";
        for (int i=0; i<c; ++i){
            ret.push_back(0);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    
    if (count.find('U') != count.end()){
        int c = count['U'];
        string n = "FOUR";
        for (int i=0; i<c; ++i){
            ret.push_back(4);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    
    if (count.find('X') != count.end()){
        int c = count['X'];
        string n = "SIX";
        for (int i=0; i<c; ++i){
            ret.push_back(6);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    
    if (count.find('G') != count.end()){
        int c = count['G'];
        string n = "EIGHT";
        for (int i=0; i<c; ++i){
            ret.push_back(8);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    
    if (count.find('W') != count.end()){
        int c = count['W'];
        string n = "TWO";
        for (int i=0; i<c; ++i){
            ret.push_back(2);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    
    if (count.find('S') != count.end()){
        int c = count['S'];
        string n = "SEVEN";
        for (int i=0; i<c; ++i){
            ret.push_back(7);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }

    if (count.find('R') != count.end()){
        int c = count['R'];
        string n = "THREE";
        for (int i=0; i<c; ++i){
            ret.push_back(3);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    
    
    
    if (count.find('O') != count.end()){
        int c = count['O'];
        string n = "ONE";
        for (int i=0; i<c; ++i){
            ret.push_back(1);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    

    if (count.find('F') != count.end()){
        int c = count['F'];
        string n = "FIVE";
        for (int i=0; i<c; ++i){
            ret.push_back(5);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }

    
    if (count.find('N') != count.end() && count.find('I') != count.end()){
        int c = count['N'] / 2;
        string n = "NINE";
        for (int i=0; i<c; ++i){
            ret.push_back(9);
        }
        for (int i=0; i<n.length(); ++i){
            count[n[i]] -= c;
        }
    }
    
    sort(ret.begin(), ret.end());
    fout << "Case #" << t<< ": ";
    
    for (auto it = ret.begin(); it!=ret.end(); ++it){
        fout << *it;
    }
    fout << endl;
    
    bool flag = true;
    
    for (auto it = count.begin(); it != count.end(); ++it){
        if (it->second != 0 ){
            if (flag){
                cout << t << " " << S << endl;
                flag = false;
            }
            cout << "\t" << it->first << ": " << it->second << endl;
        }
    }
}




int main(int argc, const char * argv[]) {
    int T;
    fin >> T;
//    cout << T;
    for (int t = 1; t <=T; ++t){
        fMain(t);
    }
    fin.close();
    fout.flush();
    fout.close();
    return 0;
}
