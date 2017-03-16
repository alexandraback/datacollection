#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;

int main(){
    ofstream output;
    ifstream fcin;
    fcin.open("in.in");
    output.open("outout.out");
    int t,n,num;
    vector<int> v;
    map<int,int> m;
    fcin>>t;
    for(int k=0;k<t;k++){
        fcin>>n;
        for(int i=0;i<n*(2*n-1);i++){
            fcin>>num;
            m[num]++;
        }
        map<int,int>::iterator it;

        for(it=m.begin();it!=m.end();it++){
            if((it->second)&1){
                v.push_back(it->first);
            }
        }
        sort(v.begin(),v.end());
        long s=v.size();
        output<<"Case #"<<k+1<<": ";
        for(int i=0;i<s;i++){
            output<<v[i]<<" ";
        }
        output<<"\n";
        m.clear();
        v.clear();
    }
    return 0;
}
