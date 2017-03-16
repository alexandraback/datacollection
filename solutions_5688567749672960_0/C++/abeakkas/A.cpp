/*
* abeakkas
* Google CodeJam 2015 - Round 1B
* Problem A
* Bu da mi gol degil
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>

typedef long long int ll;

#define pr pair<ll,ll>
#define vpr vector<pair<ll,ll> >

//DEBUGGING
#define _s cout<<
#define _d <<" "<<
#define _e <<endl;

//(int *)calloc(1000000,sizeof(int));
//(int *)malloc(1000000*sizeof(int));

using namespace std; 
ifstream fin ("A.in");
ofstream fout ("A.out");

int reverse(int x){
    int c=0;
    while(x!=0){
        c*=10;
        c+=(x%10);
        x/=10;
    }
    return c;
}

// Brute force rulez
int arr[1000001];
int main(){
    int T;
    fin>>T;
    arr[1]=1;
    for(int i=2;i<=1000000;i++){
        arr[i]=10000000;
    }
    for(int i=2;i<=1000000;i++){
        if(arr[i]>arr[i-1]+1) arr[i]=arr[i-1]+1;
        if(arr[reverse(i)]>arr[i]+1) arr[reverse(i)]=arr[i]+1;
    }
    for(int iT=1;iT<=T;iT++){
        int x;
        fin>>x;
        fout<<"Case #"<<iT<<": "<<arr[x]<<endl;
    }
	return 0;
}
