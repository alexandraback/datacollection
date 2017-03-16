#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int stones,N,M,K;
int unf[20];

int root(int x){
    if(x==-1) return -1;
    if(unf[x]==x) return x;
    unf[x] = root(unf[x]);
    return unf[x];
}

void add(int x,int y){
    if( (stones>>x)&1 || (stones>>y)&1 ) return;
    int p = root(x);
    int q = root(y);
    unf[p] = min(p,q);
    unf[q] = min(p,q);
    return;
}
    
bool poss(){

    for (int ind = 0; ind < N*M; ++ind)
    {
        unf[ind] = ind;
        if( ind/M==0 || ind/M==(N-1) || ind%M==0 || ind%M==(M-1) ) unf[ind] = -1;
        if( (stones >> ind) & 1) unf[ind] = ind;
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
           if(i<(N-1))add(i*M+j,i*M+j+N);
           if(j<(M-1))add(i*M+j,i*M+j+1); 
        }
    }
    int count = 0;
    for (int ind = 0; ind < N*M; ++ind)
    {
        if(root(ind)==-1) count++;
    }
    return (K<= (N*M-count));
}


int fun(int x){
    int ans = 0;
    while(x!=0){
        ans += x&1;
        x /= 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    for (int t = 0; t < T; ++t)
    {
        cin>>N>>M>>K;
        int ans = N*M;

        for (int i = 0; i < (1<<N*M); ++i)
        {
            stones = i;
            if(poss()) ans = min(ans , fun(stones));
        }
        printf("Case #%d: %d\n", t+1 , ans);
    }
    return 0;
}