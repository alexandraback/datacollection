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

#define infi 2100000000000000000LL

int main(){
	int T;
	unsigned long long int r, t, inf, med, sup;
	cin >> T;
	for(int caso=1;caso<=T;++caso){
		cin >> r >> t;
		inf = 1;
		sup = min((unsigned long long)sqrt(infi),infi/r);
		while(inf+1!=sup){
			med = (inf+sup)/2;
			if(2*r*med+2*med*(med+1)-3*med<=t){
				inf = med;
			}else{
				sup = med;
			}
		}
		cout << "Case #" << caso << ": " << inf << endl;
	}
	
	return 0;
}
