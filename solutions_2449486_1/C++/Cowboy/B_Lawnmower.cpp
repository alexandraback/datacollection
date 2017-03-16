/*
 *ID:   Cowboy
 *TASK: B. Lawnmower
 *Judge:Code Jam
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
#define FIL first
#define COL second

int N, M;
//vector< vector<pair<bool, bool> > >valid;
vector< vector<int> >A;

bool marcar( int k, int j ){

    int i;
    for( i=0; i<N; i++){
        if( A[i][j]>A[k][j] )
            break;
    }

    if(i == N)
        return true;

    for( i=0; i<M; i++){
        if( A[k][i]>A[k][j] )
            break;
    }

    if(i == M)
        return true;

    return false;
}

int main( ){
    freopen("B-large.in","r",stdin);
    freopen("solution.out","w",stdout);
    int T;
    cin>>T;
    string res;
    vector<int>menF, menC;

    for(int k=0; k<T; k++) {
        cin>>N>>M;
        A = vector< vector<int> >( N, vector<int>( M ) );
        for( int i = 0; i < N; i++ ){
            for( int j = 0; j < M; j++){
                cin>>A[i][j];
            }
        }
        int i, j;
        for( i = 0; i < N; i++ ) {
            for( j = 0; j < M; j++) {
                //if( A[i][j]==1 ){
                    if( !marcar( i , j) )
                        break;
                //}
            }
            if( j!=M )
                break;
        }
        res = "YES";
        if( i!=N )
            res = "NO";

        printf("Case #%d: ", k+1);cout<<res<<endl;
    }
return 0;
}
