#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <math.h>
using namespace std;



int guess[10];
int maxP[10];

int prob[100];

int getProb(int a, int b, int c, int K = 7)
{

    int ret = 0;
    for(int i=0; i<K; ++i){
        if(guess[i] == a) ret++;
        if(guess[i] == b) ret++;
        if(guess[i] == c) ret++;
        if(guess[i] == a*b) ret++;
        if(guess[i] == b*c) ret++;
        if(guess[i] == a*c) ret++;
        if(guess[i] == a*b*c) ret++;
    }

    //cout << a << b << c << " " << ret << endl;
    return ret;
}

void solve(int K=7, int N=3, int M=5)
{
    int maxT = -1;
    for(int i=2; i<=M; ++i)
    for(int j=i; j<=M; ++j)
    for(int k=j; k<=M; ++k){
        int t = getProb(i, j, k, K);
        int cnt = 1;
        if(i!=j) {
            cnt++;
            if(k!=j) cnt++;
        }
        else{
            if(k!=j) cnt++;
        }

        if(cnt==2) cnt = 3;
        else if(cnt==3) cnt = 6;

        if(t*cnt > maxT){
            maxT = t*cnt;
            maxP[0] = i;
            maxP[1] = j;
            maxP[2] = k;
        }
    }
}

int main()
{
    int T;
    //ull r, t;
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    cin>>T;
    int R,N,M,K;
    for(int ca=1; ca<=T; ++ca){
        cin>>R>>N>>M>>K;
        cout << "Case #1:" << endl;
        for(int i=0; i<R; ++i){
            for(int j=0; j<K; ++j)
            cin>>guess[j];

            solve(K,N,M);
            for(int j=0; j<N; ++j)
            cout << maxP[j];
            cout << endl;
        }
        //cout << "Case #" << ca << ": "<< ans << endl;
    }
    return 0;
}
