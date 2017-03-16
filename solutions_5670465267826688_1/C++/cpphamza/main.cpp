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

const int SIZE = 2000001;
big L, X, N;
pair<char, int> leftArr[SIZE], rightArr[SIZE];

pair<char, int> f(pair<char, int> x, pair<char, int> y) {
    
    pair<char, int> res;
    res.second = x.second * y.second;
    
    if(x.first == y.first) {
        res.first = '1';
        res.second *= x.first == '1' ? 1 : -1;
    } else if(x.first == '1') {
        res.first = y.first;
    } else if (y.first == '1') {
        res.first = x.first;
    } else if (x.first == 'i' && y.first == 'j') {
        res.first = 'k';
    } else if (x.first == 'i' && y.first == 'k') {
        res.first = 'j';
        res.second *= -1;
    } else if (x.first == 'j' && y.first == 'i') {
        res.first = 'k';
        res.second *= -1;
    } else if (x.first == 'j' && y.first == 'k') {
        res.first = 'i';
    } else if (x.first == 'k' && y.first == 'i') {
        res.first = 'j';
    } else if (x.first == 'k' && y.first == 'j') {
        res.first = 'i';
        res.second *= -1;
    }
    return res;
}

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/C-small-attempt0.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/C-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/C.out", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        cin >> L >> X;
        cerr << t << " " << L << " " << X << endl;
        if (X >= 100)
            X %= 100;
        cerr << X << endl;
        string s; cin >> s;
        string str = "";
        for (int i = 0 ; i < X ; i++)
            str += s;
        
        N = L*X;
        leftArr[0] = make_pair(str[0], 1);
        rightArr[N-1] = make_pair(str[N-1], 1);
        
        for (int i = 1 ; i < N ; i++)
            leftArr[i] = f(leftArr[i-1], make_pair(str[i], 1));
        for (int i = N-2 ; i >= 0 ; i--)
            rightArr[i] = f(make_pair(str[i], 1), rightArr[i+1]);
        
        int kidx = -1;
        for(int i = N-1 ; i >= 0 ; i--)
            if(rightArr[i] == make_pair('k', 1)) {
                kidx = i;
                break;
            }
        
        bool ok = false;
        for (int i = kidx - 1 ; i >= 1 ; i--) {
            if (rightArr[i] == make_pair('i', 1) && leftArr[i-1] == make_pair('i', 1)){
                ok = true;
                break;
            }
        }
        
        cout << "Case #" << t << ": " << (ok?"YES":"NO") << endl;
    }
    
    return 0;
}

