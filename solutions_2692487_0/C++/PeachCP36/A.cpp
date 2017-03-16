#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define fi first
#define se second

#define FOR(i,j,k) for(typeof((j)) i = (j); i < (k); ++i)
#define FORE(i,j,k) for(typeof((j)) i = (j); i <= (k); ++i)
#define FOREACH(i,j) for(typeof((j.begin())) i = j.begin(); i != (j).end(); ++i)

typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef map<int,int>    mii;
typedef long long int   ll;

int _gcd(int a,int b) { if(b==0)return a; return _gcd(b,a%b);}
inline int gcd(int a,int b) { return (a>=b)?_gcd(a,b):_gcd(b,a); }

int mote[100];

int upSize(int &A, int target){
    int cnt = 0;
    while(A<=target){
        A+=A-1;
        cnt++;
    }
    return cnt;
}

void solve(){
    int A, N;
    scanf("%d%d",&A,&N);
    FOR(i,0,N) scanf("%d",&mote[i]);
    if(A==1){
        printf("%d\n",N);
        return;
    }
    sort(mote,mote+N);
    int answer = 0;
    int answerDel = 9999;
    FOR(i,0,N){
        if(A>mote[i]) A+=mote[i];
        else {
            answerDel = min(answerDel, answer+N-i);
            answer+=upSize(A,mote[i]);
            if(answer>answerDel) break;
            A+=mote[i];
        }
    }
    if(answerDel<answer) printf("%d\n", answerDel);
    else printf("%d\n",answer);
}

int main(){
    freopen("Asmall.in","r",stdin);
    freopen("Asmall.out","w",stdout);
    int _test;
    scanf("%d",&_test);
    FORE(t,1,_test){
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
