#include <bits/stdc++.h>




using namespace std;







#define fr(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp make_pair
typedef pair<int,int> pii;



int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {1,0,-1,-1,-1,0,1,1};
pii fila[55*55];
bool mk[55][55];
char gr[55][55];
int in, fi;
int t;
int r,c,m;

bool valid(int a, int b){
	return a >= 0 && a < r && b >= 0 && b < c;
}


bool solve(int r, int c, int s){
	fr(i,0,r) fr(j,0,c) gr[i][j] = '*';
	bool ret = false;
	if(s == 1){
		gr[0][0] = 'c';
	}
	fr(i,2,r+1){
		int j = s/i;
		if(j > c || j <= 1) continue;
		if(s % i){
			if(j != c && (i != 2 || s%i != 1) && (j != 2 || s%i != 1)){
				fr(k,0,i) fr(l,0,j) gr[k][l] = '.';
				fr(l,0,s%i) gr[l][j] = '.';
				if(s%i == 1){
					gr[i-1][j-1] = '*';
					gr[s%i][j] = '.';
				}
				gr[0][0] = 'c';
				break;
			}
		}
		else{
			fr(k,0,i) fr(l,0,j) gr[k][l] = '.';
			gr[0][0] = 'c';
			break;
		}
	}
	return gr[0][0] == 'c';
}


int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%d %d %d",&r,&c,&m);
		int s = r*c-m;
		printf("Case #%d:\n",cas);
		fr(i,0,r) fr(j,0,c) gr[i][j] = '*';
		if(r == 1 || c == 1){
			int cnt = 0;
			fr(i,0,r){
				fr(j,0,c){
					gr[i][j] = '.';
					cnt++;
					if(cnt == s) break;
				}
				if(cnt == s) break;
			}
			gr[0][0] = 'c';
			fr(i,0,r){
				fr(j,0,c) printf("%c",gr[i][j]);
				puts("");
			}
			continue;
		}
		if(s == 2 || s == 3 || s == 5) printf("Impossible\n");
		else{
			bool ok = solve(r,c,s);
			if(ok){
				fr(i,0,r){
					fr(j,0,c) printf("%c",gr[i][j]);
					puts("");
				}
			}
			else{
				ok = solve(c,r,s);
				if(ok){
					fr(i,0,r){
						fr(j,0,c) printf("%c",gr[j][i]);
						puts("");
					}
				}
				else printf("Impossible\n");
			}
		}
	}
	return 0;
}























