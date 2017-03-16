#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

typedef long long lld;

#define SIZE 100+10

#define IN freopen("C-small-attempt1.in","r",stdin);
#define OUT freopen("C-small-attempt1.out","w",stdout);

int T,N,M;

lld Bx[SIZE],Ty[SIZE];
lld bx[SIZE],ty[SIZE];

lld ans;

void bktk(int b, int t, lld sum){
    if(b == N || t == M){
        if(sum > ans){
            ans = sum;
        }
        return;
    }

    if(Bx[b] == Ty[t]){
        lld b1 = bx[b];
        lld t1 = ty[t];

        if(bx[b] > ty[t]){
            bx[b] -= ty[t];
            bktk(b,t+1,sum+ty[t]);
        }else if(ty[t] == bx[b]){
            bktk(b+1,t+1,sum+bx[b]);
        }else{
            ty[t] -= bx[b];
            bktk(b+1,t,sum+bx[b]);
        }

        bx[b] = b1;
        ty[t] = t1;
        return;
    }

    bktk(b+1,t,sum);
    bktk(b,t+1,sum);
}

int main()
{
	IN
	OUT
	int i,j,t;

	scanf("%d",&T);
	for(t=1;t<=T;t++){

	    scanf("%d %d",&N,&M);

	    for(i=0;i<N;i++)    scanf("%lld %lld",&bx[i],&Bx[i]);
	    for(i=0;i<M;i++)    scanf("%lld %lld",&ty[i],&Ty[i]);

        ans = 0;
        bktk(0,0,0);

		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}
