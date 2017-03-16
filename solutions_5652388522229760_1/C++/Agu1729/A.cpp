#include<iostream>
#include<fstream>
using namespace std;

int main(){
     ifstream inp("At.txt");
     ofstream outp("Ao.txt");
     int T, N, ts;
     int a[10];
     inp>>T;
     for(int i=1;i<=T;i++){
         outp<<"Case #"<<i<<": ";
         inp>>N;
         if(N==0){
             outp<<"INSOMNIA"<<endl;
         }
         else{
             for(int j=0;j<=9;j++){
                 a[j]=0;
             }
             for(int i=1;i<=90;i++){
                 ts=i*N;
                 while(ts!=0){
                     a[ts%10]=1;
                     ts/=10;
                 }
                 if(a[0]*a[1]*a[2]*a[3]*a[4]*a[5]*a[6]*a[7]*a[8]*a[9]==1){
                     outp<<i*N<<endl;
                     break;
                 }
             }
         }
     }
     return 0;
}
