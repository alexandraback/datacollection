#include <iostream>
#include <cstring>
#include <vector>

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

bool check (long long in) {
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

	vector <long long> data;
	data.push_back (0);

	for (long long i=1; i*i<=100000000000000LL; i++) {
		if (check(i) && check(i*i)) {
			data.push_back (i*i);
		}
	}
	data.push_back (100000000000001LL);


	for (int c=1; c<=cases; c++) {
		cout << "Case #" << c << ": ";
		long long A, B;
		cin >> A >> B;

		int s = 0;
		int e = data.size()-1;
		while (s<e) {
			int m = (s+e)/2;
			if (data[m] < A)
				s = m+1;
			else
				e = m;
		}

		int s_idx = e;

		s = 0;
		e = data.size()-1;
		while (s<e) {
			int m = (s+e)/2;
			if (data[m] <= B)
				s = m+1;
			else
				e = m;
		}

		int e_idx = s;

		cout << e_idx - s_idx << endl;
	}

	return 0;
}
