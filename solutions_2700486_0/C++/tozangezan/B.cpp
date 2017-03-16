#include<stdio.h>
#include<algorithm>
using namespace std;
int ABS(int a){return max(a,-a);}
double C[4000][4000];
int main(){
	int a;
	scanf("%d",&a);
	int T=0;
	C[0][0]=1;
	C[1][0]=C[1][1]=1.0/2;
	for(int i=2;i<4000;i++){
		C[i][0]=C[i-1][0]/2;
		C[i][i]=C[i-1][i-1]/2;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])/2;
		}
	}
	while(a--){
		T++;
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		int V=0;
		int t=0;
		for(int i=1;;i+=4){
			V+=2;
			t+=i;
			if(t>b){
				V-=2;
				t-=i;
				t=b-t;
				break;
			}
		}
		//printf("%d\n",t);
		if(ABS(c)+d<V){
			printf("Case #%d: 1.0\n",T);
			continue;
		}
		if(ABS(c)+d>V||c==0||d>=t){
			printf("Case #%d: 0.0\n",T);
			continue;
		}
		if(d<t-V){
			printf("Case #%d: 1.00\n",T);
			continue;
		}
		double ret=0;
		//double now=1;
	//	if(t>V){
	//		int A=t-V;
	//		t-=A*2;
	//		d-=A;
	//	}
		for(int i=d+1;i<=t;i++){
			ret+=C[t][i];
		}
		printf("Case #%d: %.8f\n",T,ret);
	}
}