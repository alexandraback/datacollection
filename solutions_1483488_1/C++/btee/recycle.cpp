#include <cstdlib>
#include <cstdio>

#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <vector>

#include <iostream>

using namespace std;

std::string int2str(int a) {
    std::stringstream ss;
    ss << a;
    return ss.str();
}

int str2int(const std::string& aStr) {
    int ret;
    std::stringstream ss(aStr);
    ss >> ret;
    return ret;
}

std::string rot1str(const std::string& aStr) {
    if(aStr.size() > 1) {
        std::string ret;
        ret.reserve(aStr.size());
        ret.append(aStr.begin()+1, aStr.end());
        ret += *aStr.begin();
        return ret;
    } else {
        return aStr;
    }
}

void rot1inp(std::string& aStr) {
    char b = *(aStr.begin());
    std::string::iterator jt=aStr.begin();
    std::string::iterator it=jt;
    ++jt;
    for(; jt != aStr.end(); ++it, ++jt) {
        *(it) = *(jt);
    }
    *(it) = b;
}

int nInRange(int a, int aMin) {
    return a - aMin;
}

// brutal
int solve(int aA, int aB) {
    int ret = 0;
    
    std::string a = int2str(aA);
    std::string b = int2str(aB);
    clog << "---" << a << ", " << b << "---" << endl;
    if(a.size() <= 1) return ret;
    
    int s = a.size();
    int i = aA;
    
    //int stop = (aB+aA)/2 + 1;
    int stop = aB;
    for(;i<stop;++i) {
        std::string cur = int2str(i);
        std::string rot = rot1str(cur);
        map<std::string,bool> was;
        
        for(int j=1; j<a.size(); ++j) {
            if(rot.size()==s && rot <= b && cur < rot) {
                was[rot] = true;
                clog << cur << ", " << rot << endl;
            }            
            rot = rot1str(rot);
        }
        ret += was.size();
    }
    
    return ret;
}


int solveDyn(int aA, int aB) {
    int ret = 0;
    
    std::string a = int2str(aA);
    std::string b = int2str(aB);
    
    int s = a.size();
    int i = aA;
    
    vector<bool> wasGlo(nInRange(aB,aA)+1,false);
    
    //int stop = (aB+aA)/2 + 1;
    int stop = aB;
    for(;i<stop;++i) {
        int inr = nInRange(i,aA);
        if(wasGlo[inr]){
            //clog << "speedup" << endl;
            continue;
        }
        wasGlo[inr] = true;
        
        std::string cur = int2str(i);
        std::string rot = rot1str(cur);
        set<int> was;
        
        for(int j=1; j<a.size(); ++j) {
            if(rot.size()==s && rot <= b && cur < rot) {
                int roti = str2int(rot);
                was.insert(roti);
                wasGlo[nInRange(roti,aA)] = true;
                //clog << cur << ", " << rot << endl;
            }            
            //rot = rot1str(rot);
            rot1inp(rot);
        }
        int ws = was.size();
        ret += (ws+ws*ws)/2;
    }
    
    return ret;
}

int main(){

    int cases;
    cin >> cases;

    for(int i=0; i<cases; ++i) {
        int a, b;
        cin >> a >> b;
        
        int ret = solveDyn(a,b);
        
        printf("Case #%d: %d\n", 
            (i+1), ret
        );
    }
    return 0;
}
