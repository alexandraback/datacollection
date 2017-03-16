#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("B1.in");
FILE * fout = fopen("B1.out","w");

int norm(int a){
    if(a%3==0) return a/3;
    return (a/3+1);
}

int ex(int a){
    if(a<2) return -1;
    if(a%3==0) return (a/3)+1;
    if(a%3==1) return (a/3)+1;
    return (a/3)+2;
}


void solve(int t){
    int N,S,P;
    fin >> N >> S>> P;
    int safe=0, plus=0;
    for(int i=0; i<N; i++){
	int a; fin >> a;
	if(norm(a)>=P){
	    safe++;
	    continue;
	}
	if(ex(a)>=P){
	    plus++;
	    continue;
	}
    }
    int res=safe+min(plus,S);
    fprintf(fout,"Case #%d: ",t);    
    fprintf(fout,"%d\n", res);
}

int main(){
    int T; fin >> T;
    for(int i=0; i<T; i++){
	solve(i+1);
    }
}
