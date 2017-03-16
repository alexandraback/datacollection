/*
* abdurak
* Google CodeJam 2015 - Qualification Round
* Problem A
* Haydi bakalim...
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
        int M;
        fin>>M;
        char ch;
        int tot=0;
        int x=0;
        for(int i=0;i<=M;i++){
            if(tot<i){
                x+=i-tot;
                tot=i;
            }
            fin>>ch;
            tot+=ch-'0';
        }
        fout<<"Case #"<<iT<<": "<<x<<endl;
    }
	return 0;
}
