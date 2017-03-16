#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int main(){
	int T, A, B, K;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		int res = 0;
		cin >> A >> B >> K;
		
		for(int i=0;i<A;i++){
			for(int j=0;j<B;j++){
				if((i&j)<K)res++;
			}
		}
		
		
		cout << "Case #" << caso << ": " << res << endl;
	}
	
	return 0;
}
