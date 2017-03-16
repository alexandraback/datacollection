/*
ID: enggi231
LANG: C++
PROG: 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

fstream out;
int t, a, n, b[100];


int minNeeded(int m) {
    int op = 0, aa = a;
    
    for (int i = 0; i < m; i++) {
        if (aa <= b[i]) {
            op++;
            if (aa -1 == 0)
                return 600;
            aa += aa-1;
            
            i--;
            continue;
        }
        aa += b[i];
    }
    return op;
}

int main()
{
	cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> n;
        for (int j = 0; j < n; j++)
            cin >> b[j];
        
        sort (b, b+n);
        int mn = 123456;
        for (int j = n; j >= 0; j--)
            if (minNeeded(j) + n-j < mn)
                mn = minNeeded(j)+ n-j;
        
        cout << "Case #" << i <<": " << mn << endl;
    }
    
	return 0;
}

