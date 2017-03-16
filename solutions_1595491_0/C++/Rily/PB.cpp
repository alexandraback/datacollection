#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int test(vector<int>& v,int T,int S,int p){
	int map[26];
	int count=0;
	for(int j=0;j<T;j++){
		int currmax=int(v[j]/3)+int((v[j]%3)!=0);
		if(currmax>=p){
			count++;
		}
		else if((v[j]>=(p-2)*2+p)&&(v[j]>=p)&&(S>0)){
			S--;
			count++;
		}
	}
	return count;
}

void run(){
	int N,T,S,p;
	int result;
	int tmp;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		printf("Case #%d: ",i+1);
		vector<int> v;
		scanf("%d",&T);
		scanf("%d",&S);
		scanf("%d",&p);
		for(int j=0;j<T;j++){
			scanf("%d",&tmp);
			v.push_back(tmp);
		}
		result=test(v,T,S,p);
		printf("%d",result);
		printf("\n");
	}
}


int main(int argc,char** argv){
	run();
	return 0;
}
