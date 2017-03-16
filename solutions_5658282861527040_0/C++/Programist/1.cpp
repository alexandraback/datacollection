#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>
#include <time.h>
#include <iterator>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

int main(){
	ifstream cin("B-small-attempt0 (2).in");
	ofstream cout("ans.txt");
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {		
		int a, b, k, ans = 0;
		cin >> a >> b >> k;

		for(int i=0; i<a; i++)
			for(int j=0; j<b; j++)
				if((i & j) < k) ans++;

		cout << "Case #" << t << ": ";
		cout << ans << endl;
	}
    return 0;
}
 