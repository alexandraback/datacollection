// Sandbox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void counting_sheep() {
	int T;

	cin >> T;
	long long *arr = new long long[T];
	for (int i = 0; i < T; i++)
		cin >> arr[i];

	for (int i = 0; i < T; i++) {
		int seen[10];
		memset(seen, 0, 10 * sizeof(int));

		long long val = arr[i];

		bool all = true;
		for (int j = 0; j < 10000; j++) {
			long long val2 = val;
			while (val2 > 0) {
				int digit = val2 % 10;
				val2 /= 10;
				seen[digit] = 1;
			}

			all = true;
			for (int j = 0; j < 10; j++) 
				if (!seen[j])
					all = false;
			
			if (all)
				break;

			val += arr[i];
		}

		if (all)
			cout << "Case #" << i + 1 << ": " << val << endl;
		else
			cout << "Case #" << i + 1 << ": INSOMNIA" << endl;
	}
}

void pancakes() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	string s;
	int T;

	in >> T;
	for (int i = 0; i < T; i++) {
		in >> s;

		int switches = 0;
		for (int j = 0; j < s.length() - 1; j++) {
			if (s[j] != s[j + 1])
				switches++;
		}
		if (s[s.length() - 1] == '-')
			switches++;

		out << "Case #" << i + 1 << ": " << switches << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	pancakes();

	return 0;
}

