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
    int R,C,M;
    fin>>R>>C>>M;
    int M_orig=M;
    bool mine[55][55];
    int RR,CC;
    int i,j,k;

    for(i=0;i<=R;i++) for(j=0;j<=C;j++) mine[i][j]=0;
    RR=R,CC=C;
    while(M>RR || M>CC){
        if(RR<=CC){
            for(i=0;i<RR;i++) mine[i][CC-1]=1;
            M -= RR;
            CC--;
        }
        else{
            for(i=0;i<CC;i++) mine[RR-1][i]=1;
            M -= CC;
            RR--;
        }
    }

    if((RR==3 && CC==3 && M==2) || (RR==2 && CC>=2 && M==1) || (RR>=2 && CC==2 && M==1)){
        //fout<<RR<<" "<<CC<<" "<<M<<endl;
        fout<<"Impossible"<<endl;
        return;
    }

    if(RR<=CC){
        if(M!=(RR-1)) for(i=0;i<M;i++) mine[RR-1-i][CC-1]=1;
        else{
            for(i=0;i<M-1;i++) mine[RR-1-i][CC-1]=1;
            if(M>0) mine[RR-1][CC-2]=1;
        }
    }
    else{
        if(M!=(CC-1)) for(i=0;i<M;i++) mine[RR-1][CC-1-i]=1;
        else{
            for(i=0;i<M-1;i++) mine[RR-1][CC-1-i]=1;
            if(M>0) mine[RR-2][CC-1]=1;
        }
    }

    int count=0;
    if(R*C-M_orig>1 && (mine[0][0] || mine[0][1] || mine[1][0] || mine[1][1])) fout<<"Impossible"<<endl;
    else{
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                if(i==0 && j==0){
                    fout<<"c";
                    if(mine[i][j]) fout<<"ERROR!!!!!!"<<endl;
                }
                else if(mine[i][j]){
                    fout<<"*";
                    count++;
                }
                else fout<<".";
            }
            fout<<endl;
        }
        if(count != M_orig) fout<<"ERROR!!!!!!"<<endl;
    }
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<":"<<endl;
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            //fout<<endl;
    }
}
