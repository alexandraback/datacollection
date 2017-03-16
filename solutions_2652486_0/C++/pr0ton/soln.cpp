#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;

int R, N, M, K;
int digs[16];
int ip[16];
bool seen[16];
bool found = 0;
void go(int k) {
    if (found) return;
    if (k == N) {
        int X = 0;
        for (int f=0; f < N; f++) {
            // cout << digs[f];
            X = X * 10 + digs[f];
        }
        // cout << endl;
        fill(seen, 0);
        for (int mask=0; mask < (1<<N); mask++) {
            
            int cprod = 1;
            
            for (int f=0; f < N; f++)
            if (mask & 1<<f) {
                cprod *= digs[f];
            }
            // cout << X << " " << mask << " = " << cprod << endl;
            
            for (int f=0; f < K; f++)
            if (ip[f] == cprod) {
                seen[f] = true; 
            }
        }
        for (int f=0; f < K; f++) 
        if (!seen[f]) {
            return;
        }
        found = 1;
        for (int f=0; f < N; f++)
            cout << digs[f] ;
        cout << endl;
        return;
    } else {
        vector<int> x(M - 2 + 1);
        for (int j=0, i=2; j < x.size(); j++, i++) {
            x[j] = i;
        }
        
        for (int i=0; i < x.size(); i++) {
            digs[k] = x[i];
            go(k+1);
        }
    }
} 

int main() {
    int runs; s(runs);
    for (int T=1; T <= runs; T++) {
        cout << "Case #" << T << ":" << endl;
        cin>>R>>N>>M>>K;
        for (int i=0; i < R; i++) {
            for (int j=0; j < K; j++) s(ip[j]);
            found = 0;
            go(0);
        }
    }
}
