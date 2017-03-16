// DanceWithGooglers.cpp : Defines the entry point for the console application.

#include <algorithm>
#include <stdio.h>
#include <vector>
#include "assert.h"
#include <hash_map>

using namespace std;

class Reader {
public:
	Reader(const char* inputFile) {
		m_fp = NULL;
		memset(m_line, 0, c_maxLineLen);
		m_p = m_line;
	    fopen_s(&m_fp, inputFile, "r");
		assert(m_fp != NULL);
	}
	~Reader() {
		if (m_fp != NULL) fclose(m_fp);
	}
	int ReadSingleIntLine() {
		ReadLine();
		return ReadInt();
	}
	// Reads a new line from file into m_line.
	// Returns true for success and false if no more line.
	bool ReadLine() {
		memset(m_line, 0, c_maxLineLen);
		m_p = m_line;
		return fgets(m_line, c_maxLineLen, m_fp) != NULL;
	}
	// Reads an integer from cached line. Return value or -1.
	int ReadInt() {
		return (int)ReadInt64();
	}
	__int64 ReadInt64() {
		SkipSpace();
		if (*m_p == 0) return -1;
		__int64 value = 0;
		while (*m_p >= '0' && *m_p <= '9') {
			value = value * 10 + (*m_p - '0');
			m_p++;
		}
		return value;
	}
	// Read character sequence into buf and make it 0-terminated.
	void ReadWord(char* buf, int len) {
		assert(len >= 1);
		*buf = 0;
		memset(buf, 0, len);
		SkipSpace();
		int offset = 0;
		while (*m_p != 0 && *m_p != '\n' && *m_p != '\r' && *m_p != ' ' && *m_p != '\t') {
			assert(offset < len - 1);
			buf[offset] = *m_p;
			m_p++;
			offset++;
		}
		buf[offset] = 0;
		assert(offset < len);
	}
	void ReadStringLine(char* buf, int len) {
		assert(len >= 1);
		memset(buf, 0, len);
		fgets(buf, len, m_fp);
		int k = strlen(buf);
		if (buf[k-1] == '\n') buf[k-1] = 0;
	}
private:
	void SkipSpace() {
		while (*m_p == ' ' || *m_p == '\r' || *m_p == '\n' || *m_p == '\t') m_p++;
	}
	FILE * m_fp;
	static const int c_maxLineLen = 100 * 1024;
	char m_line[c_maxLineLen];  // current line read.
	char* m_p;  // pointer to current character in the line.
};

int T = 0;
int arrayA[50];
int arrayB[50];

struct Digits {
	int v;
	int d[7];
	int nd;
	bool Compare();
};

int GetNumDigits(int n) {
	if (n >= 1000000) return 7;
	if (n >= 100000) return 6;
	if (n >= 10000) return 5;
	if (n >= 1000) return 4;
	if (n >= 100) return 3;
	if (n >= 10) return 2;
	if (n >= 1) return 1;
}

int main(int argc, char* argv[]) {
	const char inputFile[] = "C:\\CodeJam\\RecycledNumbers\\C-small-attempt0.in";
	Reader r(inputFile);
	T = r.ReadSingleIntLine();
	for (int i = 0; i < T; i++) {
		r.ReadLine();
		arrayA[i] = r.ReadInt();
		arrayB[i] = r.ReadInt();
	}
	/*
	printf("%d\n", T);
	for (int i = 0; i < T; i++) {
		printf("%d %d\n", arrayA[i], arrayB[i]);
	}
	*/

	int pow[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
	for (int i = 0; i < T; i++) {
		int totalCount = 0;
		int A = arrayA[i];
		int B = arrayB[i];
		int kb = GetNumDigits(B);
		int bLeadingDigit = B;
		for (int j = 1; j < kb; j++) bLeadingDigit /= 10;
		for (int n = A; n < B; n++) {
			int kn = GetNumDigits(n);
			int m[6];
			int count = 0;
			int t = n;
			for (int j = 1; j < kn; j++) {
				int digit = t % 10;
				t = pow[kn-1] * digit + (t / 10);
				// Ignore if digit is 0 or bigger than B
				if (digit == 0 || digit > bLeadingDigit) continue;
				// ensure m > n.
				if (t <= n) continue;
				// Ignore if dup
				bool dup = false;
				for (int l = 0; l < count; l++) {
					if (m[l] == t) { 
						dup = true; 
						break; 
					}
				}
				if (dup) continue;
				m[count++] = t;
			}
			// A qualified m must satisfy: A <= n < m <= B
			for (int j = 0; j < count; j++) {
				assert(m[j] > n);
				if (m[j] <= B) {
					totalCount++;
					// printf("%4d (%d, %d)\n", totalCount, n, m[j]);
				}
			}
		}
		printf("Case #%d: %d\n", i+1, totalCount);
	}
	return 0;
}