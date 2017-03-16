//
//  main.cpp
//  Round1A_B
//
//  Created by dengjc on 16/4/15.
//  Copyright © 2016年 dengjc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
        ofstream ofs;
        ifstream ifs;
        ofs.open("/Users/dengjc/Desktop/A-large");
        ifs.open("/Users/dengjc/Desktop/A-large.in");
        if (!ofs.is_open()||!ifs.is_open()) {
            cout<<"打开文件出错"<<endl;
            return 1;
        }
    
    int T;
    ifs>>T;
//    cin>>T;
    
    for (int i=1; i<=T; i++) {
        map<int,int> mp;
        vector<int> result;
        int N;
        ifs>>N;
        for (int j=0; j<(2*N-1)*N; j++) {
            int tmp;
            ifs>>tmp;
            if (mp.count(tmp)==0) {
                mp[tmp] = 1;
            } else {
                mp[tmp]++;
            }
        }
        map<int,int>::iterator iter = mp.begin();
        for (; iter!=mp.end(); iter++) {
            
            if (iter->second%2!=0) {
                result.push_back(iter->first);
            }

        }
        ofs<<"Case #"<<i<<": ";
        sort(result.begin(), result.end());
        for (int k=0; k<result.size(); k++) {
            ofs<<result[k]<<" ";
        }
        ofs<<endl;
    }
    
    
}