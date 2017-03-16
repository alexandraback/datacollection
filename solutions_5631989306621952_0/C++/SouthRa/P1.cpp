#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

char s[1005];
int ans[5000];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int n, cases, i, len, head, tail;
	scanf("%d", &n);
	for(cases=1;cases<=n;cases++){
		scanf("%s", s);
		len=strlen(s);
		ans[2500]=0;
		head=2500;
		tail=2501;
		for(i=1;i<len;i++){
			if(s[i]<s[ans[head]]){
				ans[tail]=i;
				tail++;
			}
			else{
				head--;
				ans[head]=i;
			}
		}
		printf("Case #%d: ", cases);
		for(i=head;i<tail;i++) printf("%c", s[ans[i]]);
		puts("");
	}
	return 0;
}
