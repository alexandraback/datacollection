#include <iostream>
#include <cstring>

using namespace std;

void itoa (long long in, char *s) {
	int i=0;
	while (in!=0) {
		s[i] = in%10 + '0';
		in/=10;
		i++;
	}
	s[i] = '\0';
}

bool check (int in) {
	char buff[100];

	itoa (in, buff);

	int len = strlen (buff);
	for (int i=0; i<len ;i++) {
		if (buff[i]!=buff[len-1-i])
			return false;
	}
	return true;
	
}

int main () {
	int cases;

	cin >> cases;

	int data[1010];
	for (int i=0; i<=1000; i++)
		data[i] = 0;
	for (int i=1; i*i<=1000; i++) {
		if (check(i) && check(i*i)) {
			data[i*i] = 1;
		}
	}
	for (int i=1; i<=1000; i++) {
		data[i] += data[i-1];
	}

	for (int c=1; c<=cases; c++) {
		cout << "Case #" << c << ": ";
		int A, B;
		cin >> A >> B;

		cout << data[B] - data[A-1] << endl;
	}

	return 0;
}
