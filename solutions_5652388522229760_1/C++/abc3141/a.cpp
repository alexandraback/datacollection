#include<iostream>
#include<cstdio>
using namespace std;
int T;
int N;
int A[30];
bool F[10];
int B[30];
int main()
{
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		scanf("%d",&N);
		for(int i=0;i<10;i++)F[i]=false;
		for(int i=0;i<30;i++)A[i]=0;
		for(int i=0;i<30;i++)B[i]=0;
		if(N==0){
			printf("Case #%d: INSOMNIA\n",cas+1);
			continue;
		}
		int NN=N;int index=0;
		while(NN>0){
			A[index]=NN%10;
			B[index]=A[index];
			NN/=10;
			index++;
		}
		while(true){
			bool Flag=false;
			for(int i=29;i>=0;i--){
				if(!Flag&&A[i]==0)continue;
				Flag=true;
				F[A[i]]=true;
			}
			Flag=true;
			for(int i=0;i<10;i++){
				if(!F[i])Flag=false;
			}
			if(Flag){
				bool Flag1=false;
				printf("Case #%d: ",cas+1);
				for(int i=29;i>=0;i--){
					if(!Flag1&&A[i]==0)continue;
					Flag1=true;
					printf("%d",A[i]);
				}
				printf("\n");
				break;
			}
			for(int i=0;i<30;i++){
				A[i]+=B[i];
			}
			int next=0;
			for(int i=0;i<30;i++){
				A[i]+=next;
				next=A[i]/10;
				A[i]%=10;
			}
		}
	}
	return 0;
}
