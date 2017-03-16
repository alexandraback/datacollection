using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 1005;
int stars [MAXN];
int a [MAXN];
int b [MAXN];


int two(int bal, int n){
    for (int i = 0; i < n; i++){
        if (stars[i] != 2 and bal >= b[i]) return i;
    }
    return -1;
}

int one(int bal, int n){
    int besti = -1;
    int bestb = -1;
    for (int i = 0; i < n; i++){
        if (stars[i] == 0 and bal >= a[i]){
            if (b[i] > bestb){
                besti = i;
                bestb = b[i];
            }
        }
    }
    return besti;
}

int main(){
    int T, run = 1;
    cin >> T;
    while (T--){
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            stars[i] = 0;
        }
        
        int bal = 0;
        int count = 0;
        while (true){
            int big = two(bal, n);
            int small = one(bal, n);
            //printf("Cuando bal = %d, big = %d, small = %d\n", bal, big, small);
            if (big == -1 and small == -1) break;
            
            if (big != -1){
                assert(stars[big] == 0 or stars[big] == 1);
                bal += 2 - stars[big];
                stars[big] = 2; 
            }else{
                assert(stars[small] == 0);
                bal += 1;
                stars[small] = 1;
            }
            count++;
        }
        bool OK = true;
        for (int i = 0; i < n; i++){
            if (stars[i] != 2) OK = false;
        }
        
        if (OK) printf("Case #%d: %d\n", run++, count);
        else printf("Case #%d: Too Bad\n", run++);
    }
    return 0;
}
