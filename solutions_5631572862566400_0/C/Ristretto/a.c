#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FORN(n) for(i=0;i<n;i++)
#define FORIN(i,n) for(i=0;i<n;i++)

int N=0;
int g[1024]={0};
int visited[1024]={0};

struct line{
	int start;
	int end;
	int len;
	int len_red;
	int is_loop;
	int is_special;
	int special;
};
struct line lines[1024];

int
get_len(int s){
	if(visited[g[s]]) {
		visited[s]=0;
		return 1;
	} else {
		visited[s]=1;
		int len = get_len(g[s]);
		visited[s]=0;
		return len+1;
	}
}

int
solve(){
	int i, j;
	FORN(N){
		int len = get_len(i);
		int end=i, end2;
		FORIN(j, len-1){
			end2 = end;
			end = g[end];
		}
		lines[i].start = i;
		lines[i].len = len;
		lines[i].end = end;
		if(g[end]==i){
			lines[i].is_loop=1;
			lines[i].is_special=0;
		} else if (g[end]==end2) {
			lines[i].is_loop=0;
			lines[i].is_special=1;
			lines[i].special = end2;
		} else {
			lines[i].is_loop=0;
			lines[i].is_special=0;
			int end=i;
			FORIN(j, len-1){
				end=g[end];
				if(end==g[lines[i].end]){
					lines[i].len_red = j+3;
					break;
				}
			}
		}
	}
	int lpmax=0;
	FORN(N){
		if((lines[i].is_loop || lines[i].is_special)
				&& lines[i].len>lpmax){
			lpmax = lines[i].len;
		}else if (lines[i].len_red>lpmax){
			lpmax = lines[i].len_red;
		}
	}
	FORN(N){
		if(lines[i].is_special){
			FORIN(j, N){
				if(i==j) continue;
				if(lines[j].is_special && lines[i].special==lines[j].end
							&& lines[i].end==lines[j].special) {
					if ( (lines[i].len + lines[j].len-2) > lpmax ){
						lpmax = lines[i].len + lines[j].len-2;
					}
				}
			}
		}
	}
	return lpmax;
}

int main(){
	int cases, T, i;
	//int input[2000];

	scanf("%d", &T);
	FORIN(cases,T){
		scanf("%d",&N);
		FORN(N){
			scanf("%d", &g[i]);
			g[i]--;
		}
		printf("Case #%d: %d\n", cases+1, solve());
	}
	return 0;
}

