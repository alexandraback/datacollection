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

int N;

int main() {
    
//    freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/A-small-attempt0.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/A-large.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/1.out", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        
        string s;
        cin >> N >> s;
        cerr << t << " " << N << " " << s << endl;
        
        int req = 0, a = s[0]-'0';
        for (int i = 1 ; i < s.size() ; i++){
            if(s[i] > '0' && i > a) {
                int d = i-a;
                req += d;
                a += d;
            }
            a += s[i]-'0';
        }
        
        
        cout << "Case #" << t << ": " << req << endl;
    }
    
    return 0;
}

