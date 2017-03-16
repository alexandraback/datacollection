#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair

int A[105][105];
int k,l;
int r[105],c[105];

PII mini(){
    int res=1000;
    PII best = mp(0,0);
    FOR(i,0,k) FOR(j,0,l){
        if(A[i][j]<res){ res=A[i][j]; best = mp(i,j);}
    }
    return best;
}

bool constw(int n){
    FOR(i,1,l) if(A[n][i-1]!=A[n][i]) return false;
    return true;
}

bool constk(int n){
    FOR(i,1,k) if(A[i-1][n]!=A[i][n]) return false;
    return true;
}







int main(){
    int z; scanf("%d",&z);
    FOR(tn,1,z+1){
        scanf("%d%d",&k,&l);
        FOR(i,0,k) FOR(j,0,l) scanf("%d",&A[i][j]);
        string answer = "YES";
        while(k!=0 && l!=0){
            PII p = mini();
            if(constw(p.st)){
                FOR(i,0,l) swap(A[k-1][i],A[p.st][i]);
                k--;
            }
            else if(constk(p.nd)){
                FOR(i,0,k) swap(A[i][l-1],A[i][p.nd]);
                l--;
            } 
            else{
                answer = "NO";
                k = l = 0;
            }

            
        }
        cout<<"Case #"<<tn<<": "<<answer<<endl;

    }
}


