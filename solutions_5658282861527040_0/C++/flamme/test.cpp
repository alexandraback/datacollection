#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int a, b, k;
		cin >> a >> b >> k;
		int r = 0;
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				int temp = i & j;
				if(temp < k){
					r++;
				}
			}
		}
		cout << "Case #" << tt << ": " << r;
		cout << endl;
	}
	return 0;
}