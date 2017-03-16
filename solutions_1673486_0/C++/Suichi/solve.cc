#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define sz() size()
typedef long long ll;
int T;

int A;
int B;
double p[100000];
double log[100000];

double out;

void get(){
	scanf("%d %d",&A,&B);
	for(int i=0;i<A;i++){
		scanf("%lf",&p[i]);
	}
	//fprintf(stderr,"%s\n",input);
}
void solve(){
	double right=1.0;
	double mini=1000000;
	for(int i=0;i<=A;i++){
		double go=(B-i)+(A-i)+1+(B+1)*(1-right);
		//printf("%d %f %f\n",i,right,go);
		mini=min(mini,go);
		right*=p[i];
	}
	mini=min(mini,(double)(B+2));
	out=mini;
}

int main(int argc,char **argv){
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		get();
		solve();
		printf("Case #%d: %f\n",i+1,out);
	}
}
