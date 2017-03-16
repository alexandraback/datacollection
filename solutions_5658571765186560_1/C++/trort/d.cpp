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

bool _main(){
    int X,R,C;
    fin>>X>>R>>C;
    if(X==1) return 1;
    else if(X>=7) return 0;
    else if((R*C)%X != 0) return 0;
    // multiple of X only
    if(R>C){
        int temp = R;
        R = C;
        C = temp;
    }
    if(X == 2) return 1;
    else if(X == 3){
        if(R<=1) return 0;
        else return 1;
    }
    else if(X == 4){
        if(R<=2) return 0;
        else return 1;
    }
    else if(X == 5){
        if(R<=2) return 0;
        else if(R==3 && C>=10) return 1;
        else if(R>=4 && C>=5) return 1;
        else return 0;
    }
    else if(X == 6){
        if(R<=3) return 0;
        else if(R>=4 && C>=6) return 1;
        else return 0;
    }
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            fout<<(_main()?"GABRIEL":"RICHARD");
            fout<<endl;
    }
}
