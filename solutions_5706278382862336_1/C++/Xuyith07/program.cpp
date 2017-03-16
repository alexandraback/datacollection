#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdint.h>
#include<map>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

/*
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("test.txt");
	out.open("out.txt");
	in>>CaseNum;
	for(int Case=0;Case<CaseNum;Case++){



	out<<"Case #"<<Case+1<<":";
	}
	return 0;
}
*/

uint64_t P,Q;

uint64_t eu(uint64_t P,uint64_t Q){
	uint64_t R=Q%P;
	while(R!=0){
		Q=P;
		P=R;
		R=Q%P;
	}
	return P;
}

uint64_t p2[43]={0};

int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	//in.open("test.txt");
	in.open("A-large.in");
	out.open("out.txt");
	in>>CaseNum;
	uint64_t K;
	p2[0]=1;
	for(int i=1;i<=42;i++){
		p2[i]=p2[i-1]*2;
	}
	int j,i,ans;
	char c;
	for(int Case=0;Case<CaseNum;Case++){
		in>>P>>c>>Q;
		K=eu(P,Q);
		P/=K;
		Q/=K;
		for(i=0;i<43&&Q>p2[i];i++);
		if(i>=43||Q!=p2[i]||P>Q){
			out<<"Case #"<<Case+1<<": impossible"<<endl;
			continue;
		}
		for(j=0;j<43&&P>p2[j];j++);
		if(P<p2[j])j--;
		ans=i-j;


		out<<"Case #"<<Case+1<<": "<<ans<<endl;
	}
	return 0;
}

