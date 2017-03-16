#include <cstdlib>
#include <cstdio>
#include <cmath>

#include <algorithm>
#include <functional>
#include <vector>

#include <iostream>

using namespace std;

vector<double> solve(const vector<int>& aPts) {
    vector<double> ret(aPts.size(), -1.0);
    
    int size = aPts.size();
    double sum = 0;
    for(vector<int>::const_iterator it = aPts.begin(); aPts.end() != it; ++it) {
        sum += *it;
    }
    double avg = sum / size;
    
    // double opt = 2*sum / size;
    double opt = avg + avg;
    
    clog << " sum: " << sum << " avg: " << avg << " opt:" << opt
        << " size: " << size
        << endl;

    int lastFighting;
    
    double newOpt = opt;
    int fighting = size;

    do {
        opt = newOpt;
        lastFighting = fighting;
        
        fighting = 0;
        double sumFighting = 0.0;
        for(int i = 0; i < aPts.size(); ++i) {
            if(ret[i] < 0.0){
                if(aPts[i] <= opt) {
                    ++fighting;
                    sumFighting += aPts[i];
                } else {
                    ret[i] = 0.0;
                }
            }
        }
        newOpt = (sum+sumFighting)/fighting;
        clog 
            << " fight: " << fighting 
            << " sumFighting: " << sumFighting 
            <<" new opt:" << newOpt << endl;
    } while (fighting != lastFighting);


    for(int i = 0; i < aPts.size(); ++i) {
        if(ret[i] < 0.0) {
            double req = opt - aPts[i];
            ret[i] = req/sum;
        }
    }
    
    return ret;
}

int main(){
    int cases;
    cin >> cases;

    for(int i=0; i<cases; ++i) {
        int a;
        cin >> a ;
        vector<int> p(a);
        for(int j=0;j<a;++j){
            cin >> p[j];
            clog << " " << p[j];
        }
        clog << endl;
        
        vector<double> ret = solve(p);
        
        cout << "Case #"<< (i+1) <<":";
        for(vector<double>::iterator it=ret.begin(); it!=ret.end(); ++it) {
            cout << " " << fixed << (*it*100.0);
        }
        cout << endl;
    }
    return 0;
}
