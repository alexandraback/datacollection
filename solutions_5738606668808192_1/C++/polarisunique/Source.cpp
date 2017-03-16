// Example program
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

string buildString(int64_t x);
int isPrime(string s, int base);
int checkDiv(string s, int base, int div);

int main()
{
	ifstream myfile("C-large.in");
	ofstream file("out.txt");
	int n;
	myfile >> n;
	file << "Case #1:" << endl;
	for (int i = 0; i < n; i++){
		int m, k;
		myfile >> m >> k;
		int count = 0;
		int64_t start = (int64_t)pow(2, m - 1) + 1;
		int64_t end = (int64_t)pow(2, m) - 1;
		for (int64_t j = start; j <= end; j += 2){
			string str = buildString(j);
			stringstream output;
			bool go = true;
			output << str << " ";


			for (int base = 2; base <= 10; base++){
				int pr = isPrime(str, base);
				output << pr;
				if (base != 10)
					output << " ";
				if (!pr)
					go = false;
			}
			if (go){
				file << output.str() << endl;
				count++;
			}
			if (count == k){
				return 0;
			}
		}
	}
}

string buildString(int64_t x){
	string ans;
	while (x != 0){
		if (x % 2 == 1)
			ans = '1' + ans;
		else
			ans = '0' + ans;
		x /= 2;
	}
	return ans;
}

int isPrime(string s, int base){
	if (checkDiv(s, base, 2))
		return 2;
	for (int i = 3; i < 100; i+=2){
		if (checkDiv(s, base, i))
			return i;
	}
	return 0;
}

int checkDiv(string s, int base, int div){
	int sum = 0;
	int size = s.size();
	for (int i = 0; i < size; i++){
		int digit = size - i - 1;
		int64_t b = (int64_t)pow(base % div, digit);
		if (b < 0)
			return 0;
		if (s[i] == '1')
			sum += b % div;
	}
	return !(sum % div);
}

