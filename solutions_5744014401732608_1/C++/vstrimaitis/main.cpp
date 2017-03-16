#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <climits>
#include <set>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<double, double> pdd;

#define PI 3.1415926535897932384626433
#define INF ((1<<30)-1)*2+1
#define mp(a, b) make_pair((a), (b))
#define pb push_back
#define MOD 1000000007
#define MAX_N 10000
#define MAX_B 50
using namespace std;

ll numOfWays[MAX_B];

bool possible(ll b, ll m){
    ll res = 1;
    for(int i = 0; i < b-2; i++)
        res *= 2;
    if(m <= res)
        return true;
    return false;
}

void init(){
    numOfWays[0] = numOfWays[1] = 1;
    for(int i = 2; i < 50; i++)
        numOfWays[i] = numOfWays[i-1] * 2;
}

void solve(ll b, ll m){
    int ind = 0;
    bool matrix[MAX_B][MAX_B] = {false};
    if(b <= 3){
        if(m == 1)
            matrix[0][b-1] = true;
        else if(m == 2)
            matrix[0][b-1] = matrix[1][b-1] = matrix[0][1] = true;
        for(int i = 0; i < b; i++){
            for(int j = 0; j < b; j++)
                cout << matrix[i][j];
            cout << endl;
        }
        return ;
    }

    for(int i = 0; i < b-1; i++){
        for(int j = 0; j < i; j++){
            matrix[j][i] = true;
        }
    }

    m *= 2;
    m--;

    while(m > 0){
        if(m%2)
            matrix[ind][b-1] = true;
        ind++;
        m /= 2;
    }
    for(int i = 0; i < b; i++){
        for(int j = 0; j < b; j++)
            cout << matrix[i][j];
        cout << endl;
    }
}

int main()
{
    freopen("../B-large.in","r",stdin);
    freopen("output.txt", "w", stdout);
    init();
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        ll B, M;
        cin >> B >> M;
        cout << "Case #" << t << ": ";
        if(!possible(B, M)){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "POSSIBLE" << endl;
        solve(B, M);
    }
    return 0;
}
