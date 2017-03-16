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
    int s_max;
    fin>>s_max;
    string stand;
    fin>>stand;
    int ct = 0;
    int shy = 0;
    for(int i=0; i <= s_max; i++){
        if(ct < i){
            shy += i-ct;
            ct = i;
        }
        ct += (stand[i]-'0');
    }
    fout<<shy;
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
