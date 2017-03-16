#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _T;
    cin >> _T;
    for(int T = 0; T < _T; T++){
        int n;
        cin >> n;
        int freq[n+1];
        for(int i = 0; i < n+1; i++){
            char c;
            cin >> c;
            freq[i] = c - '0';
        }
        int ans = 0, cur = 0;
        for(int i = 0; i < n+1; i++){
            while(cur < i){
                ans++;
                cur++;
            }
            cur += freq[i];
        }
        cout << "Case #" << T+1<< ": " << ans << "\n";
    }
    return 0;
}
