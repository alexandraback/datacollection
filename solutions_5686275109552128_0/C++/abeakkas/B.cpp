/*
* abdurak
* Google CodeJam 2015 - Qualification Round
* Problem B
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

//DEBUGGING
#define _s cout<<
#define _d <<" "<<
#define _e <<endl;

//(int *)calloc(1000000,sizeof(int));
//(int *)malloc(1000000*sizeof(int));

using namespace std; 
ifstream fin ("B.in");
ofstream fout ("B.out");

int main(){
    int T;
    fin>>T;
    for(int iT=1;iT<=T;iT++){
        int D;
        fin>>D;
        int P[D];
        for(int i=0;i<D;i++) fin>>P[i];
        int min=1001;
        for(int i=1;i<=1000;i++){
            int cuts=0;
            for(int j=0;j<D;j++) cuts+=(P[j]-1)/i;
            if(i+cuts<min) min=i+cuts;
        }
        fout<<"Case #"<<iT<<": "<<min<<endl;
    }
	return 0;
}
