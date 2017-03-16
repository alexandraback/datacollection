#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <fstream>

using namespace std;

//ifstream fin("A3.in");
ifstream fin("A-small-attempt1.in");
//ifstream fin("A-large.in");
FILE * fout = fopen("A3.out","w");

int N;
double A[205], S;

bool check(int a, double p){
    double sb=0;
    for(int i=0; i<N; i++){
	if(i==a) continue;
	double cur=A[a]+p-A[i];
	if(cur<0) cur=0;
	sb+=cur;
    }
    return (sb>1-p);
}

void solve(int t){
    fin >> N;
    S=0;
    for(int i=0; i<N; i++){
	fin >> A[i];
	S+=A[i];
    }
    for(int i=0; i<N; i++){
	A[i]/=S;
    }
    
    fprintf(fout,"Case #%d: ",t);
    if(t==1){

    }
    for(int i=0; i<N; i++){
	//double P=(2*S - N*A[i]) / (N*S);
	/*for(int j=0; j<N; j++){
	    if(i==j) continue;
	    P = max(P, (1.0 - ((A[i]-A[j])/S) )/2.0 );
	}*/
	//if(P<0) P=0;
	double lo=0, hi=1.0, mid=(lo+hi)/2;
	while(mid-lo>.000000001){
	    if(check(i,mid)){
		hi=mid;
	    }else{
		lo=mid;
	    }
	    mid=(lo+hi)/2;
	}
	fprintf(fout,"%.6f", 100*mid);
	if(i==N-1){
	    fprintf(fout,"\n");
	}else{
	    fprintf(fout," ");
	}
    }

    
}

int main(){
    int T; fin >> T;
    for(int i=0; i<T; i++){
	solve(i+1);
    }
}
