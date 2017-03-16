/*
 *ID:   Cowboy
 *TASK: Manage your Energy Problem B
 *Judge:CodeJam
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#define INF 2000000000
#define PI 2*acos(0.0)
using namespace std;

#define PB(t) push_back(t)
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
int T, E, R, N;
vector<int>v;
vector< vector<int> >memo;

long long solve( int idx , int ene){
    long long res = 0;
    if( idx>=N )
        return res;

    if( memo[idx][ene] != 0 ){
        //cout<<"aca "<<idx<<" "<<ene<<" . "<<memo[idx][ene]<<endl;
        return memo[idx][ene];
    }

    for( int i=0; i <= ene ; i++){
        res=max(res, solve(idx+1, min(ene-i+R, E) )+v[idx]*i );
        //cout<<"**"<<idx<<"_"<<ene<<" "<<i<<" "<<res<<endl;
    }

    return memo[idx][ene] = res;
}

int main( ){
    freopen("B-small.in","r",stdin);
    freopen("solution.out","w",stdout);
    cin>>T;
    for(int k=0; k<T; k++){
        cin>>E>>R>>N;
        v = vector<int>(N);
        memo = vector< vector<int> >(12, vector<int>(12, 0));
        for(int i=0; i<N; i++){
            cin>>v[i];
        }

        cout<<"Case #"<<k+1
            <<": "<<solve(0, E)<<endl;
    }
return 0;
}
