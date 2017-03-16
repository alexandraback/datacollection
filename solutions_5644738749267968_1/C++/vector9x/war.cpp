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

int N;

int war(set<float> A, set<float> B)
{
    int points = 0;
    FOREACH(x,A) {
        set<float>::iterator it = upper_bound(ALL(B),*x);
        if(it==B.end()) {
            points++;
            B.erase(B.begin());
        }
        else {
            B.erase(it);
        }
    }
    return points;
}

int deceitful(set<float> A, set<float> B)
{
    int points=N;
    FOREACH(x,A) {
        if(*x<*B.begin()) {
            points--;
            B.erase(--B.end());
        }
        else {
            B.erase(B.begin());
        }
    }
    return points;
}

int main() 
{
    ios_base::sync_with_stdio(false);

    int T; cin>>T;
    REP(_t,T) {
        set<float> A,B;
        cin>>N;
        
        REP(i,N) {
            float x; cin>>x;
            A.insert(x);
        }

        REP(i,N) {
            float x; cin>>x;
            B.insert(x);
        }
        
        
        cout<<"Case #"<<_t+1<<": "<<deceitful(A,B)<<" "<<war(A,B)<<endl;


    }
}