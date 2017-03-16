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

typedef pair<string,string> P;
int T,N;
map<string,int> cntA,cntB;
map<string,int> cntImpA,cntImpB;
set<P> impossible;

int main() {
    int cases = 1;
    cin >> T;
    while( T-- ) {
        cin >> N;
        P in;
        vector<P> vec;
        cntA.clear();
        cntB.clear();
        cntImpA.clear();
        cntImpB.clear();
        impossible.clear();
        for(int i = 0 ; i < N ; i++ ) {
            cin >> in.first >> in.second;
            vec.push_back(in);
            cntA[in.first]++;
            cntB[in.second]++;
        }
        for(auto &a: cntA) {
            if( a.second == 1 ) {
                for(int i = 0 ; i < vec.size();i ++ ) {
                    if( a.first == vec[i].first ) {
                        impossible.insert(vec[i]);
                        cntImpA[vec[i].first]++;
                        cntImpB[vec[i].second]++;
                    }
                }
                for(int i = 0 ; i < vec.size();i++ ) {
                    if( a.first == vec[i].second ) {
                        impossible.insert(vec[i]);
                        cntImpA[vec[i].first]++;
                        cntImpB[vec[i].second]++;
                        break;
                    }
                }
            }
        }
        for(auto &b: cntB) {
            if( b.second == 1 ){
                for(int i = 0 ; i < vec.size();i++ ) {
                    if( b.first == vec[i].second) {
                        impossible.insert(vec[i]);
                        cntImpA[vec[i].first]++;
                        cntImpB[vec[i].second]++;
                    }
                }
                for(int i = 0 ; i < vec.size();i++ ) {
                    if( b.first == vec[i].first ) {
                        impossible.insert(vec[i]);
                        cntImpA[vec[i].first]++;
                        cntImpB[vec[i].second]++;
                        break;
                    }
                }
            }
        }
        for(int i = 0 ; i < vec.size();i ++ ) {
            if( impossible.find(vec[i]) == impossible.end() ) {
                string &A = vec[i].first;
                string &B = vec[i].second;
                if( cntImpA.find(A) == cntImpA.end() || cntImpB.find(B) == cntImpB.end() ) {
                    impossible.insert(vec[i]);
                    cntImpA[vec[i].first]++;
                    cntImpB[vec[i].second]++;
                }
            }
        }
        cout << "Case #"<< cases++ << ": "<< N - impossible.size()<< "" << endl;
    }
    return 0;
}