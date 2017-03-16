//
//  main.cpp
//  a
//
//  Created by Zhou Sun on 15/4/11.
//  Copyright (c) 2015年 Zhou Sun. All rights reserved.
//

#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    int ts;
    ifstream in("a.txt");
    ofstream out("a.out");
    in>>ts;
    for (int tt=1; tt<=ts; tt++) {
        int n;
        string s;
        in>>n;
        int mx=0;
        int sum=0;
        in>>s;
        for (int i=0; i<=n; i++) {
            if (s[i]>'0'&&i>sum) {
                mx+=i-sum;
                sum=i;
            }
            sum+=s[i]-'0';
        }
        out<<"Case #"<<tt<<": "<<mx<<endl;
    }
    return 0;
}
