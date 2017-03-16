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

big table[30][2][2][2];
big get(int i, int eq0, int eq1, int eq2){
    
    if(i < 0)
        return 1;
    if(table[i][eq0][eq1][eq2] != -1)
        return table[i][eq0][eq1][eq2];
    
    big res = 0;
    
    int bita = (A>>i)&1;
    int bitb = (B>>i)&1;
    int bitk = (K>>i)&1;

    int au = eq0 ? bita : 1;
    int bu = eq1 ? bitb : 1;
    int ku = eq2 ? bitk : 1;
    
    for(int a = 0 ; a <= au ; a++)
        for(int b = 0 ; b <= bu ; b++){
            int c = a&b;
            if(c <= ku)
                res += get(i-1, eq0&(a==au), eq1&(b==bu), eq2&(c==ku));
        }
    
    return table[i][eq0][eq1][eq2] = res;
}

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/B-small-attempt0.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/B-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        
        cin >> A >> B >> K;
        A--; B--; K--;
        cerr << t << endl;
        
        memset(table, -1, sizeof table);
        big r1 = get(29, 1, 1, 1);
        cout << "Case #" << t << ": " << r1 << endl;
    }
    
    return 0;
}

