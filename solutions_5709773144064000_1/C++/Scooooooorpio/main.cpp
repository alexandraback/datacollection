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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;




void work();

int main(int argc, char *argv[])
{

#if 1
auto t1 = freopen("1.in","r",stdin);
if (t1== nullptr) {
    cerr <<"no file"<<endl;
    return 0;
}
auto t2 = freopen("output.txt","w",stdout);
#endif



    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Case #"<<i+1<<": ";
        work();
        cout<<endl;
    }

    cerr<<"end!!!!!!!!!!"<<endl;

}


void work() {
    double c,f,x;
    cin>>c>>f>>x;
    double re = x/2.0;
    double now = 0;
    double s = 2.0;
    while(now<re) {
        now+= c/s;
        s+= f;
        double nre = now + x/s;
        if (nre<re) re = nre;
    }
    cout<<setprecision(10)<<re;
}
