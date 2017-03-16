#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

string in[4] ={
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"y qee"
};
string out[4] = {
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up",
"a zoo"
};

char zn[256];

char buf[1000];
int used[256];

int main() {
	for (int i=0;i<4;i++) for (int j=0;j<(int)in[i].size();j++) {
		if (in[i][j] >= 32) {
			zn[in[i][j]] = out[i][j];
			used[out[i][j]] = 1;
		}
	}
	int n;
	gets(buf);
	sscanf(buf, "%d", &n);
	zn['z'] = 'q';
	//jfor (int j='a';j<='z';j++) cerr<<(char)j<<" "<<(int)used[j]<<endl;
	//for (int j='a';j<='z';j++) cerr<<(char)j<<" "<<(int)zn[j]<<endl;
	for (int i=0;i<n;i++){
		gets(buf);
		printf("Case #%d: ", i+1);
		int len = strlen(buf);
		for (int j=0;j<len;j++) if(buf[j]>=32)
			printf("%c", (char)zn[buf[j]]);
		printf("\n");
	}

	return 0;
}
