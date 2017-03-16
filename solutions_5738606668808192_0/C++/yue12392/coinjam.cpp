#include<iostream>
#include<cstdio>

using namespace std;

int T,n,m, arr[40],factor[12];
long long temp,temp2;
bool flag;

void work(int i){
int j;
	if (m>0){	
		if (i==n){
			j=2; flag=true;
			do
			{
				temp=0;
				for(int k=1;k<=n;k++) temp=temp*j+arr[k];
				temp2=2;
				while((temp2*temp2<temp)&&(temp%temp2!=0)) temp2++;
				if (temp%temp2==0) factor[j]=temp2;
				else flag=false;
				j++; 
			} while ((flag)&&(j<=10));
			if (flag){
				for (int j=1;j<=n;j++) printf("%d",arr[j]);
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
	freopen("coinjam.out","w",stdout);
	
	scanf("%d",&T);
	scanf("%d%d",&n,&m);
	
	arr[1]=1; arr[n]=1;
	
	printf("Case #1:\n");
	work(2);	
	
	return 0;
}
