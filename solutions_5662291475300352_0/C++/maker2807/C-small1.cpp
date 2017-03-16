#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <utility>
#include <set>
#include <map>
#include <cctype>

#define FOR(i,n) for(long long int i=0; i<n; i++)
#define MP(a,b) make_pair(a,b)
#define PB(x) push_back(x)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())

#define COND(p,t,f) ((p)?(t):(f))

#define PI 3.14159265

using namespace std;
typedef long long int lint;
typedef unsigned long long int ulint;

typedef pair<lint, lint> frac;

lint gcd(lint a, lint b) {
    while (a && b) {
        ((a>b)?a:b) = max(a,b)%min(a,b);
    }
    return max(a,b);
}

frac addFrac(frac a,frac b) {
    frac res;
    res.second = a.second * b.second;
    res.first = a.first * b.second + a.second * b.first;
    lint g = gcd(res.first,res.second);
    res.first /= g;
    res.second /= g;
    return res;
}

frac mulFrac(frac a,frac b) {
    frac res;
    res.second = a.second * b.second;
    res.first = a.first * b.first;
    lint g = gcd(res.first,res.second);
    res.first /= g;
    res.second /= g;
    return res;
}
/*
frac divFrac(frac a, frac b) {

}*/


int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        lint N;
        cin >> N;
        vector <lint> D(N);
        vector <lint> H(N);
        vector <lint> M(N);
        lint total = 0;
        FOR(i,N) {
            cin >> D[i] >> H[i] >> M[i];
            total += H[i];
        }
        if (total==1) {
            cout << "Case #" << t+1 << ": 0" << endl;
            continue;
        }

        lint A = M[0];
        lint B = COND(N==1,A+1,M[1]);

        lint dA = D[0];
        lint dB = COND(N==1,dA,D[1]);

        if (dA < dB) {
            swap(A,B);
            swap(dA,dB);
        }

        /*frac sA,sB;
        sA.first = A;
        sB.first = B;
        sA.second = sB.second = 360;*/
        long double sA = 1.0/A, sB = 1.0/B;
        //cerr << sA << " " << sB << endl;

        lint ret;

        if (sA>sB) {
            double tB = (1 - dB/360.0)*B;
            if (sA*tB>=2-dA/360.0) ret=1;
            else ret=0;
        }
        else {
            double tA = (1 - dA/360.0)*A;
            if (sB*tA >= 2-dB/360.0) ret=1;
            else ret=0;
        }


        cout << "Case #" << t+1 << ": " << ret << endl;
    }

}
