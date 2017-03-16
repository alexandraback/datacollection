#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a) for (int i = 0; i < a; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(sol, i) cout << "Case #" << i << ": " << sol << '\n';

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

//primes
const vi v = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 
79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383,
389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499 };

const int N = 16;
bool num[N-2];

bool mul2(int &two){
	lli n = 1;
	For(i, N-2){
		if (num[i])n += pow(2 , (N-2 - i));
	}
	n += pow(2, N-1);

	FOR(i, v){
		if (n%v[i]==0){
			two = v[i];
			return true;
		}
	}
	return false;
}

bool mul6(int &six){
	lli n = 1;
	For(i, N-2){
		if (num[i])n += pow(6, (N-2 - i));
	}
	n += pow(6, N-1);

	FOR(i, v){
		if (n%v[i]==0){
			six = v[i];
			return true;
		}
	}
	return false;
}

bool mul8(int &eight){
	lli n = 1;
	For(i, N-2){
		if (num[i])n += pow(8, (N-2 - i));
	}
	n += pow(8, N-1);

	FOR(i, v){
		if (n%v[i]==0){
			eight = v[i];
			return true;
		}
	}
	return false;

}

int main(){
	int two, six, eight;
	For(i, N-2) num[i] = 1;
	num[0] = num[1] = num[2] = num[3] = 0;
	int cont = 0;
	cout << "Case #1:\n";
	while (cont < 50){
		if (mul2(two) && mul6(six) && mul8(eight)){
			cout << '1';
			For(i, N-2)cout << num[i];
			cout << "1 ";
			cout << two << " 2 3 2 " << six << " 6 " << eight << " 2 3\n";
			++cont;
		}
		//ChangeNumber
		bool first = true, second = true, done = false; int f, s;
		for (int i = N-3; i >= 0 && !done; --i){
			if (!num[i] && first){
				first = false;
				if (i != N-3){
					num[i] = 1;	num[i + 1] = 0;
					done = true;
				}
				else f = i;
				continue;
			}
			if (!num[i] && second){ 
				second = false;
				if (i != N - 4){
					num[i] = num[f] = 1;
					num[i + 1] = num[i + 2] = 0;
					done = true;
				}
				else s = i;
				continue;
			}
			if (!num[i]){
				num[i] = num[f] = num[s] = 1;
				num[i + 1] = num[i + 2] = num[i + 3] = 0;
				done = true;
			}
		}
	}
	system("pause");
	return 0;
}