#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vstr;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int,int> mii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

//container util
#define RANGE(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
/******* All Required define Pre-Processors and typedef Constants *******/
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back




template<class T> inline void READARR(T& arr, uint64 N) {
    FOR(i,0,N){
        cin >> arr[i];
    }
}
template<class T> inline void READVEC(vector<T>& vec, uint64 N) {
    FOR(i,0,N){
        T a;
        cin >> a;
        vec.push_back(a);
    }
}



int main(int argc, char *args[]) {
        freopen("/Users/Hikaru/Downloads/B-small-attempt3.in","rt",stdin);
        freopen("/Users/Hikaru/Desktop/B-small.out","wt",stdout);
    
    const int MAXLEN = 100;
    int T;
    cin >> T;
    FOR(caseNum,1,T+1){
        int K, L, S;
        cin >> K >> L >> S;
        string keys;
        cin >> keys;
        string target;
        cin >> target;
        
        int keytimes[26];
        FOR(i,0,26){
            keytimes[i] = 0;
        }
        
        for(auto k : keys){
            keytimes[k-'A']++;
        }

        int T = target.length();
        FOR(i,1,target.length()+1){
            bool foundperiod = true;
            for(int j = 0; j < target.length(); j += i){
                dump(target.substr(0,i) != target.substr(j,i))
                if(target.substr(0,i) != target.substr(j,i)){
                    foundperiod = false;
                    break;
                }
                if (foundperiod){
                    T = i;
                }
            }
            if(foundperiod)
                break;
        }
        dump(T)

        // keycheck
        bool a = false;
        for(auto c : target){
            if (!keytimes[c - 'A']){
                a = true;
                break;
            }
        }
        if(a){
            printf("Case #%d: 0.0\n", caseNum);
            continue;
        }
        
        double w = 1.0;
        for(auto c : target){
            w *= keytimes[c - 'A'] / (double) keys.length();
        }
        
        double p[S];
        FOR(i,0,S){
            p[i] = keytimes[target[i] - 'A'] / (double) keys.length();
        }
        
        double E[MAXLEN+1][MAXLEN+1][MAXLEN+1];
        for(int s = 1; s <= MAXLEN; s++){
            for(int l = 1; l <= MAXLEN; l++){
                for(int t = 1; t <= MAXLEN; t++){
                    E[s][l][t] = 0.0;
                }
            }
        }
        for(int s = 1; s <= MAXLEN; s++){
            for(int l = 1; l <= s; l++){
                for(int t = 1; t <= s; t++){
                    E[s][l][t] = w * ((t >= T ? 1: 0) + E[s-l][l][t+1]);
                    for(int i=1; i<=target.length(); i++){
                        if(i > s) break;
                        double a = 1.0;
                        for(int j=1; j<= i-1; j++){
                            a *= p[j-1];
                        }
                        a *= 1 - p[i-1];
                        E[s][l][t] += a * E[s-i][l][0];
                    }
                }
            }
        }
        double ans = 0;
        for(int t = 1; t <= MAXLEN; t++){
            ans += E[S][L][t];
        }
        printf("Case #%d: %lf\n", caseNum, ans);
    }
}
