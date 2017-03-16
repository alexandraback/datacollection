#include <cstdio>
#include <cstdlib>
bool YN,YN_2;
char s[50][50];
int T,M,R,C,i,j,k,l,m,x,y;
int main (){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("GCJ14_Q_Q3_output.out","w",stdout);
	scanf("%d",&T);
	for (i=1;i<=T;i++){
		scanf("%d %d %d",&R,&C,&M);
		YN=1;
		for (j=0;j<R;j++) for (k=0;k<C;k++) s[j][k]='.';
		if (R==1){
			s[0][0]='c';
			for (j=C-1;j>=C-M;j--) s[0][j]='*';
		} else if (C==1){
			s[0][0]='c';
			for (j=R-1;j>=R-M;j--) s[j][0]='*';
		} else if (M==0){
			s[0][0]='c';
		} else if (M==R*C-1){
			for (j=0;j<R;j++) for (k=0;k<C;k++) s[j][k]='*';
			s[0][0]='c';
		} else if (R==C && R>3 && M==R-1){
			s[0][0]='c';
			for (j=C-1;j>C-M;j--) s[R-1][j]='*';
			s[R-2][C-1]='*';
		} else if (R==2){
			if (M<R*C-3 && M%2==0){
				s[0][0]='c';
				for (j=C-1;j>=C-M/2;j--){
					s[0][j]='*';
					s[1][j]='*';
				}
			} else {
				YN=0;
			}
		} else if (C==2){
			if (M<R*C-3 && M%2==0){
				s[0][0]='c';
				for (j=R-1;j>=R-M/2;j--){
					s[j][0]='*';
					s[j][1]='*';
				}
			} else {
				YN=0;
			}
		} else {
			YN=0;
			for (j=2;j<=R;j++){
				for (k=2;k<=C;k++){
					if (YN==0){
						for (l=0;l<R;l++) for (m=0;m<C;m++) s[l][m]='*';
						for (l=0;l<j;l++) for (m=0;m<k;m++) s[l][m]='.';
						s[0][0]='c';
						YN_2=0;
						for (l=0;l<j-1;l++){
							for (m=0;m<k-1;m++){
								if (M==R*C-j*k+l*m){
									x=l;
									y=m;
									YN_2=1;
								}
							}
						}
						if (YN_2){
							for (l=j-1;l>=j-x;l--) for (m=k-1;m>=k-y;m--) s[l][m]='*';
							YN=1;
						}
					}
				}
			}
		}
		printf("Case #%d:\n",i);
		if (YN){
			for (j=0;j<R;j++){
				for (k=0;k<C;k++){
					printf("%c",s[j][k]);
				}
				printf("\n");
			}
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}
