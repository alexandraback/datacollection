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
        string s;
        cin >> s;
        if (s[0] == '-') {
            int d = 1;
            for (int i = 1; i < s.length(); i++) {
                if (s[i] != s[i-1])
                    d++;
            }
            if (d%2 == 0) d--;
            cout << d << endl;
        } else {
            int d = 1;
            for (int i = 1; i < s.length(); i++) {
                if (s[i] != s[i-1])
                    d++;
            }
            if (d&1) d--;
            cout << d << endl;
        }
    }
    
    return 0;
        
}