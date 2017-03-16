#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

long long int Ac[100];
long long int Bc[100];
int At[100];
int Bt[100];

long long int min(long long int a, long long int b){
	if(a<b)return a;
	else return b;
}
long long int max(long long int a, long long int b){
	if(a>b)return a;
	else return b;
}


void run(){
	int T;
	int N,M;
	char str[10000];
	long long int result;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d%d",&N,&M);
		for(int j=0;j<N;j++){
			scanf("%lld",&(Ac[j]));
			scanf("%d",&(At[j]));
		}
		for(int j=0;j<M;j++){
			scanf("%lld",&(Bc[j]));
			scanf("%d",&(Bt[j]));
		}


		int currt;int curridx;
		int merge[100];
		// compress -- A
		for(int j=0;j<N;j++)merge[j]=j;
		for(int j=0;j<N;j++){
			if(j==0){currt=At[j];curridx=j;}
			else if(At[j]==currt){
				merge[j]=-curridx;
			}
			else{currt=At[j];curridx=j;}
		}
		vector<int> cAt;
		vector<long long int> cAc;
		int shiftA=0;
		for(int j=0;j<N;j++){
			if(merge[j]>=0){
				cAt.push_back(At[j]);
				cAc.push_back(Ac[j]);
			}
			else{
				shiftA++;
				cAc[j-shiftA]+=Ac[j];
			}
		}
		// compress -- B
		for(int j=0;j<N;j++)merge[j]=j;
		for(int j=0;j<N;j++){
			if(j==0){currt=Bt[j];curridx=j;}
			else if(Bt[j]==currt){
				merge[j]=-curridx;
			}
			else{currt=Bt[j];curridx=j;}
		}
		vector<int> cBt;
		vector<long long int> cBc;
		int shiftB=0;
		for(int j=0;j<N;j++){
			if(merge[j]>=0){
				cBt.push_back(Bt[j]);
				cBc.push_back(Bc[j]);
			}
			else{
				shiftB++;
				cBc[j-shiftB]+=Bc[j];
			}
		}

		N=cAc.size();
		M=cBc.size();
/*
		for(int j=0;j<N;j++){
			printf("\t%lld",cAc[j]);
		}
		printf("\n");
		for(int j=0;j<M;j++){
			printf("\t%lld",cBc[j]);
		}
		printf("\n");
*/
		long long int dp[102][102]={0};
		long long int rem[102][102]={0};
		int ni,mi;
		long long int tmp1,tmp2,tmp3;
		for(int j=0;j<N;j++){
			dp[0][j]=0;
			dp[j][0]=0;
			rem[0][j]=0;
			rem[j][0]=0;
		}
		for(int j=1;j<=N;j++){
			for(int k=1;k<=M;k++){
				ni=j-1;
				mi=k-1;
				// matching
				if(cAt[ni]==cBt[mi]){
					// printf("m\n");
					tmp1=min(cAc[ni],cBc[mi])+dp[j-1][k-1];
					rem[j][k]=cAc[ni]-cBc[mi];
				}
				else tmp1=dp[j-1][k-1];
				tmp2=dp[j-1][k];
				tmp3=dp[j][k-1];
				dp[j][k]=max(max(tmp1,tmp2),tmp3);
			}
		}
		long long int currmax=0;
		for(int j=1;j<=N;j++){
			for(int k=1;k<=M;k++){
				if(dp[j][k]>currmax){
					currmax=dp[j][k];
				}
			}
		}

/*
		for(int j=0;j<=N;j++){
			for(int k=0;k<=M;k++){
				printf("\t%lld",dp[j][k]);
			}
			printf("\n");
		}
		printf("\n");
*/
		printf("Case #%d: ",i+1);
		printf("%lld",currmax);
		printf("\n");
	}
}


int main(int argc,char** argv){
	run();
	return 0;
}
