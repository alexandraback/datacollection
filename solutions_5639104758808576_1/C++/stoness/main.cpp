//
//  main.cpp
//  Codejam2015
//
//  Created by stoness on 15/4/11.
//  Copyright (c) 2015年 sts. All rights reserved.
//

#include <iostream>
using namespace std;

int q1() {
    int s(0),i(0),j(0),cnt(0),res(0);
    char c(0);
    cin>>s;
    cin.ignore();
    do {
        cin>>c;
        j=c-'0';
        if (i>cnt) { res+=i-cnt;cnt=i;}
        cnt+=j;
    } while (++i<=s);
    return res;
}

int main(int argc, const char * argv[]) {
    int T(0);
    cin>>T;
    for (int i=0;i<T;++i) {
        int r=q1();
        cout<<"Case #"<<i+1<<": "<<r<<endl;
    }
    return 0;
}
