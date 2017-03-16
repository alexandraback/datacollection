// Example program
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

string buildString(int x);
int isPrime(string s, int base);
int checkDiv(string s, int base, int div);

int main()
{
	ifstream myfile("C-small-attempt0.in");
	ofstream file("out.txt");
	int n;
	myfile >> n;
	file << "Case #1:" << endl;
	for (int i = 0; i < n; i++){
		int m, k;
		myfile >> m >> k;
		int count = 0;
		int start = (int)pow(2, m - 1) + 1;
		int end = (int)pow(2, m) - 1;
		for (int j = start; j <= end; j += 2){
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

string buildString(int x){
	string ans;
	while (x != 0){
		char c = x % 2 + '0';
		ans = c + ans;
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
		int b = (int)pow(base % div, digit);
		if (b < 0)
			return 0;
		if (s[i] == '1')
			sum += b % div;
	}
	return !(sum % div);
}

