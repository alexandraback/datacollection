#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
long long r,t;

const double PI = std::atan(1.0)*4;

int main(){
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    int gt,run;
    cin>>gt;
    long long ret;
    for(int run=1;run<=gt;run++){
        cin>>r>>t;
        ret=0;
        while(t>0){
            long long cur= (r*2+1);
            //cur= cur*PI;
            if(cur>t) break;
            ret++;
            r=r+2;
            t=t-cur;
        }
        cout<<"Case #"<<run<<": "<<ret<<endl;

    }
    return 0;
}




