#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#define DEBUG 0
using namespace std;
int main() {
    int tc,tci,i,j,N,A,S[101],flag[101],possible,eaten,ans,new1,lasteat;
    long long int amin;
    FILE *fp = fopen("C:/ikj/input.txt","r");
    FILE *fp2 = fopen("C:/ikj/output.txt","w");
    fscanf(fp,"%d",&tc);
    for(tci=0;tci<tc;tci++) {
        fscanf(fp,"%d %d",&A,&N);
        amin=A;
        for(i=0;i<N;i++) {
            fscanf(fp,"%d",&S[i]);
            flag[i]=0;
        }
        eaten=0;
        ans=0;
        lasteat=0;
        new1=0;
retry:
        possible=1;
        while(possible) {
            possible=0;
            for(i=0;i<N;i++) {
                if((flag[i]==0)&&(S[i] < amin)) {
                    amin+=S[i];
                    flag[i]=1;
                    eaten++;
                    new1++;
                    possible=1;
                    if(DEBUG) fprintf(fp2,"%d %d %d %d\n",int(amin),eaten,new1,ans);
                }
            }
        }
        if((amin!=1)&&(eaten<N)) {
            amin=2*amin-1;
            ans++;
            if(new1>=lasteat) {
                new1=0;
                lasteat=0;
            }
            lasteat++;
            goto retry;
        }
        if(eaten < N) ans=N-eaten;
        else {
            if(new1<lasteat) {
                ans-=lasteat;
                ans+=new1;
            }
        }
        fprintf(fp2,"Case #%d: %d\n",tci+1,ans);
    }
}
