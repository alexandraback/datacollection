//
//  main.cpp
//  GCJ20131CB
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

typedef pair<pair<long, long>, string> state;



const static string kProblemSet = "small";

int main(int argc, const char * argv[]) {
    ifstream ifs( kProblemSet + ".in" );
    ofstream ofs( kProblemSet + ".out" );
	int T = 0;
    
	ifs >> T;
    
    for (int testCase = 0; testCase < T; testCase++) {
        long X,Y;
        
        ifs >> X >> Y;
        map<pair<long, long>, string> minstep;
        
        string res;
        queue<pair<pair<long, long>, string> > q;
        q.push(make_pair(make_pair(0, 0), ""));
        while (q.size()) {
            state cu = q.front();
            q.pop();
            if (( abs(cu.first.first) > abs(X) && abs(cu.first.second) > abs(Y) )||  minstep.find(cu.first) != minstep.end()) {
                
                continue;
            }else {
                minstep[cu.first] = cu.second;
                
            }
            
            if (cu.first.first == X && cu.first.second == Y) {
                res = cu.second;
                break;
            }
            
            
            
            long step = cu.second.size()+1;
            
            state n = cu;
            n.first.second += step;
            n.second += 'N';
            q.push(n);
            
            state w = cu;
            w.first.first -= step;
            w.second += 'W';
            q.push(w);
            
            state s = cu;
            s.first.second -= step;
            s.second += 'S';
            q.push(s);
            
            state e = cu;
            e.first.first += step;
            e.second += 'E';
            q.push(e);
            
        }
        
        cout << "Case #" << testCase+1 << ": " << res << endl;
        ofs << "Case #" << testCase+1 << ": " << res << endl;
    }
    
	return 0;
}
