#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

double opt1(int A, int B, vector<double>& p)
{
    double ret = 0, pp;
    int i;

    // all correct
    pp = 1.0;
    for(i=0;i<A;i++) {
        pp *= p[i];
    }
    ret = pp*(B-A+1) + (1.0-pp)*(B-A+1+B+1);

    return ret;
}

double opt2(int A, int B, vector<double>& p, int n)
{
    if (n == A)
        return n+B+1;
    return opt1(A-n, B, p)+n;
}

double opt3(int A, int B, vector<double>& p)
{
    return B+2;
}

int
main(void)
{
    int T;
    int i, j;
    int A, B;
    double d, tmp;
    double ret;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> A >> B;
        vector<double> p;
        for(j=0;j<A;j++) {
            cin >> d;
            p.push_back(d);
        }
        
        ret = opt1(A, B, p);
        // cout << "opt1 = " << ret << endl;
        for(j=1;j<=A;j++) {
            tmp = opt2(A, B, p, j);
            ret = min(ret, tmp);
            // cout << "opt2 = " << tmp << endl;
        }
        tmp = opt3(A, B, p);
        // cout << "opt3 = " << tmp << endl;
        ret = min(ret, tmp);
        
        printf("Case #%d: %f\n", i, ret);
        // cout << "Case #" << i << ": " << ret << endl;
    }
    
    return 0;
}
