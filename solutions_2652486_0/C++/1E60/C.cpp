#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

char sol_str[100];
double Vmin=-1;

int check(int n,int prod,int N,int *use,int *sol)
{
	int ret;
	if (n==N){
		int P=1;
		int i;
		for (i=0;i<N;i++){
			if (use[i])P*=sol[i];
		}
		if (prod==P)return 1;
		return 0;
	}
	use[n]=0;
	ret=check(n+1,prod,N,use,sol);
	if (ret)return 1;
	use[n]=1;
	return check(n+1,prod,N,use,sol);
}

void search(int n,int N,int M,int K,int *prods,int *sol)
{
	if (n==N){
		//ありえるsolutionであるかprodsから検証
		int i;
		int use_arr[N];
		for (i=0;i<K;i++){
			if (!check(0,prods[i],N,use_arr,sol))return;
		}
		//tmp_solを出力
		char str1[13],str2[2];
		*str1='\0';
		for (i=0;i<N;i++){
			sprintf(str2,"%d",sol[i]);
			strcat(str1,str2);
		}
		//fprintf(stderr,"Possible: %s\n",str1);
		//分散を計算
		double E,V;
		int sol_num[M+1];
		memset(sol_num,0,sizeof(sol_num));
		for (i=0;i<N;i++){
			sol_num[sol[i]]++;
		}
		E=0;
		for (i=2;i<=M;i++){
			E+=sol_num[i];
		}
		E/=M-2+1;
		double d;
		V=0;
		for (i=2;i<=M;i++){
			d=E-sol_num[i];
			V+=d*d;
		}
		if (Vmin<0 || V<Vmin){//分散が小さいものを選ぶ
			//fprintf(stderr,"%lf %lf\n",V,Vmin);
			Vmin=V;
			strcpy(sol_str,str1);
		}
		return;
	}
	int cand;
	int candmin=2;
	if (n>0){candmin=sol[n-1];}
	for (cand=candmin;cand<=M;cand++){
		sol[n]=cand;
		search(n+1,N,M,K,prods,sol);
	}
}

int main(void)
{
	int tc,T;
	scanf("%d\n",&T);
	for (tc=1;tc<=T;tc++){
		int i;
		int R,N,M,K;
		int r;
		int prods[12];
		printf("Case #1:\n");
		scanf("%d %d %d %d\n",&R,&N,&M,&K);
		for (r=0;r<R;r++){
			Vmin=-1;
			for (i=0;i<K;i++){
				scanf("%d ",&prods[i]);
			}
			int tmp_sol[12];
			search(0,N,M,K,prods,tmp_sol);
			printf("%s\n",sol_str);
		}
	}
	return 0;
}
