/*
* abdurak
* Google CodeJam 2015 - Qualification Round
* Problem D
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
ifstream fin ("D.in");
ofstream fout ("D.out");

int main(){
    int T;
    fin>>T;
    forr(iT,1,T){
        int X,R,C;
        fin>>X>>R>>C;
        if(R>C){
            int t=R;
            R=C;
            C=t;
        }
        if(X>6 || (R*C)%X>0 || R*C<X){
            fout<<"Case #"<<iT<<": RICHARD"<<endl;
            continue;
        }
        switch(X){
            case 1:
                fout<<"Case #"<<iT<<": GABRIEL"<<endl;
                break;
            case 2:
                fout<<"Case #"<<iT<<": GABRIEL"<<endl;
                break;
            case 3:
                if(R==1) fout<<"Case #"<<iT<<": RICHARD"<<endl;
                else fout<<"Case #"<<iT<<": GABRIEL"<<endl;
                break;
            case 4:
                if(R<=2) fout<<"Case #"<<iT<<": RICHARD"<<endl;
                else fout<<"Case #"<<iT<<": GABRIEL"<<endl;
                break;
            case 5:
                if(R<=2) fout<<"Case #"<<iT<<": RICHARD"<<endl;
                else fout<<"Case #"<<iT<<": GABRIEL"<<endl;
                break;
            case 6:
                if(R<=3 || R*C==16) fout<<"Case #"<<iT<<": RICHARD"<<endl;
                else fout<<"Case #"<<iT<<": GABRIEL"<<endl;
                break;
        }
    }
	return 0;
}
