
#include <iostream>
#include <istream>
#include <stdio.h>
#include <string>
#include <vector> 
#include <fstream>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define BIG 1000000007

using namespace std; 

int main ()
{
    freopen ("D-large (1).in", "r", stdin);
	freopen ("D.out", "w", stdout); 
 	int tt; 
 	cin >> tt; 
 	for (int cases = 1; cases <= tt; cases++)
 	{
 		cout << "Case #" << cases << ": ";
 		int x, r, c, temp;
 		cin >> x >> r >> c;
		temp = min (r, c); 
		c = max(r, c); 
		r = temp; 
		if ((x >= 2*r && (x != 2 || r != 1)) || (r*c)%x != 0 || x > c || (x >= 5 && x == 2*r-1))
			cout << "RICHARD\n";
		else
			cout << "GABRIEL\n";
	}
}
