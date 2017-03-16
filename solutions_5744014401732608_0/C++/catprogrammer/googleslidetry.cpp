#include<bits/stdc++.h>
using namespace std;
int main (){
		ifstream cin("Bsmall.in");
ofstream cout("AE.txt");
	int x;
	cin>>x;
	int y;
	int target;
	for(int i=1;i<=x;i++){
		cout<<"Case #"<<i<<": ";
		cin>>y>>target;
		int count[y];
		int array[y][y];
		for(int k=0;k<y;k++){
			count[k]=1;
			
		}
		for(int k=0;k<y;k++){
			for(int l=0;l<y;l++){
				array[k][l]=0;
			}
		}
		for(int k=0;k<y-1;k++){
			array[k][k+1]=1;
		}	
		target--;
		int pointer1=y-2;
		int pointer2;
		int large=0;
		int check=0;
		
	//	target--;
		while(target!=0){
		//	cout<<pointer1<<endl;
		pointer2=0;
		large=0;
		for(int k=pointer1+1;k<y;k++){
			//cout<<k<<endl;
			if(array[pointer1][k]==0&&count[k]<=target&&count[k]>=large){
				large=count[k];
				
				pointer2=k;
			}
		}
		if(pointer2==0){
			pointer1--;
			if(pointer1==-1){
			
			cout<<"IMPOSSIBLE"<<endl;
			target=0;
			check=-1;
			
			
			
			
			}
			
			
			
		}else{
			target-=count[pointer2];
			count[pointer1]+=count[pointer2];
		//	cout<<count[pointer1]<<endl;
			array[pointer1][pointer2]=1;
			
		}
		
		
		
		
	}
	if(check==0){
			cout<<"POSSIBLE"<<endl;	
		for(int k=0;k<y;k++){
			for(int l=0;l<y;l++){
				cout<<array[k][l];
			}cout<<endl;
		}
	}

		
	}
}
