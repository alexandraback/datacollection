#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define hash privet5

using namespace std;

    long long t, n, m, a[55][55];

    bool alpha(long long m){
        long long s = 1;
        for(int i=1; i<n-1; i++) s*=2;
        if(s<m) return false;
        return true;
    }

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int w=0; w<t; w++){
        cin >> n >> m;
        cout << "Case #" << w+1 << ": ";
        for(int i=0; i<n; i++) for(int q=0; q<n; q++) a[i][q] = 0;
        if(!alpha(m)){cout << "IMPOSSIBLE\n"; continue;} else cout << "POSSIBLE\n";
        for(int i=1; i<n-1; i++) for(int q=i+1; q<n; q++) a[i][q] = 1;
        a[0][n-1] = 1;
        m--;
        for(int i=n-2; i>0 && m>0; i--, m/=2) if(m%2 == 1) a[0][i] = 1;
        for(int i=0; i<n; i++) {for(int q=0; q<n; q++) cout << a[i][q]; cout << "\n";}
    }

}
/*
1212121112121124
111212
*/
