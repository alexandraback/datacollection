//
//  main.cpp
//  GCJ20131CA
//
//  Created by Seki Inoue on 2013/05/12.
//  Copyright (c) 2013年 Seki Inoue. All rights reserved.
//

//
//  This code uses project templates developed by peroxyacyl.
//  https://github.com/peroxyacyl/gcj-xcode-template
//


#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;



const static string kProblemSet = "small";

int main(int argc, const char * argv[]) {
    ifstream ifs( kProblemSet + ".in" );
    ofstream ofs( kProblemSet + ".out" );
	int T = 0;
    
	ifs >> T;
    
    for (int testCase = 0; testCase < T; testCase++) {
        int n = 0;
        string name;
        
        ifs >> name >> n;
        
        int nv = 0;
        for (int i = 0; i < name.length(); i++) {
            for (int j = i+1; j < name.length()+1; j++) {
                string substr = name.substr(i, j-i);
                int cs = 0;
                int maxcs = 0;
                for (int k = 0; k < substr.size(); k++) {
                    switch (substr[k]) {
                        case 'a':
                        case 'i':
                        case 'u':
                        case 'e':
                        case 'o':
                            maxcs = max(cs, maxcs);
                            cs = 0;
                            break;
                            
                        default:
                            cs++;
                            break;
                    }
                }
                maxcs = max(cs, maxcs);
                if (maxcs >= n) {
                    nv++;
                }
            }
        }
        
        
        cout << "Case #" << testCase+1 << ": " << nv << endl;
        ofs << "Case #" << testCase+1 << ": " << nv << endl;
    }
    
	return 0;
}
