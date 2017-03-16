#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
double prob[8], probCom, probRes;
int com;
string kb,tgt;
int K,L,S;
int cnt[256];
int findProb(){
    int i,j;
    for(i=0;i<256;i++)
        cnt[i]=-1;
    for(i=0; i<L; i++){
        if(cnt[tgt[i]] >0)
            continue;
        cnt[tgt[i]] = 0;
        for(j=0; j<K; j++){
            if(tgt[i] == kb[j])
                cnt[tgt[i]]++;
        }
        if(cnt[tgt[i]] == 0)
            return -1;
        prob[i] = 1.0 * cnt[tgt[i]]/K;
        if(prob[i] == 1.0)
            return -1;
        //printf("Prob of %c = %f\n", tgt[i], prob[i]);
    }
    return 0;
}

void findCom(){
    int ret = -1, i, j;
    for(i=1; i<L; i++){
        if(tgt[i] == tgt[0]){
            ret = i;
            for(j=1; j<L-i; j++){
                if(tgt[i+j] != tgt[j])
                    ret = -1;
            }
        }
        if(ret>0)
            break;
    }
    com = ret;
    //printf("Common = %d\n", com);

    probRes= 1.0;
    probCom = 1.0;
    for(i=0;i<L;i++){
        probRes *= prob[i];
    }
    if(com>0){
        for(i=0;i<com;i++){
            probCom *= prob[i];
        }
    }
    else{
        probCom = probRes;
        com = L;
    }
    //printf("probCom = %f probRes = %f\n", probCom, probRes);
}

double exp(int n){
    double ret=1.0;
    int l = ((n-1)*com) + L;
    if(l > S)
        return 0;
    n--;
    while(n--){
        ret*=probCom;
    }
    ret*=probRes;
    return ret;
}

int main(){
    double ex,ret;
    int i,j, runs;
    cin>>runs;
    for(j=1; j<=runs; j++){
        cin>>K>>L>>S>>kb>>tgt;
        //cout<<kb<<endl<<tgt<<endl;
        if(findProb() == -1){
            printf("Case #%d: %f\n", j, 0.0);
            continue;
        }
        findCom();
        i = 1;
        ex=0.0;
        while((ret=exp(i))!=0){
            ex += i*ret;
            i++;
        }
        i--;
        //printf("%d %f\n", i, ex);
        ex = i-ex;
        printf("Case #%d: %f\n", j, ex);
    }
    return 0;
}
