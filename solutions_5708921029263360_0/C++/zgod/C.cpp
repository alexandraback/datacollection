#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    FILE *fin = freopen("C-small-attempt2.in", "r", stdin);
    FILE *fout = freopen("C-small-attempt2.out", "w", stdout);
    long T,cas=0,J,P,S,K,JP,PS,SJ;
   
    cin>>T;
    while(T--){
        cas++;
        cin>>J>>P>>S>>K;
        int combinations[J*P*S][3];
        int temp[3];
        int counter=0;
        for(int j=1;j<=J;j++){
            for(int p=1;p<=P;p++){
                for(int s=1;s<=S;s++){
                    temp[0]=j;
                    temp[1]=p;
                    temp[2]=s;
                    JP=0;
                    PS=0;
                    SJ=0;
                    for(int i=0;i<counter;i++){
                        if(temp[0]==combinations[i][0] && temp[1] ==combinations[i][1])
                            JP++;
                        if(temp[1]==combinations[i][1] && temp[2] ==combinations[i][2])
                            PS++;
                        if(temp[2]==combinations[i][2] && temp[0] ==combinations[i][0])
                            SJ++;
                    }
                    if(JP<K && PS<K && SJ<K){
                        combinations[counter][0] = temp[0];
                        combinations[counter][1] = temp[1];
                        combinations[counter][2] = temp[2];
                        counter++;
                    }
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<(counter)<<endl;
        for(int i=0;i<counter;i++){
            cout<<combinations[i][0]<<" "<<combinations[i][1]<<" "<<combinations[i][2]<<endl;
        }
    }
    
    return 0;
}