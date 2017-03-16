#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <vector>

#define mp make_pair
#define ll long long
#define pb push_back

using namespace std;

int main() {
    
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n,k,xx;
        cin >> n >> k >> xx;
        //n^k
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < n; j++) {
            long long x = 1;
            long long sum = 0;
            for (int l = 0; l < k; l++) {
                sum += x*j;
                x = x*n;
            }
            
            cout << sum+1 << " ";            
        }
        cout << "\n";
        
        
    }
    
   
    return 0;
}