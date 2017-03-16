#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <fstream>

using namespace std;

//ifstream fin("C3.in");
ifstream fin("C-small-attempt0.in");
//ifstream fin("A-large.in");
FILE * fout = fopen("C3.out","w");

int N;
long long S[505];
int sum[(1<<20)+5];
int last[(1<<21)+5];

void solve(int t){
    fin >> N;
    for(int i=0; i<N; i++){
	fin >> S[i];
    }
    for(int i=0; i<2000000; i++){
	last[i]=-1;
    }
    int a=-1, b=-1;
    for(int i=0; i<(1<<N); i++){
	sum[i]=0;
	for(int j=0; j<N; j++){
	    if((i>>j)%2==1){
		sum[i]+=S[j];
	    }
	}
	if(last[sum[i]]==-1){
	    last[sum[i]]=i;
	}else{
	    a=last[sum[i]];
	    b=i;
	    break;
	}
    }

    fprintf(fout,"Case #%d:\n",t);
    if(a!=-1){
	for(int i=0; i<N; i++){
	    if((a>>i)%2==1)
		fprintf(fout,"%llu ", S[i]);
	}
	fprintf(fout,"\n");
	for(int i=0; i<N; i++){
	    if((b>>i)%2==1)
		fprintf(fout,"%llu ", S[i]);
	}
	fprintf(fout,"\n");
    }else{
	fprintf(fout,"Impossible\n");
    }
}

int main(){
    int T; fin >> T;
    for(int i=0; i<T; i++){
	solve(i+1);
    }
}
