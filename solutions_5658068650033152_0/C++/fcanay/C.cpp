#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <list>

using namespace std;



int main(){
	
	int t,n,m,k,a,b;
	cin >> t;
	for(int j = 1; j <= t; ++j){
		cout << "Case #" << j << ": ";
		cin >> n;
		cin >> m;
		cin >> k;
		if(m > 2 && n > 2 && k > 3){
			a = 1;
			b = 1;
			if(a > n){a = n;}
			if(b > m){b = m;}
			bool encontre = false;
			int mejor = k;
			while(b <= m){
				if(a <= n && b <= m){
					if(a*b >= k){
						//if((a*b - k) >= 2){ //posible error
							//cout << "a:" << a << "  b:" << b << endl;

							if((a*b - k) >= 4){
								if(2*a + 2*b - 8 < mejor){mejor = 2*a + 2*b -8;}
							}
							else if(2*a + 2*b - 4 - (a*b - k) < mejor){mejor = 2*a + 2*b - 4 - (a*b - k);}
							//cout << 2*a + 2*b - 4 - (a*b - k) << endl;
							encontre = true;
							//continue;
						/*}
						if(a < n && a*b + b >= k){
							//cout << "a:" << a+1 << "  b:" << b << endl;
							if(2*a + 2*b - 6 < mejor){mejor = 2*a + 2*b - 6;}
							//cout << 2*a + 2*b - 6 << endl;
							encontre = true;
							//continue;
						}
						if(b < m && a*b + a >= k){
							//cout << "a:" << a << "  b:" << b+1 << endl;
							if(2*a + 2*b - 6 < mejor){mejor = 2*a + 2*b - 6;}
							//cout << 2*a + 2*b - 6 << endl;
							encontre = true;
							//continue;
						}
						if((a*b - k) > 4){
								//cout << "ERROR" << endl;
							}
						if(2*a + 2*b - 4 - (a*b - k) < mejor){mejor = 2*a + 2*b - 4 - (a*b - k);}
						//cout << 2*a + 2*b - 4 - (a*b - k) << endl;
						encontre = true;
						//continue;
						*/

					}
					if(a < n){
						++a;
						continue;
					}
					a = 1;
					++b;
				}
			}
		cout << mejor << endl;
		}
		else{cout << k <<endl;}	
	}




	return 0;
}

/*
i = k/7;
		ic = i*i;
		if(4*i+ic == k && 4*i+2 >= n && 4*i+2 >=m){
			cout << 4*i << endl;
			continue;
		}
		if(4*i+ic+1 == k-1 && 4*i+2 >= n && 4*i+2 >=m){
			cout << 4*i+1 << endl;
			continue;
		}
		if(ic +5*i +2 >= k && ((4*i+2 >= n && 4*i+3 >=m)|| (4*i+3 >= n && 4*i+2 >=m))){
			cout << 4*i+2 << endl;
			continue;
		}
		if(ic +5*i +3 >= k && ((4*i+2 >= n && 4*i+3 >=m)|| (4*i+3 >= n && 4*i+2 >=m))){
			cout << 4*i+3 << endl;
			continue;
		}
		if(i > 2 && 4*i+3 >= n && 4*i+3 >=m){
			cout << 4*i+4 << endl;
			continue;
		}
		if(4*i+3 >= n && 4*i+3 >=m){
			cout << 4*i+5 << endl;
			continue;
		}

if(a <= b && a < n){
						++a;
						continue;
					}
					if(b < m){
						++b;
						continue;
					}
					++a;
					continue;



		*/