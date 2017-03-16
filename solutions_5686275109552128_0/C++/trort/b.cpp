#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<ctime>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

bool re_cmp(int i, int j) { return (i>j);}

void _main(){
    int D;
    fin>>D;
    int P[1005];
    int P_max=0;
    for(int i=0; i<D; i++){
        fin>>P[i];
        if(P[i]>P_max) P_max = P[i];
    }
    int mmin = P_max;
    int wait;
    for(int j = P_max; j>0; j--){
        wait = 0;
        for(int i = 0; i<D; i++){
            if(P[i]>j) wait += int(ceil(double(P[i])/j))-1;
        }
        if(wait + j < mmin) mmin = wait + j;
    }
    fout<<mmin;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
