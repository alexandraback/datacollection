#include <stdio.h>
#include <string.h>

int main() {
	int T, S;
	static char arr[1024];
	scanf("%d", &T);
	for (int C=1;C<=T;C++) {
		scanf("%d%s", &S, arr);
		int end=strlen(arr);
		while (end && arr[end-1]=='0')
			end--;
		arr[end]=0, S=end;
		int tot=0, cnt=0;
		for (int i=0;i<S; i++) {
			if (cnt<i) {
				tot+=i-cnt;
				cnt=i;
			}
			cnt+=arr[i]-'0';
			//printf("[%d %d %d] ", i, tot, cnt);
		}
		printf("Case #%d: %d\n", C, tot);
	}
	return 0;
}

