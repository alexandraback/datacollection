#pragma comment(linker, "/STACK:65777216")
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <stdio.h>
#include <deque>
#include <map>
#include <set>
#include <stack>
  
using namespace std;
  
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
  
typedef long long li;
typedef unsigned long long uli;

li nod(li a, li b){
	if(a > b) swap(a, b);
	if(a == 0) return b;
	else
		return nod(b % a, a);
}

int main(){
	freopen("A-small-attempt0 (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	//cout.setf(ios::fixed);
	//cout.precision(7);
	li t;
	cin >> t;
	li z;
	for(z = 0; z < t; z++){
		li p, q;
		char c;
		cin >> p >> c >> q;
		li h = nod(p, q);
		p = p / h;
		q = q / h;
		li k = 0;
		while(q % 2 == 0){
			q = q / 2;
			k++;
		}
		if(q != 1){
			cout << "Case #" << z + 1 << ": " << "impossible" << "\n";
			continue;
		}
		for(li i = 41; i > -1; i--){
			li w = (1ll << i);
			if(p >= w){
				cout << "Case #" << z + 1 << ": " << k - i << "\n";
				break;
			}
			else{
				w *= 2;
			}
		}
	}
	return 0;
}
/*

*/