#include<stdio.h>
#include<math.h>
int TC,TC_C,i;
unsigned long long R,T,A,B,Res,E,M,S;
double O;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&TC);
	while(TC--){
		printf("Case #%d: ",++TC_C);
		scanf("%llu",&R);
		scanf("%llu",&T);
		A=T/(2*R)+1;
		O=T;
		O/=2.0;
		O=sqrt(O);
		B=O;
		B+=10;
		if(A>B)A=B;
		Res=0,B=1;
		E=A;
		while(B<=E){
			M=(B+E+1)/2;
			S=2*R*M + M*(2*M-1);
			if(S>T)E=M-1;
			else B=M+1,Res=M;
		}
		printf("%llu\n",Res);
	}
}