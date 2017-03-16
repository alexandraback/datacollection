#include <fstream>
#include <iostream>

using namespace std;
typedef unsigned long long int ulli;
ulli exponentiate(int base, int exp){
	if(base == 1) return 1;
	if(base == 0) return 0;
	if(exp == 1) return base;
	if(exp == 0) return 1;
	if(exp % 2 == 0){
		ulli temp = exponentiate(base, exp >> 1);
		return temp*temp;
	}else{
		return base * exponentiate(base, exp-1);
	}
}
int main(){
	ifstream in("input");
	ofstream out("output");
	int times;
	in >> times;
	for(int t = 1; t <= times; t++){
		int k, c, s;
		in >> k >> c >> s;
		if(s * c >= k){
			out << "Case #" << t << ":";
			int cnt = 0;
			int val = k-1;
			while(cnt < k){
				ulli tile = 0;
				ulli multiplier = exponentiate(k, c-1);
				for(int i = c-1; i >= 0; i--){
					if(val == 0) break;
					tile += val * multiplier;
					val--; multiplier /= k;
				}
				out << " " << tile+1;
				cnt += c;
			}
			out << endl;
		}else{
			out << "Case #" << t << ": IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
