#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int A,B;
double P[100005];
void get_data(){
	int i;
	scanf("%d%d",&A,&B);
	for(i=1;i<=A;i++)scanf("%lf",&P[i]);
}
void run(){
	int i;
	double res=1+B+1,temp=1,tres;
	for(i=1;i<=A;i++){
		temp*=P[i];
		tres=A-i+B-i+1+(1-temp)*(B+1);
		if(res<0||res>tres)res=tres;
	}
	printf("%.12lf\n",res);
}
int main(){
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("A-small-attempt0.out","w",stdout);
	int t,i=0;
	scanf("%d",&t);
	while(t--){
		get_data();
		printf("Case #%d: ",++i);
		run();
	}
	return 0;
}
