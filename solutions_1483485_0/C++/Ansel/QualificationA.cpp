#include <assert.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const char * ciphertext[3] = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

const char * plaintext[3]  = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up",
};

// cipherchar : index
// plainchar  : key
char maptable[26];

void init_maptable ()
{
	int	i, j;
	for (i = 0; i < 3; ++i) {
		int length = strlen(ciphertext[i]);
		for (j = 0; j < length; ++j) {
			char cipherchar = ciphertext[i][j];
			char plainchar  = plaintext[i][j];
			if (cipherchar != ' ') {
				maptable[cipherchar - 'a'] = plainchar;
			}
		}
	}
	maptable['z'-'a'] = 'q';
	maptable['q' - 'a'] = 'z';
//	for (i = 0; i < 26; ++i) {
//		cout << "cipherchar = " << char(i + 'a') << "; plainchar = " << maptable[i] << endl;
//	}
//	for (i = 0; i < 25; ++i) {
//		for (j = i+1; j < 26; ++j) {
//			if (maptable[j] == maptable[i]) {
//				cout << "Error:" << "i = " << i << "; j = " << j << "; maptable[] = " << maptable[i] << endl;
//				exit(1);
//			}
//		}
//	}
//	cout << "Right" << endl;
}

void decode(const char* cipherline,  char * plainline)
{
	int length = strlen(cipherline);
	for ( ; *cipherline != '\0'; plainline++, cipherline++) {
		if (*cipherline >= 'A' && *cipherline <= 'Z') {
			*plainline = maptable[*cipherline - 'A'];
		} else if (*cipherline >= 'a' && *cipherline <= 'z') {
			*plainline = maptable[*cipherline - 'a'];
		} else {
			*plainline = *cipherline;
		}
	}
	*plainline = *cipherline;
}

int main() {
	init_maptable();

	int 	N;
	char	line[256];
	char	plainline[256];

	cin.getline(line, 256);
	N = atoi(line);
	assert(N > 0);

	for (int i = 0; i < N; i++) {
		cin.getline(line, 256);
		int length = strlen(line);
		assert(length > 0 && length <= 100);
		decode(line, plainline);
		cout << "Case #" << i+1 << ": " << plainline << endl;
	}

	return 0;
}
