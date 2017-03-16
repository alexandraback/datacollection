#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

char a[26];
char s[1000000];

void relax(string s,string t){
	for (int i=0;i<s.size();i++) if (isalpha(s[i])) a[s[i]-'a']=t[i];
}

int main(){
	for (int i=0;i<26;i++) a[i]='#';
	relax("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
	relax("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
	relax("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up");
	relax("zq","qz");
	int t,ti=0;
	for (scanf("%d\n",&t);t--;){
		printf("Case #%d: ",++ti);
		gets(s);
		int n=strlen(s);
		for (int i=0;i<n;i++) if (isalpha(s[i])) printf("%c",a[s[i]-'a']);
		else printf("%c",s[i]);
		puts("");
	}
    return 0;
}
