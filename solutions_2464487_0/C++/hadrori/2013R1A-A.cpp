#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

int n;//num of test case

ll rad;
ll t;

using namespace std;

int main(){
    cin >> n;
    rep(k,0,n){
        cin >> rad >> t;
        ll m = 1;
        while( m * (2 * m + 2 * rad -1) <= t)m++;
        cout << "Case #" << k+1 << ": " << m-1 << endl;
    }
}


/*
are = r^2
1 area[1] = (r+1)^2 - r^2
2 area[2] = (r+3)^2 - (r+2)^2

sum area[1:m] = (r+m)^2 - 

*/