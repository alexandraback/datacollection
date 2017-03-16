#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <cmath>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <stack>
#include <list>
using namespace std;

typedef long long LL;
int T;

LL finala,finalb,minn;
string sfinala,sfinalb;

LL parseStringToLL(const string &s) {
    LL ret = 0;
    for(size_t i = 0 ; i < s.size();i++ ) {
        ret = ret*10+(s[i]-'0');
    }
    return ret;
}

void solve(string a,string b,int i,int type) {
    //cout << "a=" << a << ",b=" << b << ",i=" << i << ",type=" << type << endl;
    //getchar();
    if( i >= a.size() ){
        LL tfa = parseStringToLL(a);
        LL tfb = parseStringToLL(b);
        LL tmn = abs(tfa-tfb);
        //sfinala = a;
        //sfinalb = b;
        if( tmn < minn ) {
            minn = tmn;
            finala = tfa;
            finalb = tfb;
            sfinala = a;
            sfinalb = b;
        }
        else if( tmn == minn ) {
            if( tfa < finala ) {
                minn = tmn;
                finala = tfa;
                finalb = tfb;
                sfinala = a;
                sfinalb = b;
            }
            else if( tfa == finala ) {
                if( tfb < finalb ) {
                    minn = tmn;
                    finala = tfa;
                    finalb = tfb;
                    sfinala = a;
                    sfinalb = b;
                }
            }
        }
        return;
    }
    if( a[i] == '?' && b[i] == '?' ) {
        //cout << "both" << endl;
        if( type == 0 ) {
            a[i] = '0'; b[i] = '0'; solve(a,b,i+1,0);
            a[i] = '1'; b[i] = '0'; solve(a,b,i+1,1);
            a[i] = '0'; b[i] = '1'; solve(a,b,i+1,2);
        }
        if( type == 1 ){
            a[i] = '0'; b[i] = '9'; solve(a,b,i+1,1);
        }
        if( type == 2 ) {
            a[i] = '9'; b[i] = '0'; solve(a,b,i+1,2);
        }
        a[i] = '?';
        b[i] = '?';
        return;
    }
    if( a[i] == '?' && b[i] != '?' ) {
        //cout << "a == ?" << endl;
        char aa = a[i] , bb = b[i];
        if( type == 0 ){
            a[i] = b[i]; solve(a,b,i+1,0);
            if( b[i] != '9' ) a[i] = b[i] + 1; solve(a,b,i+1,1);
            if( b[i] != '0' ) a[i] = b[i] - 1; solve(a,b,i+1,2);
        }
        if( type == 1 ) {
            a[i] = '0'; solve(a,b,i+1,1);
        }
        if( type == 2) {
            a[i] = '9'; solve(a,b,i+1,2);
        }
        a[i] = aa; b[i] = bb;
        return;
    }
    if( a[i] != '?' && b[i] == '?' ) {
        //cout << "b == ?" << endl;
        char aa = a[i] , bb = b[i];
        if( type == 0 ) {
            b[i] = a[i]; solve(a,b,i+1,0);
            if( a[i] != '0' ) b[i] = a[i] - 1; solve(a,b,i+1,1);
            if( a[i] != '9' ) b[i] = a[i] + 1; solve(a,b,i+1,2);
        }
        if( type == 1 ) {
            b[i] = '9'; solve(a,b,i+1,1);
        }
        if( type == 2 ) {
            b[i] = '0'; solve(a,b,i+1,2);
        }
        a[i] = aa; b[i] = bb;
        return;
    }
    if( a[i] != '?' && b[i] != '?' ) {
        //cout << "neither" << endl;
        if( a[i] > b[i] && type == 0 ) solve(a,b,i+1,1);
        else if( a[i] < b[i] && type == 0) solve(a,b,i+1,2);
        else solve(a,b,i+1,type);
        return;
    }
}

int main() {
    cin >> T;
    int cases = 1;
    while( T-- ) {
        string a,b;
        cin >> a >> b;
        string ta(a), tb(b);
        int n = a.size();
        for(int i = 0 ; i < n ; i++ ) {
            if(a[i] == '?' && b[i] != '?' ) a[i] = b[i];
            if(a[i] != '?' && b[i] == '?' ) b[i] = a[i];
            if(a[i] == '?' && b[i] == '?' ) {a[i] = '0' ; b[i] = '0';}
        }
        finala = parseStringToLL(a);
        finalb = parseStringToLL(b);
        minn = abs(finala - finalb);
        sfinala = a;
        sfinalb = b;
        solve(ta,tb,0,0);
        cout << "Case #"<< cases++ << ": "<< sfinala <<" "<< sfinalb << "" << endl;
    }
    return 0;
}