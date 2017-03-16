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

bool q4()  {
    int x(0),r(0),c(0);
    cin>>x>>r>>c;
    if (x>=7) return true;
    else if (r*c%x!=0) return true;
    else if (r<x && c<x) return true;
    else if (x==1) return false;
    else if (x==3)  {
        if (r==1 || c==1) return true;
    } else if (x==4)  {
        if (r<=2 || c<=2) return true;
    } else if (x==5)  {
        if (r<=2 || c<=2) return true;
        if (r*c==15) return true;
    } else if (x==6) {
        if (r<=3 || c<=3) return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int T(0);
    cin>>T;
    for (int i=0;i<T;++i) {
        bool r=q4();
        cout<<"Case #"<<i+1<<": "<<(r?"RICHARD":"GABRIEL")<<endl;
    }
    return 0;
}
