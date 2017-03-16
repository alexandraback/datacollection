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

vector<vector<int> > get_ok(){
    vector<vector<int> > ok(21,vector<int>(21,-1));
    for(int w=1; w<=20; w++){
        for(int c=w; c<=20; c++){
            if(c==w){
                ok[w][c] = w;
            }else if(c-w<w){
                ok[w][c] = w+1;
            }else{
                ok[w][c] = ok[w][c-w]+1;
            }
        }
    }
    return ok;
}

vector<vector<int> > get_ng(){
    vector<vector<int> > ng(21,vector<int>(21,-1));
    for(int w=1; w<=20; w++){
        for(int c=w; c<=20; c++){
            if(c-w<w){
                ng[w][c] = 1;
            }else{
                ng[w][c] = ng[w][c-w]+1;
            }
        }
    }
    return ng;
}

int main(){
    vector<vector<int> > ok = get_ok();
    vector<vector<int> > ng = get_ng();
    int T;
    cin >> T;
    REP(testCase,T){
        int R,C,W;
        cin >> R >> C >> W;
        cout << "Case #" << testCase+1 << ": " << (R-1)*ng[W][C] + ok[W][C] << endl;

    }
    return 0;
}
