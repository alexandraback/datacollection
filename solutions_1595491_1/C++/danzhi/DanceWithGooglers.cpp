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
struct TestCase {
	int N;
	int S;
	int P;
	int ti[100];
};

// enum Surprise { required, optional, no };

struct ScoreRange {
	// low and high of best score
	int l;
	int h;
	// whether surprise is required, optional or no.
	char ls;
	char hs;
};

ScoreRange scores[31];

TestCase tests[100];

int main(int argc, char* argv[]) {
	const char inputFile[] = "C:\\CodeJam\\DanceWithGooglers\\B-large.in";
	Reader r(inputFile);
	T = r.ReadSingleIntLine();
	for (int i = 0; i < T; i++) {
		TestCase& t = tests[i];
		r.ReadLine();
		t.N = r.ReadInt();
		t.S = r.ReadInt();
		t.P = r.ReadInt();
		for (int k = 0; k < t.N; k++) {
			t.ti[k] = r.ReadInt();
			assert(t.ti[k] >= 0);
		}
	}
	/*
	printf("%d\n", T);
	for (int i = 0; i < T; i++) {
		TestCase& t = tests[i];
		printf("%d %d %d", t.N, t.S, t.P);
		for (int k = 0; k < t.N; k++) {
			printf(" %d", t.ti[k]);
		}
		printf("\n");
	}
	*/
	// build score table
	for (int t = 0; t < 31; t++) {
		ScoreRange& r = scores[t];
		r.l = (t + 2) / 3;
		r.h = (t + 4) / 3;
		if (r.h > 10) r.h = 10;
		if (r.h > t) r.h = t;
		assert(r.l <= t && r.l >= 0);
		assert(r.h <= t && r.h >= r.l);

		// 1. l-2 l-2 l => 3l - 4  required
		// 2. l-2 l-1 l => 3l - 3  required
		// 3. l-2 l   l => 3l - 2  optional
		// 4. l-1 l-1 l => 3l - 2  optional
		// 5. l-1 l   l => 3l - 1  no
		// 6. l   l   l => 3l - 0  no
		{
			int remain = 3 * r.l - t;
			assert(remain >= 0 && remain <= 4);
			if (remain >= 3) r.ls = 'r';
			else if (remain >= 2) r.ls = 'o';
			else r.ls = 'n';
		}
		{
			int remain = 3 * r.h - t;
			assert(remain >= 0 && remain <= 4);
			if (remain >= 3) r.hs = 'r';
			else if (remain >= 2) r.hs = 'o';
			else r.hs = 'n';
		}
		// printf("t:%2d l:%2d h:%2d ls:%c hs:%c\n", t, r.l, r.h, r.ls, r.hs);
	}

	// Compute maximum number of Googlers who could have had a best result 
	// of greater than or equal to p with specific number of surprises.
	for (int i = 0; i < T; i++) {
		TestCase& test = tests[i];
		// count following numbers:
        //  1. # of scores >= p with NO surprise;
		//  2. # of scores >= p with optional surprise;
		//  3. # of scores >= p with surprise;
		int c1 = 0;
		int c2 = 0;
		int c3 = 0;
		for (int k = 0; k < test.N; k++) {
			int t = test.ti[k];
			ScoreRange& r = scores[t];
			if (r.h < test.P) continue;
			if (r.l >= test.P) {
				if (r.ls == 'n' && r.hs == 'n') c1++;
				else if (r.ls == 'o' || r.hs == 'o') c2++;
				else if (r.ls == 'n' || r.hs == 'r') c2++;
				else c3++;
			} else {
				assert(r.h >= test.P && r.l < test.P);
				if (r.hs == 'n') c1++;
				else if (r.hs == 'o') c2++;
				else c3++;
			}
		}
		// This assert is not valid as surprise could also come from disqualified scores.
		// assert(test.S <= c3 + c2);
		printf("Case #%d: %d\n", i+1, (test.S <= c3)? c1 + c2 + test.S : c1 + c2 + c3);
	}
	return 0;
}