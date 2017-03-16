#include<cstdio>
const int maxn(60);

int T, N, M, B;
bool reverse;
char ans[maxn][maxn];

void print(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
}

void printr(){
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			printf("%c", ans[j][i]);
		printf("\n");
	}
}

int main()
{
	freopen("C.in", "r", stdin);
	
	scanf("%d", &T);
	for(int o=0; o<T; o++){
		printf("Case #%d:\n", o+1);
		
		scanf("%d%d%d", &N, &M, &B);
		int rest = N*M-B;
		for(int i=0; i<maxn; i++)
			for(int j=0; j<maxn; j++)
				ans[i][j] = '*';
		ans[0][0] = 'c';
		
		if (rest == 1){
			print();
			continue;
		}
		
		reverse = 0;
		if (N > M){
			N^=M^=N^=M;
			reverse = 1;
		}
		
		if (N==1){
			if (M==1) {print(); continue;}
			for(int i=1; i<rest; i++)
				ans[0][i] = '.';
			if (reverse) printr(); else print();
			continue;
		}
		
		if (N==2){
			if (rest < 4 || (rest&1)){
				printf("Impossible\n");
				continue;
			}
			ans[1][0] = '.';
			for(int i=1; i<rest/2; i++)
				ans[0][i] = ans[1][i] = '.';
				
			if (reverse) printr(); else print();
			continue;
		}

		if (rest == 2 || rest == 5 || rest == 7 || rest == 3){
			printf("Impossible\n");
			continue;
		}
		
		if (rest == 4){
			ans[0][1] = ans[1][0] = ans[1][1] = '.';
			if (reverse) printr(); else print();
			continue;
		}
		
		if (rest == 6){
			ans[0][1] = 'c';
			ans[0][0] = ans[0][2] = ans[1][0] = ans[1][1] = ans[1][2] = '.';
			if (reverse) printr(); else print();
			continue;
		}
		
		rest -= 8;
		ans[0][1] = ans[0][2] = ans[1][0] = ans[1][1] = ans[1][2] = ans[2][0] = ans[2][1] = '.';
		for(int i=3; i<M; i++)
			if (rest >= 2){
				ans[0][i] = ans[1][i] = '.';
				rest -= 2;
			} else break;
		if (!rest){
			if (reverse) printr(); else print();
			continue;		
		}
		if (rest == 1){
			ans[2][2] = '.';
			if (reverse) printr(); else print();
			continue;			
		}
		
		for(int i=3; i<N; i++)
			if (rest >= 2){
				ans[i][0] = ans[i][1] = '.';
				rest -= 2;
			} else break;
		if (!rest){
			if (reverse) printr(); else print();
			continue;			
		}
		
		for(int i=2; i<N; i++)
			for(int j=2; j<M; j++)
				if (rest){
					ans[i][j] = '.';
					rest--;
				} else goto Label1;
		Label1:
		if (reverse) printr(); else print();
	}
	return 0;
}
