#include <cstdio>
#include <map>
#include <string>

using namespace std;

map<char, char> g_map;

void putMap(char c1, char c2) {
	g_map[c1] = c2;
	//g_map[c2] = c1;
}
void putLine(string s1, string s2) {
	for(int i=0; i<(int)s1.size(); ++i) {
		putMap(s1[i], s2[i]);
	}
}


int main() {
	putLine("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	putLine("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	putLine("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
	putLine("qz", "zq");

	char line[1024];
	fgets(line, sizeof(line), stdin);
	int n = atoi(line);
	for(int i=0; i<n; ++i) {
		fgets(line, sizeof(line), stdin);
		printf("Case #%d: ", i+1);
		char * p = line;
		while(*p) {
			char c = *p;
			if('a' <= c && c<= 'z') {
				if(g_map[c]) {
					c = g_map[c];
				}
				else {
					c += 'A' - 'a';
				}
			}
			putchar(c);
			++p;
		}
	}
	return 0;
}
