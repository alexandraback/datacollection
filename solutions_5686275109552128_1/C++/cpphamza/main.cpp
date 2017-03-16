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

const int SIZE = 1001;
int N, arr[SIZE];

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/B-small-attempt1.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/B-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/B.out", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        cerr << t << endl;
        cin >> N;
        for (int i = 0 ; i < N ; i++)
            cin >> arr[i];
        
        int best = 1000;
        for(int e = 1 ; e <= 1000 ; e++){
            int current = e;
            for(int i = 0 ; i < N ; i++) {
                if (arr[i] <= e)continue;
                current += arr[i]/e;
                if((arr[i]%e) == 0)
                    current --;
            }
            
            best = min(best, current);
        }
        
        cout << "Case #" << t << ": " << best << endl;
    }
    
    return 0;
}

