#include <cstdio>
#include <cstring>

const int MAXS = 105;

char pc[MAXS], tmp[MAXS], buf[MAXS];
int cases, len, ans;

void flip(int pos){
	ans++;
	memset(tmp, 0, sizeof(tmp));
	for(int i = 0; i <= pos; ++i)
		if(pc[i] == '-') tmp[pos - i] = '+';
		else tmp[pos - i] = '-';
	for(int i = 0; i <= pos; ++i)
		pc[i] = tmp[i];
}

int main(){
	scanf("%d\n", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%s", buf);
		len = strlen(buf);
		int zz = 0;
		memset(pc, 0, sizeof(pc));
		pc[zz] = buf[0];
		for(int i = 1; i < len; ++i)
			if(buf[i] != buf[i - 1]){
				++zz;
				pc[zz] = buf[i];
			}
		len = strlen(pc);
		ans = 0;
		for(int i = len - 1; i >= 0; --i){
			if(pc[i] == '+') continue;
			// need to flip...
			if(pc[0] == '-'){
				flip(i);
			} else {
				flip(0);
				flip(i);
			}
		}
		printf("Case #%d: %d\n", xx, ans);
	}
}
