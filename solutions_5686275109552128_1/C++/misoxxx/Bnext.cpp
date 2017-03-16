#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define FOR(a,b) for(int a=0;a<b;a++)
int turns(vector<int> V);
int main(){
    int T;
    scanf("%d",&T);
    FOR(tt,T){
        int n;
        scanf("%d",&n);
        vector<int> pancakes(n);
        FOR(i,n){
            scanf("%d",&pancakes[i]);
        }
        printf("Case #%d: %d\n",tt+1,turns(pancakes));
    }
    return 0;
}

int turns(vector<int> V){
    int maximum=0,minc=99999999;
    FOR(i,V.size()){
        if(V[i]>maximum)maximum=V[i];
    }
    for(int minL=1;minL<=maximum;minL++){
        priority_queue<int> Q;
        FOR(i,V.size()){
            Q.push(V[i]);
        }
        int divs=0;
        while(Q.top()>minL){
            divs++;
            int t=Q.top();
            Q.pop();
            Q.push(t-minL);
        }
        if(divs+minL<minc)minc=divs+minL;
   }
   return minc;
}
