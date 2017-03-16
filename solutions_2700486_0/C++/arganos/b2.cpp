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
#include <iomanip>


#define ll long long

using namespace std;
int x, y, n, t;


long long bino(int n, int p) {
    long long res = 1;
    
    for (int i = n; i >= n-p+1; i--)
        res *= i;
    for (int i = 1; i <= p; i++)
        res /= i;
   // cout << res << endl;
    return res;
}


double prob(int n, int p) {
    if (n <= p)
        return 0.0;
    long long res = 0;
    for (int i = p;  i <= n; i++)
        res +=  bino(n, i);
    //cout << res << endl;
    return res / pow(2.0, n);
    
}


int main() {
	cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> x >> y;
        //cnt = cnttot = 0;
        
        int level = 0, blocks = 0;
        for (; blocks <= n; level++) {
            blocks += 1 + 4*level;
        }
        blocks -= 1+4*(level-1);
        level--;
        n -= blocks;
        
       // cout << n << " "<<blocks << " " << level << endl;
        
        
        int border = 2*(level -1);
        //cout << "boarder" << border<<" " << x << " " << y  << endl;
        if ((x+y <= border) || ((abs(y-x) <= border) && (x < 0)) ) {
            cout << "Case #" << i << ": 1.0"  << endl;
            continue;
        } else if ((x+y == border +2) || ((abs(y-x) == border+2) && (x < 0)) ) {
            int r = abs(2*level-x)+1;
            //cout << "r = " << r << endl;
             std::cout << std::fixed;
         cout << std::setprecision(7)<< "Case #" << i << ": " << prob(n, r)  << endl;
            
        } else {
            cout << "Case #" << i << ": 0.0"  << endl;
        }
            
    } 

	return 0;
}

