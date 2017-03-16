#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 2000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);


		int worn[30][30];
		int J, P, S, K;
		scanf("%d%d%d%d", &J, &P, &S, &K);
		
		memset(worn,0,sizeof(worn));
		int num = 0;

		for(int i = 0; i < S; i++){
			for(int j = 0; j < P; j++){
				for(int k = 0; k < J; k++){
					if(worn[i][j+S] >= K || worn[i][k+S+P] >= K || worn[j+S][k+S+P] >= K) continue;  
					worn[i][j+S] +=1;
					worn[i][k+S+P] +=1;
					worn[j+S][k+S+P] +=1;
					num++;
				}
			}
		}

		printf("%d\n", num);
		memset(worn,0,sizeof(worn));
		for(int i = 0; i < S; i++){
			for(int j = 0; j < P; j++){
				for(int k = 0; k < J; k++){
					if(worn[i][j+S] >= K || worn[i][k+S+P] >= K || worn[j+S][k+S+P] >= K) continue;  
					printf("%d %d %d\n", k+1, j+1, i+1);
					worn[i][j+S] +=1;
					worn[i][k+S+P] +=1;
					worn[j+S][k+S+P] +=1;
					// num++;
				}
			}
		}
		
	}
}