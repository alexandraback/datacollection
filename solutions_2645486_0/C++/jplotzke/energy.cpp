#include <cstdio>
#include <iostream>
using namespace std;

const int E = 5;
const int N = 10;

int main(){
	freopen("energy.in", "r", stdin);
	freopen("energy.out", "w", stdout);
	int run, emax, reg, count, val[N], total[2][E+3], curr, prev, temp;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> emax >> reg >> count;
		for (int x = 0; x < count; ++x) cin >> val[x];
		
		prev = 0; curr = 1;
		for (int x = 0; x <= emax; ++x) total[prev][x] = 0;
		for (int x = 0; x < count; ++x){
			for (int y = 0; y <= emax; ++y) total[curr][y] = 0;
			for (int y = 0; y <= emax; ++y){
				int limit = y+reg;
				if (limit > emax) limit = emax;
				for (int z = 0; z <= limit; ++z){
					temp = total[prev][y] + val[x] * (limit-z);
					if (temp > total[curr][z]) total[curr][z] = temp;
				}
			}
			temp = prev; prev = curr; curr = temp;
		}
		cout << "Case #" << a << ": " << total[prev][0] << endl;
	}
	return 0;
}
