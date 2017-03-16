#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int tc_;
char map[] = {"yhesocvxduiglbkrztnwjpfmaq"};
char s[1000];

int main(){
	scanf("%d", &tc_);
	gets(s);
	FOE(tc,1,tc_){
		gets(s);
		printf("Case #%d: ", tc);
		for (int j=0; s[j]; j++)
		if (s[j] != ' ') printf("%c", map[s[j]-'a']);
		else printf(" ");
		puts("");
	}
	return 0;
}
