#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

struct Q{
    int r,i,j,k;

    Q(char c = 'r'){
        r = i = j = k = 0;
        if(c=='i')i = 1;
        else if(c=='j')j = 1;
        else if(c=='k')k = 1;
        else r = 1;
    }

    void multiply(const Q &o){
        int _r = r*o.r - i*o.i - j*o.j - k*o.k;
        int _i = r*o.i + i*o.r + j*o.k - k*o.j;
        int _j = r*o.j - i*o.k + j*o.r + k*o.i;
        int _k = r*o.k + i*o.j - j*o.i + k*o.r;
        r = _r;
        i = _i;
        j = _j;
        k = _k;
    }

    void output(){
        cout << r << " " << i << " "<< j << " " << k << endl;
    }



};

Q q_pow(Q a, LL b){
    Q c('r');
    while(b>0){
        if(b&1LL)c.multiply(a);
        a.multiply(a);
        b >>= 1;
    }
    return c;
}

bool solve(const string &S, const LL X){
    if(set<char>(S.begin(), S.end()).size()==1)return false;
    Q q('r');
    Q b('r');

    REP(i, S.size())b.multiply(Q(S[i]));

    char reqire = 'i';

    for(LL x=0; x<X; x++){
        if(reqire=='k'){
            q.multiply(q_pow(b, X-x));
            break;
        }
        REP(i,S.size()){
            //cout << "reqire:" << reqire <<  "------------" << endl;
            q.multiply(Q(S[i]));
            //q.output();
            if(reqire=='i' && q.i != 0){
                reqire = 'j';
                swap(q.r, q.i);
            }
            if(reqire=='j' && q.j != 0){
                reqire = 'k';
                swap(q.r, q.j);
            }
            //q.output();
        }
    }
    if(reqire=='k' && q.k == 1){
        reqire = 0;
    }
    //cout << endl << reqire << endl;
    return reqire == 0;
}

int main(){
    int T;
    cin >> T;
    REP(testCase, T){
        int L;
        LL X;
        string S;
        cin >> L >> X >> S;
        bool ans = solve(S,X);
        cout << "Case #" << testCase+1 << ": " << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
