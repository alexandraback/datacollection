#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a); i < (b); i++)
#define inf 0x3F3F3F3F
#define pb push_back
#define ST first
#define ND second
#define mod 1000000007

using namespace std;
typedef long long ll;

char arr[110][110], temp[110][110];
int prox[110], ante[110], n, head, size[110], iguais[30], sizet[110], ponta[30], meio[30];
int mat[110][110];

void init(){
	fr(i, 0, n){
		prox[i] = i+1;
	}
	prox[n-1] = -1;
	
	fr(i, 0, n){
		ante[i] = i-1;
	}
	ante[0] = -1;
	
	head = 0;
}

void remover(int pos){
	if(head == pos) head = prox[pos];
	else prox[ante[pos]] = prox[pos];
	
	if(prox[pos] != -1){
		ante[prox[pos]] = ante[pos];
	}
}

int ciclo, mark[110];

void dfs(int s){
	if(mark[s]){
		ciclo = 1;
		return;
	}
	
	mark[s] = 1;
	
	fr(i, 0, n){
		if(mat[s][i]){
			dfs(i);
		}
	}
}


ll fat[110];

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	
	fat[0] = 1;
	fr(i, 1, 102){
		fat[i] = (fat[i-1]*i)%mod;
	}
	
	while(t--){
		scanf("%d", &n);
		fr(i, 0, n){
			scanf("%s", arr[i]);
			size[i] = strlen(arr[i]);
		}
		init();
		
		memset(iguais, 0, sizeof(iguais));
		
		int k = n;
		
		fr(i, 0, n){
			int igual = 1;
			fr(j, 1, size[i]){
				if(arr[i][j] != arr[i][j-1]){
					igual = 0;
					break;
				}
			}
			
			if(igual){
				remover(i);
				iguais[arr[i][0]-'a']++;
				k--;
			}
		}
		
		memset(sizet, 0, sizeof(sizet));
		
		for(int i = head; i != -1; i = prox[i]){
			fr(j, 0, size[i]){
				if(j == 0 || arr[i][j] != arr[i][j-1]){
					temp[i][sizet[i]++] = arr[i][j];
					temp[i][sizet[i]] = '\0'; 
				}
			}
		}
		
		for(int i = head; i != -1; i = prox[i]){
			strcpy(arr[i], temp[i]);
			size[i] = sizet[i];
		}
		
		memset(ponta, 0, sizeof(ponta));
		memset(meio, 0, sizeof(meio));
		
		int ok = 1;
		
		for(int i = head; i != -1; i = prox[i]){
			if(arr[i][0] == arr[i][size[i]-1]){
				ok = 0;
				break;
			}
			fr(j, 0, size[i]){
				if(j == 0 || j == size[i]-1){
					ponta[arr[i][j]-'a']++;
				}else{
					meio[arr[i][j]-'a']++;
				}
			}
		}
		
		if(!ok){
			printf("Case #%d: 0\n", caso++);
			continue;
		}
		
		fr(i, 0, 28){
			if(meio[i] > 1){
				ok = 0;
				break;
			}
			if(meio[i] == 1 && (iguais[i] > 0 || ponta[i] > 0)){
				ok = 0;
				break;
			}
			if(ponta[i] > 2){
				ok = 0;
				break;
			}
		}
		
		if(!ok){
			printf("Case #%d: 0\n", caso++);
			continue;
		}
		
		memset(mat,0, sizeof(mat));
		
		for(int i = head; i != -1; i = prox[i]){
			for(int j = head; j != -1; j = prox[j]){
				if(arr[i][size[i] - 1] == arr[j][0]){
					mat[i][j] = 1;
				}
			}
		}
		
		for(int i = head; i != -1; i = prox[i]){
			ciclo = 0;
			memset(mark,0, sizeof(mark));
			dfs(i);
			if(ciclo){
				ok = 0;
				break;
			}
		}
		
		if(!ok){
			printf("Case #%d: 0\n", caso++);
			continue;
		}
		
		fr(i, 0, 28){
			if(ponta[i] == 2){
				k--;
			}else if(ponta[i] == 0){
				if(iguais[i] > 0) k++;
			}
		}
		
		ll ans = fat[k];
		
		fr(i, 0, 28) ans = (ans*fat[iguais[i]])%mod;
		
		printf("Case #%d: %lld\n", caso++, ans);
	}
	
	return 0;
}

