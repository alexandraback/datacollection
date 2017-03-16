#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;


void q(){
    DRI(N);
    
    set<string> a, b;
    vector< pair<string, string> > ab;
    
    for(int i=0; i<N; i++){
        char A[30];
        char B[30];
        RS(A);
        RS(B);
        
        ab.push_back(make_pair(A, B));
    }
    
    for(auto v = ab.begin(); v != ab.end(); ){
        if(a.find(v->first) != a.end()){ v++; continue;}
        if(b.find(v->second) != b.end()){ v++; continue; }
        a.insert(v->first);
        b.insert(v->second);
        v = ab.erase(v);
    }
    
    for(auto v = ab.begin(); v != ab.end(); ){
        if(a.find(v->first) == a.end()){
            a.insert(v->first);
            v = ab.erase(v);
            continue;
        }
        if(b.find(v->second) == b.end()){
            b.insert(v->second);
            v = ab.erase(v);
            continue;
        }
        v++;
    }
    
    
    printf("%d\n", ab.size());
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

