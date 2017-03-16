#include <stdio.h>
#include <string.h>
int check(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 0;
	return 1;
}
int main(){
	int T, n;
	char s[1000001];
	scanf("%d", &T);
	for(int t=1;t<=T;++t){
		scanf("%s%d", s, &n);
		int len = strlen(s), cnt = 0;
		/*
		int begin = -1, end = 0;
		int m_begin = 0, m_end = 0;
		int c = 0, m = -1, cnt = 0, len = strlen(s);
		while(begin < len && end < len){
			if(check(s[end])){
				++begin;
				++end;
			}
			else{
				c += end-begin;
				if(m < c){
					m = c;
					m_begin = begin;
					m_end = end;
				}
				++end;
			}
			if(c >= n) ++cnt;
		}
		*/
		// length
		for(int i=0;i<len;++i){
			// start
			for(int j=0;j<len;++j){
				int max = -1, con = 0;
				for(int k=j;k+i<len;++k){
					if(check(s[k]) > 0){
						++con;
					}
					else{
						con = 0;
					}
					if(max < con) max = con;
				}
				if(max >= n) ++cnt;
			}
		}
		printf("Case #%d: %d\n", t, cnt);
	}
}
