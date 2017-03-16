#include<iostream>
#include<cstdio>

using namespace std;

int T,n,m, arr[40],factor[12];
long long temp,temp2;
bool flag;

void work(int i){
int tot,tot2,tmp;
	if (m>0){	
		if (i==n){
			flag=true;
			tot=0;
			for(int j=1;j<=n;j++) tot+=arr[j];
			if (tot%6!=0) flag=false; // base 10,4,9,7,5,3
			if (flag){
				tot2=0; tmp=-1;
				for(int j=1;j<=n;j++){
					tot2+=(arr[j]*tmp); tmp*=(-1);
				}			
				if (tot2%3!=0) flag=false; //base 2,8
			} 
			if (flag){
				if (tot%5==0) factor[6]=5;
				else if(tot2%7==0) factor[6]=7; //base 6
				else flag=false;
			}
			if (flag){
				for (int j=n;j>=1;j--) printf("%d",arr[j]);
				for (int j=2;j<=10;j++) printf(" %d",factor[j]);
				printf("\n");
				m--;
			} 
		}
		else {
			for(int j=0;j<=1;j++) {
				arr[i]=j; work(i+1);
			}
		}
	}
}

int main(){
	freopen("coinjam.in","r",stdin);
	freopen("coinjam2.out","w",stdout);
	
	scanf("%d",&T);
	scanf("%d%d",&n,&m);
	
	arr[1]=1; arr[n]=1; 
	
	printf("Case #1:\n");
	factor[10]=3; factor[4]=3; factor[3]=2; factor[5]=2; factor[7]=2; factor[9]=2; factor[8]=3; factor[2]=3; 
	work(2);	
	
	return 0;
}
