#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
int main(){
    ifstream fcin;
    ofstream fout;
    fcin.open("input.in");
    fout.open("output.out");
    int T;
    int arr[51][51]={0,};
    int n,m,temp;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m;
        fout<<"Case #"<<i<<": ";
        if(pow(2,n-2)<m){
            fout<<"IMPOSSIBLE\n";
            continue;
        }
        else{
            fout<<"POSSIBLE\n";
        }
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                arr[j][k]=1;
            }
        }
        temp=n-2;
        for(int j=0;j<n;j++){
            arr[0][j]=0;
        }
        arr[0][0]=0;
        arr[0][n-1]=1;
        m--;
        while (m) {
            if(m%2){
                arr[0][temp]=1;
            }
            m/=2;
            temp--;
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                fout<<arr[j][k];
            }
            fout<<"\n";
        }
    }
}