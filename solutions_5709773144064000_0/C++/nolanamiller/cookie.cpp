//
//  main.cpp
//  code_jam_q1
//
//  Created by Nolan Miller on 4/12/14.
//  Copyright (c) 2014 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

set<int> intersection(const set<int>& s1, const set<int> &s2){
    set<int> ret;
    set<int>::iterator it;
    for (it = s1.begin(); it!=s1.end(); it++) {
        if (s2.find(*it)!=s2.end()) {
            ret.insert(*it);
        }
    }
    return ret;
}

int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    for (int i = 0; i<n; i++) {
        long double c,f,x;
        long double time = 0;
        long double production = 2;
        cin>>c>>f>>x;
        cout<<"Case #"<<i+1<<": ";
        
        while (x>c) {
            time+=c/production;
            x-=c;
            if (x/production > (x+c)/(production+f)) {
                x+=c;
                production+=f;
//                cout<<"buying farm @ t="<<time<<endl;
//                cout<<"x="<<x<<endl;
//                cout<<"prod"<<production<<endl;
            }
            else
                break;
        }
        if (x!=0) {
            time+=x/production;
        }
        printf("%.7Lf",time);
        
        if(i+1!=n)
            cout<<endl;
    }
    return 0;
}
