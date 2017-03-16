#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;


int K;
int P[110];

int nx[110][27];

char str[110];

int  N;

void init(){

	int i,j;
	int k;

	i = 1, j =0;
	while(i < N){

		if(str[j] == str[i]){
			P[i++] = ++j;
			continue;
		}

		if(j){
			j = P[j-1];
			continue;
		}

		P[i++]=j;
	}


	for(i = 0; i <= N; ++i){

		for(k = 0; k < 26; ++k){
			j = i;

			while(1){
				if(j < N && str[j] == k+'A'){
					nx[i][k] = ++j;
					break;
				}
				if(!j){
					nx[i][k] = 0;
					break;
				}
				j = P[j-1];
			}
		}
	}
}

int mx[110][110];


double ex[110][110];


int S;

int prob[110];

double compute(){


	int i,pr,k;

	for(i = S-1; i >= 0; --i){
		for(pr = 0; pr <= N; ++pr){
			for(k = 0; k < 26; ++k){
				if(!prob[k]) continue;
				mx[i][pr] = max(mx[i][pr],mx[i+1][nx[pr][k]] + (nx[pr][k] >= N));
				ex[i][pr] += (ex[i+1][nx[pr][k]]+(nx[pr][k] >= N))*(prob[k]*1.0/K);
			}
		}
	}

	return mx[0][0]-ex[0][0];

}


int main(){

	int t,T;
	char c;


	scanf("%d",&T);

	for(t =1 ;t <= T; ++t){

		memset(prob,0,sizeof(prob));

		scanf("%d%d%d",&K,&N,&S);
		for(int k = 0; k < K; ++k){
			scanf(" %c",&c);
			++prob[c-'A'];
		}

		scanf("%s",str);


		memset(mx,0,sizeof(mx));
		memset(ex,0,sizeof(ex));
		memset(P,0,sizeof(P));

		init();
		printf("Case #%d: %.7f\n",t,compute());
	}

	return 0;
}
