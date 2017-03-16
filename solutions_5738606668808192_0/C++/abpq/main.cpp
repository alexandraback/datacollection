#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int T,N,J,temp;
int main(){
    ofstream output;
    output.open("output.out");
    scanf("%d",&T);
    string copys;
    string s16="1111111111111111";
    string sarr[101];
    sarr[0]=s16;
    copys=s16;
    int temp=1;
    for(int i=0;i<14;i++){
        copys=s16;
        copys[14-i]='0';
        for(int j=13-i;j>0;j-=2){
            sarr[temp]=copys;
            sarr[temp][j]='0';
            temp++;
        }
    }
    sarr[50]="1000011111111111";
    for(int i=1;i<=T;i++){
        temp=0;
        scanf("%d %d",&N,&J);
        output<<"Case #"<<i<<":\n";
        while(J--){
            output<<sarr[temp++];
            output<<" 3 4 5 6 7 8 9 10 11\n";
        }
    }
}