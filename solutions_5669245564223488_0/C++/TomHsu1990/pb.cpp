#include <stdio.h>
#include <string.h>
int cc[110], len[110], use[110], com[110];
int table[110][110];
char train[110][110];
long long int cnt;
void go(int s, int num){
	if(s == num){
		//for(int i=0;i<num;++i){
		//	printf("%s", train[com[i]]);
		//}
	
		int invalid = -1;
		for(int i=0;i<num;++i){
			for(int j=0;j<num;++j){
				if(i != j && i+1 != j && i-1 != j &&
				   table[com[i]][com[j]] > 0){
					invalid = 1;
				}
			}
		}
		//printf(" %d\n", invalid);
		if(invalid < 0) ++cnt;
		return ;
	}
	for(int i=0;i<num;++i){
		if(use[i] < 0 &&
		   ((table[com[s-1]][i] < 0) || (table[com[s-1]][i] > 0 && train[com[s-1]][len[com[s-1]]-1] == train[i][0]))){
			use[i] = 1;
			com[s] = i;
			go(s+1, num);
			use[i] = -1;
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int tt=1;tt<=t;++tt){
		int num;
		scanf("%d", &num);
		for(int i=0;i<num;++i){
			scanf("%s", train[i]);
			len[i] = strlen(train[i]);
		}
		for(int i=0;i<num;++i){
			for(int j=0;j<num;++j){
				table[i][j] = -1;
			}
		}
		int ZZZ = -1;
		for(int i=0;i<num;++i){
			for(int j=0;j<num;++j){
				if(i != j){
					for(int k=0;k<26;++k){
						cc[k] = 0;
					}
					for(int k=0;k<len[i];++k){
						cc[train[i][k]-'a'] = 1;
					}
					for(int k=0;k<len[j];++k){
						if(cc[train[j][k]-'a'] == 1){
							cc[train[j][k]-'a'] = 2;
						}
					}
					int gg = 0;
					for(int k=0;k<26;++k){
						if(cc[k] > 1){
							++gg;
						}
					}
					if(gg > 1){
						ZZZ = 1;
					}
					else if(gg == 1){
						table[i][j] = 1;
					}
				}
			}
		}
		cnt = 0;
		if(ZZZ < 0){
			for(int i=0;i<num;++i){
				for(int j=0;j<num;++j){
					use[j] = -1;
				}
				use[i] = 1;
				com[0] = i;
				go(1, num);
				use[i] = -1;
			}
		}
		printf("Case #%d: %lld\n", tt, cnt%1000000007);
	}
	return 0;
}
