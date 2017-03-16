#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool can;
bool is[2][20];
int num[20];
int T;
int N;

int main(){
	freopen("C_in.txt","r",stdin);
	freopen("C_out.txt","w",stdout);
	cin >> T;
	for(int cas = 1;cas <= T;++cas){
		memset(is,0,sizeof(is));
		can = false;
		cin >> N;
		for(int i = 0;i < N;++i)
			cin >> num[i];
		for(int x = 1;x < (1 << 20);++x){
			for(int i = 0;i < 20;++i){
				is[0][i] = (1 << i)&x;
			}
			int sum1 = 0;
			for(int i = 0;i < 20;++i){
				if(is[0][i])
					sum1 += num[i];
			}
			for(int y = 1;y < (1 << 20);++y){
				for(int j = 0;j < 20;++j){
						is[1][j] = (1 <<j)&y;
				}
				int sum2 = 0;
				for(int i= 0 ;i < 20;++i){
					if(!is[0][i] && is[1][i])
						sum2 += num[i];
				}
				if(sum1 == sum2){
					can = true;
					break;
				}
			}
			if(can)
				break;
		}
		printf("Case #%d:\n",cas);
		int s = 0;
		int cnt = 0;
		for(int i = 0;i < 20;++i){
			if(is[0][i]){
				if(cnt == 0)
					s = i;
				++cnt;
			}
		}
		if(cnt == 1){
			printf("%d\n",num[s]);
		}
		else
			printf("%d",num[s]);
		for(int i = s + 1;i < 20;++i){
			if(is[0][i])
				printf(" %d",num[i]);
		}
		if(cnt != 1)
			printf("\n");
		s = 0;
		cnt = 0;
		for(int i = 0;i < 20;++i){
			if(!is[0][i] && is[1][i]){
				if(cnt == 0)
					s = i;
				++cnt;
			}
		}
		if(cnt == 1){
			printf("%d\n",num[s]);
		}
		else
			printf("%d",num[s]);
		for(int i = s + 1;i < 20;++i){
			if(!is[0][i] && is[1][i])
				printf(" %d",num[i]);
		}
		if(cnt != 1)
			printf("\n");
	}
	return 0;
}

