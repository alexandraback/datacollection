#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

int G(int a,int b){
    int c=a%b;
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
        int P,Q;
        string ss;
        fin>>ss;
        sscanf(ss.c_str(),"%d/%d",&P,&Q);
        int g=G(P,Q);
        P=P/g;
        Q=Q/g;
        int QQ=Q;
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
