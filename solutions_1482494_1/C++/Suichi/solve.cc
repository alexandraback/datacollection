#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int T;

int N;
int a[1000];
int b[1000];
int cleared[1000];

char out[128];

void get(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&a[i],&b[i]);
		//printf("%d %d\n",a[i],b[i]);
		cleared[i]=0;
	}
	return;
}

void solve(){
	int star=0;
	int played=0;
	int stop=0;

	while(stop==0 && star<2*N){
		stop=1;
		int max_b=-1;
		int max_index;

		for(int i=0;i<N;i++){

			if(cleared[i]==0 && b[i]<=star){
				cleared[i]=2;
				star+=2;
				played++;
				stop=0;
				break;
			}

			if(cleared[i]==1 && b[i]<=star){
				cleared[i]=2;
				star+=1;
				played++;
				stop=0;
				break;
			}

			if(cleared[i]==0 && a[i]<=star){
				if(max_b<b[i]){
					max_b=b[i];
					max_index=i;
				}
			}
		}
//		printf("%d %d\n",max_b,max_index);
		if(stop!=0 && max_b!=-1 && a[max_index] <= star){
			cleared[max_index]=1;
			star++;
			played++;
			stop=0;
		}
	}

	if(star!=2*N){
		strcpy(out,"Too Bad");
	}else{
		sprintf(out,"%d",played);
	}
	return;
}

int main(int argc,char **argv){
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		get();
		solve();
		printf("Case #%d: %s\n",i+1,out);
	}
}
