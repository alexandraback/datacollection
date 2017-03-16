#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const char dict[27] = "yhesocvxduiglbkrztnwjpfmaq";
int n; char a[10001];
int main()
{
	freopen("A.in", "r", stdin); freopen("A.out", "w", stdout);
int T; scanf("%d", &T); getchar();
	for (int i = 1; i <= T; i++){
		printf("Case #%d: ", i);
		gets(a);
		for (char *S = a; *S; S++){ if (!isalpha(*S)) putchar(' '); else putchar(dict[*S - 'a']); }
		putchar('\n');
	}
}
