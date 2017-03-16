#include <iostream>

using namespace std;

char t[4][4] = {
	{'h', 'i', 'j', 'k'},
	{'i', 'h', 'k', 'j'},
	{'j', 'k', 'h', 'i'},
	{'k', 'j', 'i', 'h'},
};

int S[4][4] = {
	{1, 1, 1, 1},
	{1, -1, 1, -1},
	{1, -1, -1, 1},
	{1, 1, -1, -1},
};

#define MUL(x, y) t[x - 'h'][y - 'h']
#define S_MUL(x, y) S[x - 'h'][y - 'h']



char s[10000];


int multiply(char str[], int L,  int start, int end, char *result) {
	int sig = 1, L_sig;
	char tmp = 'h', L_tmp;

	for (int i = 0; i < L; i++) {
		sig = sig * S_MUL(tmp, str[i]);
		tmp = MUL(tmp, str[i]);
	}
	L_sig = sig;
	L_tmp = tmp;

	sig = 1;
	tmp = 'h';

	int i;
	if (end - start <= L) {
		for (i = start; i < end; i++) {
			sig = sig * S_MUL(tmp, str[i % L]);
			tmp = MUL(tmp, str[i % L]);
		}
		*result = tmp;
		return sig;
	}
	for (i = start % L; i < L; i++) {
		sig = sig * S_MUL(tmp, str[i % L]);
		tmp = MUL(tmp, str[i % L]);
	}

	for (i = 0; i < (end/L - start/L - 1) % 4; i++) {
		sig = sig * L_sig * S_MUL(tmp, L_tmp);
		tmp = MUL(tmp, L_tmp);
	}

	for (i = 0; i < end % L; i++) {
		sig = sig * S_MUL(tmp, str[i % L]);
		tmp = MUL(tmp, str[i % L]);
	}

	*result = tmp;
	return sig;
}

int main()
{
	int T;
	cin >> T;
	for (int n = 1; n <= T; n++) {
		int L, X;
		cin >> L >> X;
		for (int i = 0; i < L; i++) {
			cin >> s[i];
		}
		char total;
		if (multiply(s, L, 0, L*X, &total) == -1) {
			if (total != 'h') {
				cout << "Case #" << n << ": NO" << endl;
				continue;
			}
		}
		else {
			cout << "Case #" << n << ": NO" << endl;
			continue;
		}

		int sig_i = 1;
		char tmp_i = 'h';
		for (int i = 0; i < L * X - 2; i++) {
			sig_i = sig_i * S_MUL(tmp_i, s[i % L]);
			tmp_i = MUL(tmp_i, s[i % L]);

			if (sig_i == 1 && tmp_i == 'i') {
				int sig_j = 1;
				char tmp_j = 'h';
				for (int j = i+1; j < L * X - 1; j++) {
					sig_j = sig_j * S_MUL(tmp_j, s[j % L]);
					tmp_j =  MUL(tmp_j, s[j % L]);
					if (sig_j == 1 && tmp_j == 'j') {
						int sig_k ;
						char tmp_k ;
						sig_k = multiply(s, L, j+1, L*X, &tmp_k);
						if (sig_k == 1 && tmp_k == 'k')
							goto yes;
					
					}
				}
			
			}
		}

		cout << "Case #" << n << ": NO" << endl;
		continue;
yes:
		cout << "Case #" << n << ": YES" << endl;
	}
	return 0;
}
