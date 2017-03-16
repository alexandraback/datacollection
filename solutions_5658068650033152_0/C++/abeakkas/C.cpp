/*
* abdurak
* Google CodeJam 2014 - Round 1C
* Problem C
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>

#define pi pair<int,int>
#define vpi vector<pair<int,int> >

#define forn(i,n) for(int i=0;i<n;i++)
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define forn2(i,ni,j,nj) forn(i,ni) forn(j,nj)
//DEBUGGING
#define _s cout<<
#define _d <<" "<<
#define _e <<endl;
long long INF=100000000000LL;

//(int *)calloc(1000000,sizeof(int));
//(int *)malloc(1000000*sizeof(int));

using namespace std; 
ifstream fin ("C.in");
ofstream fout ("C.out");

int N,M,K;

int minn;

void rec(int a,int b,int k,int used,int area,int bos){
    //<<a<<" "<<b<<" "<<k _d used _d area <<" "<<(K-area>=b-a-1+(b-a==1)+(b-a==0)*2)<<endl;
    if(a==0 || b==M+1 || a>b || k>N || area>K) return;
    rec(a-1,b-1,k+1,used+2-(a==b),area+b-a+1,bos+b-a-1);
    rec(a-1,b+1,k+1,used+2-(a-1==b+1),area+b-a+3,bos+b-a+1);
    rec(a,b-1,k+1,used+2-(a==b-1),area+b-a,bos+b-a-2);
    rec(a,b,k+1,used+2-(a==b),area+b-a+1,bos+b-a-1);
    rec(a,b+1,k+1,used+2-(a==b+1),area+b-a+2,bos+b-a);
    rec(a+1,b-1,k+1,used+2-(a+1==b-1),area+b-a-1,bos+b-a-3);
    rec(a+1,b+1,k+1,used+2-(a==b),area+b-a+1,bos+b-a-1);
    if(K-area<=b-a+1+(a!=1)+(b!=M)+bos && K-area>=b-a-1+(b-a==1)+(b-a==0)*2){
        if(used+K-area<minn) minn=used+K-area;
    }
}

int main(){
    int T;
    fin>>T;
    forr(iT,1,T){
        fout<<"Case #"<<iT<<": ";
        fin>>N>>M>>K;
        minn=100000000;
        forr(i,1,M) forr(j,i,M) rec(i,j,2,j-i+1,j-i+1,0);
        if(N==1 || M==1) minn=K;
        if(K==1 ||K==2 ||K==3 ||K==4) minn=K;
        fout<<minn;
        fout<<endl;
    }
    int i;
    //cin>>i;
	return 0;
}
