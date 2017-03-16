//small
#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;



int main(){
	int TC;
	cin>>TC;
	for(int T=1;T<=TC;++T){
		printf("Case #%d:",T);
		int N,M,K;
		cin>>N>>M>>K;
		if(N>M){int temp=N;N=M;M=temp;}
		if(N==1||N==2){
			printf(" %d\n",K);continue;
		}
		if(N==3){
			if(M==3){
				if(K<5){printf(" %d\n",K);}
				else {printf(" %d\n",K-5+4);}
			}
			else if(M==4){
				if(K<5){printf(" %d\n",K);}
				else if(K<8){printf(" %d\n",K-5+4);}
				else {printf(" %d\n",K-8+6);}
			}
			else if(M==5){
				if(K<5){printf(" %d\n",K);}
				else if(K<8){printf(" %d\n",K-5+4);}
				else if(K<11){printf(" %d\n",K-8+6);}
				else {printf(" %d\n",K-11+8);}
			}
			else if(M==6){
				if(K<5){printf(" %d\n",K);}
				else if(K<8){printf(" %d\n",K-5+4);}
				else if(K<11){printf(" %d\n",K-8+6);}
				else if(K<14){printf(" %d\n",K-11+8);}
				else {printf(" %d\n",K-14+10);}
			}
			continue;
		}
		if(N==4){
			if(M==4){
				if(K<5){printf(" %d\n",K);}
				else if(K<8){printf(" %d\n",K-5+4);}
				else if(K<10){printf(" %d\n",K-8+6);}
				else if(K<12){printf(" %d\n",K-10+7);}
				else {printf(" %d\n",K-12+8);}
			}
			else if(M==5){
				if(K<5){printf(" %d\n",K);}
			else if(K<8){printf(" %d\n",K-5+4);}
			else if(K<10){printf(" %d\n",K-8+6);}
			else if(K<12){printf(" %d\n",K-10+7);}
			else if(K<14){printf(" %d\n",K-12+8);}
			else if(K<16){printf(" %d\n",K-14+9);}
			else {printf(" %d\n",K-16+10);}
			}
			continue;
		}
	}
	return 0;
}