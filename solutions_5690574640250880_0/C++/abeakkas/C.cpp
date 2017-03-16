// Abdurrahman Akkas - abdurak
// Google CodeJam 2014
// Qualification Round
// Problem C
// Allah belasini vermesin boyle sorunun da
// Deneye deneye bi hal olduk arkadas
// Exceptions, exceptions, exceptions...
// Azimle seven, kayayi delermis...

#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("C.in");
    ofstream fout("C.out");
    int T,iT;
    char table[50][50];
    fin>>T;
    for(iT=1;iT<=T;iT++){
        int R,C,M,Bos;
        fin>>R>>C>>M;
        Bos=R*C-M;
        if(M==0){
            int i,j;
            fout<<"Case #"<<iT<<":"<<endl;
            for(i=0;i<R;i++){
                for(j=0;j<C;j++) if(i==0 && j==0) fout<<'c'; else fout<<'.';
                fout<<endl;
            }
            continue;
        }
        if(Bos==1){
            int i,j;
            for(i=0;i<R;i++) for(j=0;j<C;j++) table[i][j]='*';
            table[0][0]='c';
            fout<<"Case #"<<iT<<":"<<endl;
            for(i=0;i<R;i++){
                for(j=0;j<C;j++) fout<<table[i][j];
                fout<<endl;
            }
            continue;
        }
        if((R==1 || C==1) && Bos<2){ fout<<"Case #"<<iT<<":"<<endl<<"Impossible"<<endl; continue;}
        if((R>1 && C>1) && Bos<4){ fout<<"Case #"<<iT<<":"<<endl<<"Impossible"<<endl; continue;}
        if(R==2 || C==2)
            if(Bos%2==1){
                fout<<"Case #"<<iT<<":"<<endl<<"Impossible"<<endl; continue;
            }
        if(R==1){
        fout<<"Case #"<<iT<<":"<<endl;
            for(int i=0;i<C;i++){
                if(i==0) fout<<'c';
                else if(i<Bos) fout<<'.';
                else fout<<'*';
            }
            fout<<endl;
            continue;
        }
        if(C==1){
        fout<<"Case #"<<iT<<":"<<endl;
            for(int i=0;i<R;i++){
                if(i==0) fout<<'c';
                else if(i<Bos) fout<<'.';
                else fout<<'*';
                fout<<endl;
            }
            continue;
        }
        /*
        if(R==2){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++) {
                    if(i==0 && j==0) fout<<'c';
                    else if(j*2<Bos) fout<<'.';
                    else cout<<'*';
                }
                fout<<endl;
            }
            continue;
        }
        if(C==2){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++) {
                    if(i==0 && j==0) fout<<'c';
                    else if(i*2<Bos) fout<<'.';
                    else cout<<'*';
                }
                fout<<endl;
            }
            continue;
        }*/
        if(Bos==5 || Bos==7){
            fout<<"Case #"<<iT<<":"<<endl<<"Impossible"<<endl; continue;
        }
        int i,j;
        for(i=0;i<R;i++)for(j=0;j<C;j++) table[i][j]='*';
        i=0;j=0;
        while(Bos!=0){
            table[i][j]='.';
            if(i<R && j<C) Bos--;
            if(i==j){i=0;j++;continue;}
            if(i+1==j){i++;j=0;continue;}
            if(i<j){i++;continue;}
            if(i>j){j++;continue;}
        }
        if(i==1){
            if(j>=R){
                table[R-1][j-1]='*';
                table[i][j]='.';
            }else{
                table[j-1][j-1]='*';
                table[i][j]='.';
            }
        }
        if(j==1){
            if(i>=C){
                table[i-1][C-1]='*';
                table[i][j]='.';
            }else{
                table[i-1][i]='*';
                table[i][j]='.';
            }
        }
        table[0][0]='c';
        fout<<"Case #"<<iT<<":"<<endl;
        for(i=0;i<R;i++){
            for(j=0;j<C;j++) fout<<table[i][j];
            fout<<endl;
        }
    }
    return 0;
}
