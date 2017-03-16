#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define ff first
#define ss second 
#define lli long long int
lli power(lli a, lli b) {
    lli val = 1, tmp = a;
    while (b) {
        if (b&1) val = val*tmp;
        tmp *= tmp;
        b /= 2;
    }
    return val;
}
int main() {
        
    ios::sync_with_stdio(false);
    
    //clock_t start = std::clock();
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    //cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    int t,ca = 1;
    cin >> t;

    while (t--) {
        cout << "Case #" << ca << ": ";
        ca++;
        lli k,c,s;
        cin >> k >> c >> s;
        
        if (s == k) {
            for (lli i = 1; i <= s; i++) {
                lli tmp = i;
                for (lli j = 2; j <= c; j++) {
                    tmp = (tmp-1)*k + i;
                }
                cout << tmp << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
        
}