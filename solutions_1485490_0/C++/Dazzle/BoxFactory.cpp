#include<iostream>
#include<fstream>
using namespace std;
int A[200];
long long a[200];
int B[200];
long long b[200];
int Ain[200];
long long ain[200];
int Bin[200];
long long bin[200];
long long periodsum(int i,int start,int end){
	long long sum=0;
	for(int j=start;j<end;j++){
		if(A[i]==B[j]){
			sum+=b[j];
		}
	}
	if(sum>a[i]){
		sum=a[i];
	}
	if(A[i]==B[end]){
		if((a[i]-sum)>b[end]){
			sum+=b[end];
			b[end]=0;
		}
		else{
			b[end]-=(a[i]-sum);
			sum=a[i];
		}
	}
	return sum;
}
long long sum(int p[],int N,int M)
{
	long long s=0;
	int m=0;
	if(N==1){
		s+=periodsum(0,0,M);
	}
	else if(N==2){
		s+=periodsum(0,0,p[0]);
		s+=periodsum(1,p[0],M-1);
	}
	else if(N==3){
		s+=periodsum(0,0,p[0]);
		s+=periodsum(1,p[0],p[1]);
		s+=periodsum(2,p[1],M-1);
	}
	return s;
}
int main()
{
	ifstream fin;
	fin.open("E:\\codejam\\input.txt");
	ofstream fout;
	fout.open("E:\\codejam\\output.txt");
	int T;
	fin>>T;
	int N,M;
	int p[3];
	long long match;
	for(int t=1;t<=T;t++){
		fin>>N>>M;
		for(int i=0;i<N;i++){
			fin>>ain[i]>>Ain[i];
		}
		for(int i=0;i<M;i++){
			fin>>bin[i]>>Bin[i];
		}
		long long max_match=0;
		for(int i=0;i<M;i++){
			for(int j=i;j<M;j++){
				for(int k=0;k<N;k++){
					a[k]=ain[k];
					A[k]=Ain[k];
					/*
					if(t==5)
						cout<<a[k]<<endl;*/
				}
				for(int k=0;k<M;k++){
					b[k]=bin[k];
					B[k]=Bin[k];
				}
				p[0]=i;p[1]=j;
				match=sum(p,N,M);
				
				if(t==5)
					cout<<i<<" "<<j<<" "<<match<<endl;
				if(max_match<match){
					max_match=match;
					//cout<<max_match<<endl;
				}
			}
		}
		fout<<"Case #"<<t<<": "<<max_match<<endl;
		
	}
	

}