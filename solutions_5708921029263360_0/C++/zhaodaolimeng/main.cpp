#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>
#include <iomanip>
using namespace std;

int T, J, P, S, K;
int jp[11][11];
int js[11][11];
int ps[11][11];

int main() {
    
    freopen("D:\\Desktop\\C-small-attempt2.in","r",stdin);
    freopen("D:\\Desktop\\test.out","w",stdout);   
    
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>J>>P>>S>>K; 
        
        vector<int> o1;
        vector<int> o2;
        vector<int> o3;
        
        memset(jp,0, sizeof(jp));
        memset(js,0, sizeof(js));
        memset(ps,0, sizeof(ps));
        
        cout<<"Case #"<<i<<": ";
        int t = 0;
        
        for(int j=1; j<=J; j++){
            for(int p=1; p<=P; p++){
                for(int s=1; s<=S; s++){
                    if(jp[j][p]>=K || js[j][s]>=K || ps[p][s]>=K)
                        continue;
                    o1.push_back(j);                    
                    o2.push_back(p);
                    o3.push_back(s);                    
                    
                    t++;
                    
                    jp[j][p]++;
                    js[j][s]++;
                    ps[p][s]++;
                }
            }
        }
        cout<<t<<endl;
        
        for(int i=0;i<t;i++){
            cout<<o1[i]<<" "<<o2[i]<<" "<<o3[i]<<endl;    
        }        
        
    }
    
    return 0;
}
