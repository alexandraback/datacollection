#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

struct can{
	int a, b, c;
};

struct can L[100];

int prod[7];

bool poss( can candi, int v){
	int x = candi.a , y = candi.b , z = candi.c;
	if(x==v or y==v or z ==v) return true;
	if(x*y*z==v) return true;
	if(x*y==v or y*z == v or x*z==v) return true;
	return false;
}

int main(){
	int R,N,M, K;
	int p = 0;
	for(int i = 2;i <= 5; i++)
		for(int j = 2; j<=5; j++)
			for(int k =2 ; k<=5 ; k++)
				L[p].a= i, L[p].b = j , L[p++].c = k;

	

	int t;
	scanf("%d",&t);
	while(t--){
		printf("Case #1:\n");
		scanf("%d%d%d%d",&R,&N,&M,&K);
		for(int i =0 ; i < R; i++){
			for(int j = 0 ; j < K ; j++){
				scanf("%d",&prod[j]);
			}
			int score = 0;
			int x = 2 , y = 2,z = 2;
			for(int j = 0 ;  j < 64; j++){
				int q = 0;
				for(int k =0 ; k < 7 ; k++){
					if(poss(L[j],prod[k])) q++;
				}
				if(score < q){
					score = q;
					x = L[j].a, y = L[j].b, z = L[j].c;
					//cout << score << " "<< x << " "<< y << " "<< z << endl;

				}

			}
			printf("%d%d%d\n",x,y,z);

		}
	}

}