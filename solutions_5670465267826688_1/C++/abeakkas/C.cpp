/*
* abdurak
* Google CodeJam 2015 - Qualification Round
* Problem C
* Haydi bakalim...
*      ***
*     *   *
*    *     *
*    *     *
*     *****
* (Poorly drawn easter egg)
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
typedef unsigned long long ull;

//(int *)calloc(1000000,sizeof(int));
//(int *)malloc(1000000*sizeof(int));

using namespace std; 
ifstream fin ("C.in");
ofstream fout ("C.out");

int m[4][4]={  
    { 1, 2, 3, 4},
    { 2,-1, 4,-3},
    { 3,-4,-1, 2},
    { 4, 3,-2,-1}
};

int sign(int x){ 
    return x/abs(x);
}

int multiply(int a,int b){
    return m[abs(a)-1][abs(b)-1]*sign(a)*sign(b);
}

int power(int b,ull e){
    if(e==1) return b;
    if(e%2){
        return multiply(power(b,e-1),b);
    }else{
        int x=power(b,e/2);
        return multiply(x,x);
    }
}

int main(){
    int T;
    fin>>T;
    forr(iT,1,T){
        int L;
        ull X;
        fin>>L>>X;
        int S[L];
        char ch;
        int total=1;
        for(int i=0;i<L;i++){
            fin>>ch;
            switch(ch){
                case '1':S[i]=1;break;
                case 'i':S[i]=2;break;
                case 'j':S[i]=3;break;
                case 'k':S[i]=4;break;
            }
            total=multiply(total,S[i]);
        }
        if(power(total,X)!=-1){
            fout<<"Case #"<<iT<<": NO"<<endl;
            continue;
        }
        bool flag=true;
        int state=0;
        total=1;
        for(int tour=0;tour<X && tour<8 && flag;tour++){// 8 is the magic number
            for(int i=0;i<L;i++){
                total=multiply(total,S[i]);
                if(state==0 && total==2){
                    state++;
                    total=1;
                }
                if(state==1 && total==3){
                    fout<<"Case #"<<iT<<": YES"<<endl;
                    flag=false;
                    break;
                }
            }
        }
        if(flag) fout<<"Case #"<<iT<<": NO"<<endl;
    }
	return 0;
	// https://www.youtube.com/watch?v=rgyBKqWPN1A
}
