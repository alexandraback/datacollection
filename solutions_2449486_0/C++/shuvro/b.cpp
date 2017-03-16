#include <iostream>
using namespace std;

#define max 105

int min(int x,int y){
return (x<y)?x:y;
}

int main()
{
int input[max][max],i,j,tmp,arc[max][max],arr[max][max],T,N,M,Cas=1;

cin>>T;
while(T--){
	cin>>N>>M;

	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			cin>>input[i][j];
//row chk
	for(i=0;i<N;i++){
		tmp=input[i][0];
		for(j=0;j<M;j++){
			if(input[i][j]>tmp)
				tmp=input[i][j];
		}
		for(j=0;j<M;j++){
			arr[i][j]=tmp;
		}
	}
//column chk
	for(i=0;i<M;i++){
		tmp=input[0][i];
		for(j=0;j<N;j++){
			if(input[j][i]>tmp)
				tmp=input[j][i];
		}
		for(j=0;j<N;j++){
			arc[j][i]=tmp;
		}
	}
	for(i=0;i<N;i++)
		for(j=0;j<M;j++){
		arr[i][j]=min(arr[i][j],arc[i][j]);
	}
	int f=1;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++){
			if(input[i][j]!=arr[i][j]){
				f=0;
				break;
			}
		}

	cout<<"Case #"<<Cas++<<": "; 
	if(f){
		cout<<"YES\n";
	}else
		cout<<"NO\n";
}

return 0;
}
