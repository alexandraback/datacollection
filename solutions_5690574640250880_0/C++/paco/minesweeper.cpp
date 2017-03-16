#include<iostream>
#include<cstdio>

using namespace std;

void nextcomb(int *q,int n,int max) {
	int k=1;
	while(q[n-k]==max-k) {
		k++;
		if(k>n) {
			q[0]=-1;
			return;
		}
	}
	q[n-k]++;
	for(int j=k-1;j>0;j--) {
		q[n-j]=q[n-k]+k-j;
	}
	
}

void setzeros(int *board,int R,int C,int i, int j) {

	for(int k=i-1;k<=i+1;k++) 
		for(int l=j-1;l<=j+1;l++) 
			if(k>=0 && k<R && l>=0 && l<C) 
				if(board[k*C+l]==0) {
					board[k*C+l]=3;
					setzeros(board,R,C,k,l);
				}

}

bool checkboard(int *q,int M,int R,int C) {

	int board[R*C];
	for(int i=0;i<R*C;i++)
		board[i]=0;
	for(int i=0;i<M;i++) 
		board[q[i]]=2;
		
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++) 
			if(board[i*C+j]==2) 
				for(int k=i-1;k<=i+1;k++) 
					for(int l=j-1;l<=j+1;l++) 
						if(k>=0 && k<R && l>=0 && l<C) 
							if(board[k*C+l]==0) board[k*C+l]=-1;
	
		
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++) 
			if(board[i*C+j]==-1) 
				for(int k=i-1;k<=i+1;k++) 
					for(int l=j-1;l<=j+1;l++) 
						if(k>=0 && k<R && l>=0 && l<C) 
							if(board[k*C+l]==0) board[i*C+j]=1;
	
	
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++) 
			if(board[i*C+j]==-1) return false;
			
	int k=0;
	while(board[k]) k++;
	
	int i=k/C;int j=k%C;
	
	board[i*C+j]=3;
	setzeros(board,R,C,i,j);
	
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++) 
			if(board[i*C+j]==0) return false;
			
	bool clicked=false;
	
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			if(board[i*C+j]==2) cout<<"*";
			else {
				if(board[i*C+j]==3 && !clicked) {
					clicked=true;
					cout<<"c";
				}
				else cout<<".";
			}
		}
		cout<<endl;
	}
}

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=0; n<nCases; n++) {
		int R,C,M;
		cin>>R;
		cin>>C;
		cin>>M;
		
		cout<<"Case #"<<n+1<<": ";
		cout<<endl;
		
		if(M==R*C-1) {
			for(int i=0;i<R;i++) {
				for(int j=0;j<C;j++) {
					if(i==0 && j==0) cout<<"c";
					else cout<<"*";
				}
				cout<<endl;
			}
			continue;
		}
		
		int q[M];
		for(int i=0;i<M;i++) q[i]=i;
		bool found=false;
		while(q[0]!=-1) {
			if(checkboard(q,M,R,C)) {
				found=true;
				break;
			}
			nextcomb(q,M,R*C);		
		}
		
		if(!found) cout<<"Impossible\n";
	}

	return 0;
}
