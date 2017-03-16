#include<iostream>
#include<fstream>
#define cin fin
#define cout fout
#define wait system("pause")
using namespace std;
ifstream fin("A-small-attempt1.in");
FILE *out;

int T,N;
double A[205],t,R;

double kont(int ind){
	double s=A[ind],bas=0.0,son=1.0,ort;
	while(1){
		if(son-bas<=0.00000001)	return bas;
		ort=(bas+son)/2;
		if( s+(t*ort)>=R )
			son=ort;
		else
			bas=ort;
	}
}

double bs(int ind){
	int i;
	double s=A[ind],bas=0.0,son=1.0,ort,top;
	while(1){
		if(son-bas<=0.00000001)	return bas*100;
		ort=(bas+son)/2;
		R=s+(t*ort);
		top=0.0;
		for(i=1;i<=N;i++)
			if(i!=ind)
				top+=kont(i);
		if(top+ort>=1.0)
			son=ort;
		else
			bas=ort;
	}
}

void coz(){
	int i,j,k;
	cin>>T;
	for(k=1;k<=T;k++){
		cin>>N;
		t=0.0;
		for(i=1;i<=N;i++)
			cin>>A[i],t+=A[i];
		fprintf(out,"Case #%d: ",k);
		for(i=1;i<=N;i++)
			fprintf(out,"%lf ",bs(i));
		fprintf(out,"\n");
	}
//	wait;
}

int main(){
	out=fopen("A-small-attempt1.out","w");
	coz();
}
