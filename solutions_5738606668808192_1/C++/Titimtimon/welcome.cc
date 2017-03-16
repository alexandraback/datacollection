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
    
//    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cout << "Case #1:\n";
    int cnt = 0;
   
    for (int i = 0; i < 10000; i++) 
        if (i%2 == 1)
    {
            int cnt0 = 1;
            int cnt1 = 0;
            for (int j = 0; j < 20; j++)
                if ((i & (1<<j)) > 0) {
                    if (j%2 == 0) cnt1++; else cnt0++;
                }
            if (cnt0 == cnt1) {
                for (int j = 31; j >= 0; j--) {
                    if (j == 31) cout << 1; else
                    cout << ((i&(1<<j))>0);
                }
                cout << " ";
                for (int i = 3; i <= 11; i++)
                    cout << i << " ";
                cout << "\n";
                cnt++;
                if (cnt == 500) return 0;
//                cout << i << " " << cnt0 << " " << cnt1 << "\n";
            }
            

    }
   
    return 0;
} 