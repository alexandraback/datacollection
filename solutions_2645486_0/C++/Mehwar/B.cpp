#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>

#define ull unsigned long long
//#define DEBUG

#define HORIZ 0
#define VERT 1

#define TENpSEVEN 10000000
#define TENpFOUR 10000

using namespace std;


int e, r ,n;
vector<int> values;

int dp[5][10]={{0}};

int recurse (int re, int p){
    int current = 0;


    if(p==n) return 0;

     if(re>e) re = e;

    //if (dp[re][p]) return dp[re][p];



    for(int i = 0;i<=re;i++){
        current = max(current, i * values[p] + recurse(re-i+r, p+1));
    }

    //dp[re][p] = current;

    return current;


}

void init(){
    values.clear();

    for(int i = 0;i<5;i++){
        for(int j = 0;j<10;j++){
            dp[i][j] = 0;
        }
    }

}

int main ()
{

    freopen ("B2.in","r",stdin);
    freopen ("B.out","w",stdout);

    int t; cin>>t;
    for (int _t=0;_t<t;_t++){
        init();
        cin>>e>>r>>n;
        int k;

        for(int i = 0;i<n;i++){
            cin>>k;
            values.push_back(k);
        }



        cout<<"Case #"<<_t+1<<": "<<recurse(e,0)<<endl;


    }

    return 0;
}

