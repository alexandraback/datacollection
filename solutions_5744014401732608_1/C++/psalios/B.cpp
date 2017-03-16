#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<assert.h>

const int MAXB = 55;

using namespace std;

typedef long long ull;

int B;
ull M;
int table[MAXB][MAXB];
int used[MAXB];
ull cost[MAXB];

ull calc(int num){

    if( num <= 0 )
        return 0;

    cost[num] = 1;
    ull sum = 1;
    while( num ){
        num--;
        cost[num] = sum;
        sum += cost[num];
    }
    return cost[0];
}

bool solve(){

    memset( used, 0, sizeof used );
    memset( cost, 0, sizeof cost );
    memset( table, 0, sizeof table );

    ull sum = calc(B-1);
    if( sum < M )
        return false;

    int first = -1;
    for(int i=1;i<B;i++){
        if( M >= cost[i] ){
            used[i] = 1;
            M -= cost[i];
            table[0][i] = 1;

            if( first == -1 )
                first = i;
        }else{
            table[0][i] = 0;
        }
    }

    assert( M == 0 );

    for(int i=1;i<B;i++)
        for(int j=0;j<B;j++)
            if( j<=i || (first>i))
                table[i][j] = 0;
            else
                table[i][j] = 1;

    return true;

}

int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int T; cin>>T;
    for(int t=1;t<=T;t++){
        cin>>B>>M;
        cout<<"Case #"<<t<<": ";
        bool ok = solve();
        if( !ok )
            cout<<"IMPOSSIBLE\n";
        else{
            cout<<"POSSIBLE\n";
            for(int i=0;i<B;i++){
                for(int j=0;j<B;j++)
                    cout<<table[i][j];
                cout<<'\n';
            }
        }
    }

	return 0;
}
