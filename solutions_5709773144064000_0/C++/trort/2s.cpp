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

void _main(){
    double C,F,X;
    fin>>C>>F>>X;
    double sum,time,next,speed;
    sum = 0.0;
    speed = 2.0;
    time = X/speed;
    next = C/speed + X/(speed+F);
    while(next < time){
        sum += C/speed;
        speed += F;
        time = X/speed;
        next = C/speed + X/(speed+F);
    }
    fout.precision(9);
    fout<<fixed;
    fout<<sum+time;
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
