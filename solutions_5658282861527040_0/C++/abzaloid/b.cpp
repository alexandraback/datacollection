#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>

using namespace std;
            
int main () {
	
	freopen ("input.txt", "r", stdin);
 	freopen ("output.txt", "w", stdout);


 	int t;
 	cin >> t;

 	int test = 1;

 	while (t--) {
 		int a, b, k;
 		cin >> a >> b >> k;
	    int cnt = 0;
 		for (int i = 0; i < a; i++)
 			for (int j = 0; j < b; j++) {
 			
 				//cout << i << " " << j << " " << (i & j) << endl;

 				if ((i & j) < k)
 					cnt++;	
 				}
 		printf ("Case #%d: %d\n", test++, cnt);
 	}

	return 0;
}
