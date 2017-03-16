#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

long long G(long long a,long long b){
    long long c=a%b;
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.out");
    int n;
    fin>>n;
    for(int t=1;t<=n;t++){
        int ans=0;
        long long P,Q;
        string ss;
        fin>>ss;
        sscanf(ss.c_str(),"%lld/%lld",&P,&Q);
        long long g=G(P,Q);
        P=P/g;
        Q=Q/g;
        long long QQ=Q;
        while(QQ%2==0){
            QQ=QQ/2;
            ans++;
        }
        char ansstr[500];
        if(QQ!=1)
            sprintf(ansstr,"Case #%d: impossible\n",t);
        else{
            for(int i=ans-1;i>=0;i--){
                if(P>=(1<<i)){
                    ans-=i;
                    break;
                }
            }
            sprintf(ansstr,"Case #%d: %d\n",t,ans);
        }
        fout<<ansstr;
    }
    return 0;
}
