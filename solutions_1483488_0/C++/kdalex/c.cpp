#include <set>
#include <iostream>


using namespace std;

int base, base10;
void getBase(int a) {
	base = 1;
	base10 = 0;
	while(base * 10 <= a) {
		base *= 10;
		base10++;
	}
}

set<int> numbers;
unsigned long long cnt;



void add(int num, int a, int b) {
	if(!numbers.count(num)) {
		unsigned long long cntc = 1;
		numbers.insert(num);
		for(int i = 0; i < base10; i++) {
			num = (num / 10) + ((num % 10) * base);
			if(num >= a && num <= b && !numbers.count(num)) {
				numbers.insert(num);
				cntc++;
			}
		}
		cnt += cntc * (cntc - 1) / 2LLU;
	}
}


int main() {
	int t, a, b;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cin >> a >> b;
		getBase(a);
		numbers.clear();
		cnt = 0;
		for(int i = a; i <= b; i++)
			add(i, a, b);
		cout << "Case #" << tt << ": " << cnt << endl;
	}
	return 0;
}