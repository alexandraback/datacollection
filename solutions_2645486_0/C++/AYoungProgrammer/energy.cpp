#include <iostream>
#include <fstream>
using namespace std;

int arr[11];

int maxN;
int regain;
int maxC;

int maxVal = 0;

int bt(int n,int cur,int val){
    if(n>=maxN){
        maxVal = max(maxVal,val);
        return 0;
    }

    if(cur>maxC){
        cur = maxC;
    }

    for(int i=min(maxC-regain,cur);i>=0;i--){
        bt(n+1,i+regain,val+arr[n]*(cur-i));
    }

}

int main(void){

    ifstream fin("energy.in");
    ofstream fout("energy.out");

    int T;
    fin>>T;
    for(int t=1;t<=T;t++){
        fin>>maxC;
        fin>>regain;

        if(regain>maxC)regain=maxC;

        fin>>maxN;
        maxVal = 0;

        for(int i=0;i<maxN;i++){
            fin>>arr[i];
        }

        bt(0,maxC,0);
        fout<<"Case #"<<t<<": "<<maxVal<<endl;
    }




}
