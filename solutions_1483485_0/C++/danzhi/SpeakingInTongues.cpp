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

struct Token {
	char encode;
	char decode;
	int count;
};

int compareToken(const void * a, const void * b) {
	Token* ta = (Token*)a;
	Token* tb = (Token*)b;
	int diff = (tb->count - ta->count);
	return (diff == 0)? ta->encode - tb->encode : diff;
}

struct LetterFreq {
	char c;
	double freq;
};

int compareFreq(const void * a, const void * b) {
	LetterFreq* fa = (LetterFreq*)a;
	LetterFreq* fb = (LetterFreq*)b;
	return (fb->freq > fa->freq)? 1 : -1;
}

Token tokens[26];
LetterFreq lfreqs[26];
int T = 0;
char lines[30][120];

Token* GetTokenByDecode(char decode) {
	for (int i = 0; i < 26; i++) if (tokens[i].decode == decode) return &tokens[i];
	return NULL;
}

Token* GetTokenByEncode(char encode) {
	for (int i = 0; i < 26; i++) if (tokens[i].encode == encode) return &tokens[i];
	return NULL;
}

void ShowTokens() {
	for (int i = 0; i < 26; i++) {
		if (tokens[i].decode == 0) printf("%c %3d\n", tokens[i].encode, tokens[i].count);
		else printf("%c %3d %c\n", tokens[i].encode, tokens[i].count, tokens[i].decode);
	}
}

void Decode(char encode, char decode) {
	for (int i = 0; i < T; i++) {
		char output[256];
		char* q = output;
		char* p = lines[i];
		while (*p != 0) {
			if (*p == ' ') *(q++) = ' ';
			else if (*p == encode) *(q++) = decode;
			else {
				Token *token = GetTokenByEncode(*p);
				if (token->decode != 0) *(q++) = token->decode;
				else *(q++) = '_';
			}
			p++;
		}
		*q = 0;
		printf("Case #%d: %s\n", i+1, output);
	}
}

double lfs[26] = { 
	8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153,
	0.772, 4.025, 2.406, 6.749,  7.507, 1.929, 0.095, 5.987, 6.327, 9.056,
	2.758, 0.978, 2.360, 0.150,  1.974, 0.074
};

// first letter frequency
double flfs[26] = { 
	11.602, 4.072, 3.511, 2.670, 2.000, 3.779, 1.950, 7.232, 6.286, 0.631,
	 0.690, 2.705, 4.374, 2.365, 6.264, 2.545, 0.173, 1.653, 7.755, 16.671,
	 1.487, 0.619, 6.661, 0.005, 1.620, 0.050
};

void AddDecode(char* encodes, char* decodes) {
	int len = strlen(encodes);
	assert(len == strlen(decodes));
	for (int k = 0; k < len; k++) {
		char encode = encodes[k];
		char decode = decodes[k];
		for (int i = 0; i < 26; i++) {
			if (tokens[i].encode != encode) continue;
			tokens[i].decode = decode;
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	const char inputFile[] = "C:\\CodeJam\\SpeakingInTongues\\A-small-attempt1.in";
	// "C:\\CodeJam\\SquareTiles\\B-small-practice.in";
	Reader r(inputFile);
	T = r.ReadSingleIntLine();
	for (int i = 0; i < T; i++) r.ReadStringLine(lines[i], 120);
	for (int i = 0; i < 26; i++) {
		tokens[i].encode = 'a' + i;
		tokens[i].decode = 0;
		tokens[i].count = 0;
	}
	AddDecode("y qee", "a zoo");
	AddDecode("de kr kd eoya kw aej tysr re ujdr lkgc jv",
		      "so it is okay if you want to just give up");
	AddDecode("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		      "there are twenty six factorial possibilities");
	AddDecode("ejp mysljylc kd kxveddknmc re jsicpdrysi",
		      "our language is impossible to understand");

	int remainDecode = 0;
	int index = -1;
	for (int i = 0; i < 26; i++) {
	  if (tokens[i].decode == 0) {
		  remainDecode++;
		  index = i;
	  }
	}
	assert(remainDecode <= 1);
	int remainEncode = 0;
	char decode = 0;
	for (int k = 0; k < 26; k++) {
	  Token* token = GetTokenByDecode('a'+k);
	  if (token == NULL) {
		  remainEncode++;
		  decode = 'a' + k;
	  }
	}
	assert(remainEncode == remainDecode);
	tokens[index].decode = decode;
	Decode(-1, -1);
	return 0;
}