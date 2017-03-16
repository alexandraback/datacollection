/*
* abdurak
* Google CodeJam 2014 - Round 1C
* Problem A
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
ifstream fin ("A.in");
ofstream fout ("A.out");

int main(){
    int T;
    fin>>T;
    forr(iT,1,T){
        fout<<"Case #"<<iT<<": ";
        long long P,Q;
        char zhar;
        fin>>P>>zhar>>Q;
        while(P%2==0){
            P/=2;
            Q/=2;
        }
        int x=1;
        int cc=1;
        while(Q%2==0){ Q/=2; cc*=2; }
        if(P%Q==0){ P/=Q; Q=1; }
        while(x*2<P) x*=2;
        x=cc/x;
        if(Q!=1) fout<<"impossible";
        else{
        int i=0;
            while(x!=1){
                x/=2;
                i++;
            }
            fout<<i;
        }
        fout<<endl;
    }
	return 0;
}
