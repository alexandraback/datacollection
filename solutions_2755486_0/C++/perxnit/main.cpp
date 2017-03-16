//
//  main.cpp
//  GCJ20131CC
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

class schedule {
public:
    long day, s, w, e;
    
    bool operator<(const schedule &other) const {
        return day<other.day;
    }
};

const static string kProblemSet = "small";

int main(int argc, const char * argv[]) {
    ifstream ifs( kProblemSet + ".in" );
    ofstream ofs( kProblemSet + ".out" );
	int T = 0;
    
	ifs >> T;
    
    for (int testCase = 0; testCase < T; testCase++) {
        long res = 0;
        
        int N;
        ifs >> N;
        vector<long> d,n,w,e,s,dd,dp,ds;
        map<long, long> wall, tmpwall;
        
        vector<schedule> sches;
        for (int i = 0; i < N; i++) {
            long td,tn,tw,te,ts,tdd,tdp,tds;
            ifs >> td >> tn >> tw >> te >> ts >> tdd >> tdp >> tds;
            d.push_back(td);
            n.push_back(tn);
            w.push_back(tw);
            e.push_back(te);
            s.push_back(ts);
            dd.push_back(tdd);
            dp.push_back(tdp);
            ds.push_back(tds);
            
            for (int j = 0; j < tn; j++) {
                schedule sch;
                sch.day = td + j*tdd;
                sch.e = te + j*tdp;
                sch.w = tw + j*tdp;
                sch.s = ts + j*tds;
                
                sches.push_back(sch);
            }
        }
        
        sort(sches.begin(), sches.end());
        
        long day = -1;
        
        for (int i = 0; i < sches.size(); i++) {
            schedule sc = sches[i];
            if (day < sc.day) {
                //alter day
                wall = tmpwall;
            }
            
            bool atsuc = false;
            for (long j = sc.w; j < sc.e; j++) {
                
                if (wall[j] < sc.s) {
                    tmpwall[j] = max(sc.s,tmpwall[j]);
                    atsuc = true;
                }
            }
            
            if (atsuc) {
                res++;
            }
            
            day = sc.day;
        }
        
        cout << "Case #" << testCase+1 << ": " << res << endl;
        ofs << "Case #" << testCase+1 << ": " << res << endl;
    }
    
	return 0;
}
