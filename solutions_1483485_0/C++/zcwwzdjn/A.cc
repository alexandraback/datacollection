#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

namespace {
	const char kTable[] = "yn_icwlbkuomxsev_pdrjgthaq";
	const char kRTable[] = "ynficwlbkuomxsevzpdrjgthaq";
	// fz
	int t;
	char buf[128], tr[26];

	void Solve(FILE *fin, FILE *fout) {
		for (int i = 0; i < 26; ++ i) tr[kRTable[i] - 'a'] = i + 'a';
		fscanf(fin, "%d", &t);
		for (int cas = 0; cas ++ < t; ) {
			fgets(buf, 128, fin);
			if (buf[0] == '\n') fgets(buf, 128, fin);
			for (int i = 0, sz = strlen(buf); i < sz; ++ i)
				if (buf[i] >= 'a' && buf[i] <= 'z') buf[i] = tr[buf[i] - 'a'];
			fprintf(fout, "Case #%d: %s", cas, buf);
		}
	}
}

int main() {
	::Solve(stdin, stdout);
	return 0;
}
