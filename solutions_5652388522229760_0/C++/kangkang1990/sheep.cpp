#include <fstream>

using namespace std;

void init(bool base[]);
int count(int num, bool base[], int left);
int countNumbers(int number, bool base[]);

int main() {
	//set input/output stream
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");

	int T;
	int n;
	bool base[20];
	input >> T;
	for(int i = 1; i <= T; i++) {
		init(base);
		input >> n;
		output << "Case #" << i << ": ";
		if(n == 0) {
			output << "INSOMNIA" << endl;
		} else {
			output << count(n, base, 10) << endl;
		}
	}
	return 0;
}

void init(bool base[]) {
	for(int i = 0; i < 10; i++) {
		base[i] = true;
	}
}

int count(int num, bool base[], int left) {
	int time = 0;
	while(left > 0) {
		time++;
		left = left - countNumbers(num * time, base);
	}

	return num * time;
}

int countNumbers(int number, bool base[]) {
	int sum = 0;
	while(number > 0) {
		if(base[number % 10] == true) {
			base[number % 10] = false;
			sum++;
		}
		number = number / 10;
	}

	return sum;
}
