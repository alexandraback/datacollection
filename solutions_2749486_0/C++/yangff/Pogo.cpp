#include <cstdio>
#include <cstdlib>
void north(){
	printf("SN");
}
void south(){
	printf("NS");
}
void east(){
	printf("WE");
}
void west(){
	printf("EW");
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);

	int T;scanf("%d",&T);
	for (int i = 1; i<= T ;i++){
		printf("Case #%d: ",i);
		int xx,yy;scanf("%d%d",&xx,&yy);
		for (int j = 0;j<abs(xx);j++){
			if (xx<0) west(); else east();
		}
		for (int j = 0;j<abs(yy);j++){
			if (yy<0) south(); else north();
		}
		printf("\n");
	}
}