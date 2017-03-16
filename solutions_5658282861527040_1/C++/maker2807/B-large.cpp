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


string toString(ulint n) {
    string r;
    FOR(i,30) {
        r.PB(COND(n&(1<<(30-i-1)),'1','0'));
    }
    return r;
}

vector<string> gr(string s) {
    vector <string> res;
    string r="";
    string X ="XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    FOR(i,30) {
        if (s[i]=='1') {
            res.PB(r+"0"+X);
        }
        r.PB(s[i]);
    }
    FOR(i,res.size()) {
        res[i].resize(30);
    }

    return res;
}


int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        ulint A,B,K;
        cin >> A >> B >> K;
        //cerr << toString(A) << endl;
        string sA = toString(A);
        string sB = toString(B);
        string sK = toString(K);

        vector<string> vA = gr(sA);
        vector<string> vB = gr(sB);
        vector<string> vK = gr(sK);

        //FOR(i,vA.size()) cerr << vA[i] << endl;

        ulint res = 0;

        FOR(i, vA.size()) {
            string mA = vA[i];
            FOR(j, vB.size()) {
                string mB = vB[j];
                FOR(k, vK.size()) {
                    string mK = vK[k];
                    ulint r=1;

                    FOR(p,30) {
                        ulint cnt=0;
                        FOR(aa,2) {
                            FOR(bb,2) {
                                if(mA[p]!='X' && aa!=mA[p]-'0') continue;
                                if(mB[p]!='X' && bb!=mB[p]-'0') continue;
                                ulint kk = aa&bb;
                                if(mK[p]!='X' && kk!=mK[p]-'0') continue;
                                cnt++;

                            }
                        }
                        r*=cnt;
                    }
                    res+=r;
                }
            }
        }
        cout << "Case #" << t+1 << ": ";
        cout << res << endl;
    }

}
