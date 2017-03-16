#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "B.in"
#define FILEOUT "B.out"
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int tests;
    cin>>tests;
    for(int _ = 1; _ <= tests; ++_){
    	int A,B,K;
    	cin>>A>>B>>K;
    	int res = 0;
    	for(int i = 0; i < A; ++i){
    		for(int j = 0; j < B; ++j){
    			if((i&j) < K){
    				++res;
    			}
    		}
    	}
        cout<<"Case #"<<_<<": ";
        cout<<res<<endl;
    }
    return 0;
}