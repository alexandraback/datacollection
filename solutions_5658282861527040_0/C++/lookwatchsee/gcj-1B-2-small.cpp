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
        int a,b,k;
        cin>>a>>b>>k;
        int ans=0;
        for (int i=0;i<a;++i) {
            for (int j=0;j<b;++j) {
                if ((i&j) < k) {
                    ans++;
                }
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
