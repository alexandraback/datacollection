#include <fstream>
#include <cmath>

using namespace std;

void changeTo2Base(int bits[], long long int base, int len);
bool isCodeJam(int codeJam[], int divisor[], int len);
long long bitsToNumberWithBase(int bits[], int base, int len);
int checkPrime(long long number); 

int main() {
	//set input/output stream
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");

	int T;
	int n, j;
	int codeJam[100];
	int divisor[20];
	input >> T;
	input >> n >> j;
	long long int base = (1 << (n - 1)) + 1;
	output << "Case #1:" << endl;
	
	while(j > 0) {
		changeTo2Base(codeJam, base, n);
		if(isCodeJam(codeJam, divisor, n)) {
			j--;
			for(int i = 0; i < n; i++) {
				output << codeJam[i];	
			}
			output << ' ';
			for(int i = 2; i <= 10; i++) {
				output << divisor[i] << ' ';
			}
			output << endl;
		}

		base += 2;
	}
	return 0;
}

void changeTo2Base(int bits[], long long int base, int len) {
	while(len > 0) {
		bits[len - 1] = base % 2;
		base = (base >> 1);
		len--;
	}	
}

bool isCodeJam(int codeJam[], int divisor[], int len) {
	for(int i = 2; i <= 10; i++) {
		long long number = bitsToNumberWithBase(codeJam, i, len);
		//cout << "number is " << number << endl;
		divisor[i] = checkPrime(number);
		if(divisor[i] == -1) {
			return false;
		}
	}

	return true;
}

long long bitsToNumberWithBase(int bits[], int base, int len) {
	long long sum = 0;
	for(int i = 0; i < len; i++) {
		sum = sum * base + bits[i];
	}

	return sum;
}

int checkPrime(long long number) {
	int limit = sqrt(number);
	for(int i = 2; i <= limit; i++) {
		if(number % i == 0) {
			return i;
		}
	}
	
	return -1;
}
