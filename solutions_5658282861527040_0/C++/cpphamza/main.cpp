//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<cassert>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int A, B, K;

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/B-small-attempt0.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/A-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out", "wt", stdout);

    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        
        cin >> A >> B >> K;
        cerr << t << endl;
        
        int res = 0;
        for(int i = 0 ; i < A ; i++)
            for(int j = 0 ; j < B ; j++)
                res += (i&j) < K;
        
        cout << "Case #" << t << ": " << res << endl;
    }
    
    return 0;
}

