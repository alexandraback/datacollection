#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int t,i1,i,j,r,c,v,d;
	cin>>t;
	
	for (i1=1;i1<=t;i1++){
		cin>>c;
		cin>>d;
		cin>>v;
		int co=0;
		int ar[31];
		int a1[31][31];
		for(i=0;i<31;i++) ar[i]=0;
		for(i=0;i<31;i++){
		for(j=0;j<31;j++){a1[i][j]=0;}
		
		}
		for(i=0;i<d;i++)
		{cin>>r;
		if (r<=v)
			ar[r]=1;
		}	
		for(i=1;i<=v;i++){
			for(j=i+1;j<=v;j++){
				if(ar[j]==0){
					ar[j]=1;
					co++;		
				
				
				}
				if((i+j)<=v)
					if(a1[j][i]!=1 && ar[i+j]!=1)
						{ar[i+j]=1; a1[i+j][i]=1;a1[i+j][j]=1;}
			
			}
		
		
		}
		
		
		cout<<"Case #"<<i1<<": "<<co<<endl;


	}
	


}

