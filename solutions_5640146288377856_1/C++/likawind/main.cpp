//
//  main.cpp
//  A
//
//  Created by Zhou Sun on 15/5/10.
//  Copyright (c) 2015年 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    int ts,r,c,w,s;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in>>ts;
    for (int tt=1; tt<=ts; tt++) {
        in>>r>>c>>w;
        s=0;
        s+=(r-1)*max(1, (c-w)/w+1);
        s+=(c-w+1-2)/w+1+w;
        //123 45
       // 12 34 56 78 9;
        //out<<s<<endl;
        if (w==c && w!=1) {
            s--;
        }
        out<<"Case #"<<tt<<": "<<s<<endl;
    }
 
    
    return 0;
}
