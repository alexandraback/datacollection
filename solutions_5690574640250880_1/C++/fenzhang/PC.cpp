#include<stdio.h>
#include<algorithm>
using namespace std;
char a[100][100];
void sol(int uuu){
	int r,c,m,isw=0,imp=0;
	scanf("%d %d %d",&r,&c,&m);
	m=r*c-m;
	if(r>c){
		swap(r,c);
		isw=1;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			a[i][j]='*';
		}
	}
	if(r==1){
		for(int i=0;i<m;i++){
			a[0][i]='.';
		}
		a[0][0]='c';
	}
	else if(m==1){
		a[0][0]='c';
	}
	else if(m==2||(m%2&&m<9)){
		imp=1;
	}
	else if(r==2){
		if(m%2){
			imp=1;
		}
		else{
			for(int i=0;i<m/2;i++){
				a[0][i]='.';
				a[1][i]='.';
			}
			a[0][0]='c';
		}
	}
	else{
		a[0][0]=a[0][1]=a[1][0]=a[1][1]='.';
		m-=4;
		for(int i=2,j=2;m>=2&&(i<r||j<c);){
			if(i==j&&i<r){
				a[i][0]=a[i][1]='.';
				m-=2;
				i++;
			}
			else if(j<c){
				a[0][j]=a[1][j]='.';
				m-=2;
				j++;
			}
		}
		for(int i=2;m>0&&i<r;i++){
			for(int j=2;m>0&&j<c;j++){
				a[i][j]='.';
				m--;
			}
		}
		a[0][0]='c';
	}
	if(isw){
		for(int i=0;i<c;i++){
			for(int j=i;j<c;j++){
				swap(a[i][j],a[j][i]);
			}
		}
		swap(r,c);
	}
	printf("Case #%d:\n",uuu);
	if(imp){
		puts("Impossible");
	}
	else{
		for(int i=0;i<r;i++){
			a[i][c]=0;
			puts(a[i]);
		}
	}
}
int main(){
	freopen("C-large.in","r",stdin);
	freopen("Cout-l.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		sol(ti);
	}
	return 0;
}
