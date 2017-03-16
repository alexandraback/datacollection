#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

void doGen(int pos, string C, int num, vector<int> &vC) {
    if(pos == C.size()) {
        vC.push_back(num);
        return;
    }
    if(C[pos] == '?') {
        for(int d = 0; d < 10; d++) {
            doGen(pos + 1, C, num * 10 + d, vC);
        }
    }else {
        doGen(pos + 1, C, num * 10 + (C[pos]- '0'), vC);
    }
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-output.text", "w", stdout);
    int T;
    cin>>T;
    for(int tc = 1; tc <= T; tc++) {
        cout<<"Case #"<<tc<<": ";
        string C, J;
        cin>>C>>J;
        
        vector<int> vC;
        vector<int> vJ;
        doGen(0, C, 0, vC);
        doGen(0, J, 0, vJ);
        int sc = -1, sj = -1;
        for(int i = 0; i < vC.size(); i++) {
            for(int j = 0; j < vJ.size(); j++) {
                if(sc == -1) {
                    sc = vC[i];
                    sj = vJ[j];
                }else {
                    
                    int cdiff = abs(vJ[j]-vC[i]);
                    int diff = abs(sc-sj);
                    if(cdiff < diff) {
                        sc = vC[i];
                        sj = vJ[j];
                    }else if(cdiff == diff){
                        if(vC[i] < sc) {
                            sc = vC[i];
                            sj = vJ[j];
                        }else if(vC[i] == sc) {
                            if(vJ[j] < sj) {
                                sc = vC[i];
                                sj = vJ[j];
                            }
                        }
                    }
                }
            }
        }
        
        ostringstream oss1;
        ostringstream oss2;
        oss1<<sc;
        oss2<<sj;
       // cerr<<sc<<" "<<sj<<endl;
        string s1 = oss1.str();
        string s2 = oss2.str();
        
        if(s1.size() < C.size()) {
            int extra = C.size() - s1.size();
            for(int i = 0; i < extra; i++) {
                s1 = "0"+s1;
            }
            
        }
        
        if(s2.size() < C.size()) {
            int extra = C.size() - s2.size();
            for(int i = 0; i < extra; i++) {
                s2 = "0"+s2;
            }
            
        }
        cout<<s1<<" "<<s2<<endl;
    }
    return 0;
}