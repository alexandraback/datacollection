#include<iostream>
#include<fstream>
#define wait system("pause")
#define cin fin
#define cout fout
using namespace std;
ifstream fin("C-small-attempt0.in");
ofstream fout("C-small-attempt0.out");

int T,N,A[505],V[505],f;

void rec(int k){
	if(k==N+1){
		int i,t1=0,t2=0;
		for(i=1;i<=N;i++){
			if(V[i]==1)			t1+=A[i];
			else if(V[i]==2)	t2+=A[i];
		}
		if(t1 && t1==t2){
			for(i=1;i<=N;i++)
				if(V[i]==1)	cout<<A[i]<<" ";
			cout<<endl;
			for(i=1;i<=N;i++)
				if(V[i]==2)	cout<<A[i]<<" ";
			cout<<endl;
			f=1;
		}
		return;
	}
	if(f==0)
		V[k]=1,rec(k+1);
	if(f==0)
		V[k]=2,rec(k+1);
	if(f==0)
		V[k]=0,rec(k+1);
}

void coz(){
	int i,j,k;
	cin>>T;
	for(k=1;k<=T;k++){
		cin>>N;
		for(i=1;i<=N;i++)
			cin>>A[i],V[i]=0;
		f=0;
		cout<<"Case #"<<k<<":"<<endl;
		rec(1);
		if(f==0)
			cout<<"Impossible"<<endl;
	}
}

int main(){
	coz();
}
