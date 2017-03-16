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

#define SIZE 100

#define IN freopen("A-small-attempt0.in","r",stdin);
#define OUT freopen("A-small-attempt0.out","w",stdout);

int T,N,_N,X;

double _2S;

int J[SIZE];
bool vis[SIZE];

int main()
{
	IN
	OUT
	int i,t;

	scanf("%d",&T);
	for(t=1;t<=T;t++){

	    scanf("%d",&N);
	    X = 0;
	    for(i=0;i<N;i++){
            scanf("%d",&J[i]);
            X += J[i];
	    }

        _2S = X * 2;
        double safe = _2S / N;

        memset(vis, true, sizeof(vis));

        _N = N;
        while(_N > 2){
            int nn = _N;
            for(i=0;i<N;i++){
                if(vis[i] && J[i] > safe){
                    vis[i] = false;
                    _N--;
                    _2S -= J[i];
                }
            }

            if(nn == _N){
                break;
            }

            safe = _2S / _N;
        }

        if(N == 2){
            safe = _2S / 2;
        }

		printf("Case #%d: ",t);

		for(i=0;i<N;i++){
		    if(i)   printf(" ");
            if(J[i] > safe){
                printf("0.000000");
            }else {
                printf("%.6lf", 100 * (safe - J[i]) / X);
            }
		}

        printf("\n");

	}
	return 0;
}
