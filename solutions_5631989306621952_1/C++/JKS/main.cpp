#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include "prettyprint.h"
#include <deque>
#include <fstream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define M_PI 3.14159265358979323846
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define LD long double
#define INF 1000000000
#define int long long
//Begin of the code
#undef int
int main() {
#define int long long
    int t;
    cin>>t;
    REP(q,t){
        string s;
        cin>>s;
        deque<char> b;

        REP(i, s.size()){
            deque<char> c = b;
            deque<char> d = b;
            c.PB(s[i]);
            d.push_front(s[i]);
            if(c < d){
                b = d;
            } else{
                b = c;
            }
        }
        string s1;
        REP(i, s.size()){
            s1.PB(b[i]);
        }

        cout<<"Case #"<<q + 1<<": "<<s1<<endl;
    }

    return 0;
}
