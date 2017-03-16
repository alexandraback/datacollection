#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <set>
#include <map>
#include <stack>
using namespace std;
int x,y,n,m;
string res;
int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>x>>y;
        n = x<0?-x:x;
        m = y<0?-y:y;
        res = "";
        for (int i=0;i<n;++i) {
            if (x>0) res+="WE";
            else res+="EW";
        }
        for (int j=0;j<m;++j) {
            if (y>0) res+="SN";
            else res+="NS";
        }


        cout<<"Case #"<<t<<": ";
        cout<<res<<endl;
    }
    return 0;
}




