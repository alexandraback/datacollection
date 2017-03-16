#include <fstream>

using namespace std;

// Methedology: if the sum of digits is divisible by 6, then 2, 3, or 6 is a
// divisor in bases 10, 9, 7, 5, 4, 3. It remains to check bases 8, 6, and 2.
// We check composite-ness by dividing by the first 2000 primes.

int primes[2000];
__int128 expan = 0;

__int128 pow(int A, int B){
	if(B == 0){
		return 1;
	} else{
		return pow(A, B-1) * A;
	}
}

int check(long long Z, int B){
	expan = 0;
	for(int j=0; j<100; j++){
		if((Z & 1) == 1){
			expan += pow(B, j);
		}
		Z = Z >> 1;
		if(Z == 0){
			break;
		}
	}
	bool prime = true;
	int factor;
	for(int j=0; j<2000; j++){
		if(expan % primes[j] == 0){
			prime = false;
			factor = primes[j];
			break;
		}
	}
	if(prime){
		return -1;
	}
	return factor;
}

long long next(long long Z){
	long long R = Z & (-Z);
	if((Z & (R << 1)) != 0){
		return (next((Z ^ R) >> 1) << 1) + 1;
	} else{
		return Z ^ (R+(R << 1));
	}
}

int main(int argc, char* argv[]){
	ifstream in(argv[1]);
	ofstream out("coin.out");
	primes[0] = 2;
	int j = 1;
	for(int i = 3; i < 17392; i++){
		bool t = true;
		for(int k = 0; k<j; k++){
			if(i % primes[k] == 0){
				t = false;
				break;
			}
		}
		if(t){
			primes[j] = i;
			j++;
		}
	}

	int T, N, J;
	in >> T;
	for(int i = 1; i<=T; i++){
		in >> N >> J;
		out << "Case #" << i << ":" << endl;
		int num = 0;
		long long mid = 15;
		long long one = 1;
		int F2, F6, F8;
		for(int k = 0; k<100000000; k++){
			long long cand = ((one << (N-1)) + (mid << 1) + 1);
			F2 = check(cand, 2);
			F6 = check(cand, 6);
			F8 = check(cand, 8);
			if(F2 != -1 && F6 != -1 && F8 != -1){
				num++;
				string st = "";
				while(true){
					if(cand % 2 == 0){
						st = "0" + st;
					} else{
						st = "1" + st;
					}
					cand /= 2;
					if(cand == 0){
						break;
					}
				}
				out << st << " " << F2 << " 2 3 2 " << F6 << " 6 " << F8 << " 2 3" << endl;
				if(num == J){
					break;
				}
			}
			mid = next(mid);
		}
	}
}
