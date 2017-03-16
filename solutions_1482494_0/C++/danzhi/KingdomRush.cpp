#include <stdio.h>
#include <algorithm>
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
int N = 0;
int a[1000];  // num of stars required to earn a one-stat rating
int b[1000];  // num of stars required to earn a two-star rating
int c = 0;

void ShowInput() {
	printf("%d\n", N);
	for (int i = 0; i < N; i++) {
		printf("%02d: %2d %2d\n", i, a[i], b[i]);
	}
}

int ls[2000]; // level-status, 0, 1, 2 (earned 0, 1, or two star).
bool f[2000];
bool finished() {
	for (int i = 0; i < N; i++) if (!f[i]) return false;
	return true;
}

// Find minimum number of times Ryan must complete levels in order to have
// earned a 2-star rating on every level or ""Too Bad" if impossible
void Solve() {
	// greedy approach
	for (int i = 0; i < N; i++) ls[i] = 0;
	for (int i = 0; i < N; i++) f[i] = false;
	int s = 0; // total star
	int count = 0;
	while (!finished()) {
		count++;
		bool done = false;
		// search for qualified levels which ever give maximal gain
		// Try to finish level with 2 stars
		for (int i = 0; i < N; i++) {
			if (f[i]) continue;
			if (s < a[i] && s < b[i]) continue;
			if (s >= b[i] && ls[i] == 0) {
				ls[i] = 2;
				f[i] = true;
				s += 2;
				done = true;
				// printf("finish level %2d with ** rating, total %d stars\n", i, s);
				break;
			}
		}
		if (done) continue;
		// Try to finish level (gain two-star rating) with 1 star
		for (int i = 0; i < N; i++) {
			if (f[i]) continue;
			if (s < a[i] && s < b[i]) continue;
			if (s >= b[i]) {
				assert(!f[i] && ls[i] >= 1);
				ls[i]++;
				s++;
				f[i] = true;
				done = true;
				// printf("play again level %2d with ** rating, earn *, total %d stars\n", i, s);
				break;
			}
		}
		if (done) continue;
		// Try to gain 1 star on a level (not finish)
		for (int i = 0; i < N; i++) {
			if (f[i]) continue;
			if (s < a[i] && s < b[i]) continue;
			// No play twice one-star rating (not earn star)
			if (s >= a[i] && ls[i] == 0) {
				assert(s < b[i]);
				ls[i]++;
				s++;
				done = true;
				// printf("play   level %2d with  * rating, total %d stars\n", i, s);
				break;
			}
		}
		if (done) continue;
		printf("Case #%d: Too Bad\n", c);
		return;
	}
	printf("Case #%d: %d\n", c, count);
}

int main(int argc, char* argv[]) {
	const char inputFile[] = "C:\\CodeJam\\KingdomRush\\B-small-attempt3.in";
	// const char inputFile[] = "C:\\CodeJam\\KingdomRush\\Sample2";
	Reader r(inputFile);
	T = r.ReadSingleIntLine();
	for (c = 1; c <= T; c++) {
		N = r.ReadSingleIntLine();
		for (int i = 0; i < N; i++) {
			r.ReadLine();
			a[i] = r.ReadInt();
			b[i] = r.ReadInt();
		}
		// ShowInput();
		Solve();
	}

 	return 0;
}