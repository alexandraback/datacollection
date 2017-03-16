#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstdlib>

using namespace std;

#define INF 0x2fffffff

double solve() {
    int a,b;
    cin >> a >> b;
    double p[111111];
    double t=1;
    double result=a+b+1;
    for (int i=1;i<=a;++i) {
        cin >> p[i];
        t*=p[i];
        result=min(result,t*(a-i+b-i+1)+(1-t)*(a-i+b-i+1+b+1));
    }
    result=min(result,double(2+b));
    return result;
}

int main()
{
    freopen("in","r",stdin);
    cout.precision(6);
    cout.setf(ios::fixed);
    int t;
    cin >> t;
    for (int i=1;i<=t;++i) cout << "Case #" << i << ": " << solve() << endl;
    return 0;
}
