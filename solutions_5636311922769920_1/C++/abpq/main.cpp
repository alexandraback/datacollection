#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int T,K,C,S,tt=0;
long long int search(long long int left,long long int right,int temp){
    tt=temp;
    if(right-left<=1){
        if(tt==0)
            tt=1;
        return right;
    }
    if(tt>=K)
        return right;
    return search((((K-temp)*(left/K))+temp*(right/K)),(((K-temp-1)*(left/K))+(temp+1)*(right/K)),temp+1);
}
int main(){
    ofstream output;
    output.open("output.out");
    long long int m;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d %d %d",&K,&C,&S);
        output<<"Case #"<<i<<": ";
        if((C*S)<K){
            output<<"IMPOSSIBLE\n";
            continue;
        }
        
        m=1;
        for(int i=0;i<C;i++){
            m*=K;
        }
        long long int leftstart=0;
        long long int rightstart=m;
        tt=0;
        while(1){
            output<<search(leftstart,rightstart,tt)<<" ";
            if(tt>=K)
                break;
        }
        output<<"\n";
    }
}