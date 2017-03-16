#include <iostream>
#include <iomanip>#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

int main () {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas=1;cas<=T;++cas) {
        long long r,t,a,b,c;
        cin>>r>>t;

        a = 2;
        b = 2*r-1;
        c = -t;


        cout<<"Case #"<<cas<<": "<<int((-b+sqrt(b*b-4*a*c))/2/a)<<endl;
    }
    return 0;
}

