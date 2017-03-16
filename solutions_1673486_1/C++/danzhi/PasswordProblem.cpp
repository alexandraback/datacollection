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
		m_line = (char *)malloc(MAXLINE);
		memset(m_line, 0, MAXLINE);
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
		memset(m_line, 0, MAXLINE);
		m_p = m_line;
		return fgets(m_line, MAXLINE, m_fp) != NULL;
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
	double ReadFloat() {
		SkipSpace();
		if (*m_p == 0) return -1;
		double value = 0;
		while (*m_p >= '0' && *m_p <= '9') {
			value = value * 10 + (*m_p - '0');
			m_p++;
		}
		if (*m_p != '.') return value;
		m_p++;
		double weight = 0.1;
		while (*m_p >= '0' && *m_p <= '9') {
			value += (*m_p - '0') * weight;
			weight /= 10.0;
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
	static const int MAXLINE = 2 * 1024 * 1024;
	char* m_line;  // current line read.
	char* m_p;  // pointer to current character in the line.
};

int T = 0;
int A = 0;
int B = 0;
double* pa = NULL;
int c = 0;

void ShowInput() {
	printf("%d %d\n", A, B);
	for (int i = 0; i < A; i++) {
		printf("%2.1f ", pa[i]);
	}
	printf("\n");
}

void Solve() {
	// clean until k characters *left*
	double p = 1.0;  // the probability first k are correct
	double emin = 999999999;
	for (int k = 0; k <= A; k++) {
		if (k > 0) p *= pa[k-1];
		int m = (A - k) + (B-k) + 1; // first time finish
		double e = m + (1.0-p) * (B + 1);
		if (emin > e) emin = e;
	}
	// press entry right away need B + 2
	if (emin > B + 2) emin = B + 2;
	printf("Case #%d: %12.10f\n", c, emin);
}

int main(int argc, char* argv[]) {
	const char inputFile[] = "C:\\CodeJam\\PasswordProblem\\A-large.in";
	pa = (double *)malloc(200000 * sizeof(double));
	Reader r(inputFile);
	T = r.ReadSingleIntLine();
	for (c = 1; c <= T; c++) {
		r.ReadLine();
		A = r.ReadInt();
		B = r.ReadInt();
		r.ReadLine();
		for (int i = 0; i < A; i++) {
			pa[i] = r.ReadFloat();
		}
		// ShowInput();
		Solve();
	}

	return 0;
}