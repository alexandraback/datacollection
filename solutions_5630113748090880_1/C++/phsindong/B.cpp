#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    FILE *inf, *outf;
    inf=fopen("B-large.in","r");
    outf=fopen("B-large-result.in","w");
    
    int T,N;
    int numCnt[2500];
    vector<int> ret;
    fscanf(inf,"%d",&T);
    for(int ii=0;ii<T;ii++){
        ret.clear();
        fscanf(inf,"%d",&N);
        memset(numCnt,0,sizeof(numCnt));
        for(int i=0;i<2*N-1;i++){
            for(int j=0;j<N;j++){
                int tmp;
                fscanf(inf,"%d",&tmp);
                numCnt[tmp-1]++;
            }
        }
        for(int i=0;i<2500;i++){
            if(numCnt[i]%2==1)ret.push_back(i+1);
        }
        fprintf(outf,"Case #%d:",ii+1);            
        for(int i=0;i<ret.size();i++){
            fprintf(outf," %d",ret[i]);
        }
        fprintf(outf,"\n");
    }
}