#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = ~0u>> 1;
char buf[5000000], *p[1000000], *cur= buf+1, s[4444];
int T, f[555], cnt, caseCnt, N, len[1000000];
FILE *dic = fopen("dictionary.txt", "r");
int calc(int l, int r){
	int ret = 99999;
	for(int i= 1;i<= cnt;++ i) if(len[i] == r-l+1){
		int tmp = 0, pre = -6, flag = 1;
		for(int j= 0;p[i][j] && flag;++ j) if(p[i][j] != s[l+j]){
			++ tmp;
			if(j - pre < 5)
				flag = 0;
			else
				pre = j;
		}
		if(flag)
			ret = min(ret, tmp);
//		if(ret == 0)
//			printf("%s\n", p[i]);
	}
	return ret;
}
int main(){
	while(~fscanf(dic, "%s", cur)){
		p[++ cnt]= cur;
		len[cnt] = strlen(cur);
//		if(strcmp(cur, "code") == 0){
//			printf("%d\n", cnt);
//			printf("%d\n", len[cnt]);
//		}
		while(*cur ++);
	}
//	for(int i= 1;i<= cnt;++ i)
//		puts(p[i]+1);
	scanf("%d", &T);
	while(T --){
		scanf("%s", s+1);
		N = strlen(s+1);
		for(int i= 1;i<= N;++ i)
			f[i] = N+1;
		for(int i= 1;i<= N;++ i)
			for(int j= 0;j< i;++ j)
				f[i] = min(f[i], f[j] + calc(j+1, i));
//		for(int i= 1;i<= N;++ i)
//			printf("%d\n", f[i]);
		printf("Case #%d: %d\n", ++ caseCnt, f[N]);
	}
	return 0;
}
