#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cout<<"Case #"<<t<<": ";
        double c,f,x;
        cin>>c>>f>>x;
        double v=2.0;//initial v
        int n;
        if (x<=c) {
            n=0;
        } else {
            double th=((x-c)*v+f*x-x*v)/(c*f);
            if (th<0) th=0.0;
            n=th;
        }
        double ans=0.0;
        for (int i=0;i<=n;++i) {
            if (i<n) {
                ans+=c/(v+i*f);
            } else {
                ans+=x/(v+i*f);
            }
        }
        printf("%.7f\n",ans);
    }
    return 0;
}
