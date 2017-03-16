#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const int INF=1000000000;
typedef pair<int,int> Point;
#define x first
#define y second

string str(const string& s) { return s; }

string str(int x) {
    ostringstream ss;
    ss<<x;
    return ss.str();
}

template<typename T>
string str(const T& v) {
    ostringstream ss;
    ss<<"[";
    FOREACH(x,v) ss<<str(*x)<<",";
    ss<<"]";
    return ss.str();
}



int main() 
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    REP(_t,T) {
        int A, B, K;
        cin>>A>>B>>K;
        int cnt=0;
        REP(a, A) REP(b, B)
            if((a&b)<K) cnt++;
        
        cout<<"Case #"<<_t+1<<": "<<cnt<<endl;
    }
    
}