#include<stdio.h>
#include<algorithm>
using namespace std;
char ret[100][100];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		printf("Case #%d:\n",t+1);
		// hand solve
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				ret[i][j]=0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				ret[i][j]='.';
		if(a==1){
			for(int i=0;i<c;i++)ret[0][i]='*';
			ret[0][b-1]='c';
			printf("%s\n",ret[0]);
			continue;
		}
		if(b==1){
			for(int i=0;i<c;i++)ret[i][0]='*';
			ret[a-1][0]='c';
			for(int i=0;i<a;i++)printf("%s\n",ret[i]);
			continue;
		}
		if(c==a*b-1){
			for(int i=0;i<a;i++)
				for(int j=0;j<b;j++)ret[i][j]='*';
			ret[0][0]='c';
			for(int i=0;i<a;i++)printf("%s\n",ret[i]);
			continue;
		}
		if(c%b!=b-1&&c<=(a-2)*b){
			for(int i=0;i<c;i++)ret[i/b][i%b]='*';
			ret[a-1][b-1]='c';
			for(int i=0;i<a;i++)printf("%s\n",ret[i]);
			continue;
		}
		if(c%a!=a-1&&c<=(b-2)*a){
			for(int i=0;i<c;i++)ret[i%a][i/a]='*';
			ret[a-1][b-1]='c';
			for(int i=0;i<a;i++)printf("%s\n",ret[i]);
			continue;
		}
		if(c<=(a-2)*(b-2)){
			for(int i=0;i<c;i++)ret[i/(b-2)][i%(b-2)]='*';
			ret[a-1][b-1]='c';
			for(int i=0;i<a;i++)printf("%s\n",ret[i]);
			continue;
		}
		bool ok=false;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				ret[i][j]='*';
		for(int i=2;!ok&&i<=a;i++){
			for(int j=2;!ok&&j<=b;j++){
				if(i*j>=a*b-c&&i*j-(i-2)*(j-2)<=a*b-c){
					for(int k=0;k<i;k++)
						for(int l=0;l<j;l++)
							ret[k][l]='.';
					int v=i*j-(a*b-c);
					for(int k=0;k<v;k++){
						ret[i-1-k/(j-2)][j-1-k%(j-2)]='*';
					}
					ret[0][0]='c';
					for(int k=0;k<a;k++)printf("%s\n",ret[k]);
					ok=true;
				}
			}
		}
		if(ok)continue;
		fprintf(stderr,"%d\n",t+1);
		printf("Impossible\n");
		
	}
}
