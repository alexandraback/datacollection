#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

#define LIM 1000+5
#define INF 1000000000

int N;
int A[LIM],B[LIM];
int best;
int curr;
bool valid;
int rating[LIM];
int r,g;

void do_it()
{
    valid=false;
    for(int i=1;i<=N;i++){
        if(rating[i]==0 && r>=B[i]){
            r+=2;
            g++;
            rating[i]=2;
            valid=true;
            return ;
        }
    }
    for(int i=1;i<=N;i++){
        if(rating[i]==1 && r>=B[i]){
            r++;
            g++;
            rating[i]=2;
            valid=true;
            return ;
        }
    }
    int mx=0,key=-1;
    for(int i=1;i<=N;i++){
        if(rating[i]==0 && r>=A[i]){
            if(B[i]>mx){
                key=i;
                mx=B[i];
            }
        }
    }
    if(key!=-1){
        r++;
        rating[key]=1;
        g++;
        valid=true;
        return ;
    }
    for(int i=1;i<=N;i++){
        if(rating[i]==0 && A[i]+1==B[i] && r>=A[i]){
            r+=2;
            rating[i]=2;
            g+=2;
            valid=true;
            return ;
        }
    }
    return ;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int tt=1;tt<=cases;tt++){
        //printf("%d\n",tt);
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d%d",&A[i],&B[i]);
            rating[i]=0;
        }
        r=g=0;
        valid=true;
        do{
            do_it();
        }while(valid);
        if(r<2*N) printf("Case #%d: Too Bad\n",tt);
        else printf("Case #%d: %d\n",tt,g);
    }
}
