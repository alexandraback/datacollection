#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define MAXN 100010

int N, M, A;
double p[ MAXN ];
double ans;

int main() {
	int cases;		// number of cases
	int caseID = 1;	// case ID, start from 1

    freopen("input","r",stdin);
    freopen("output","w",stdout);

	scanf("%d", &cases);
	while (cases--) {

		//IO
		scanf("%d%d", &N, &M);
		p[0] = 1;
        for(int i = 1; i <= N;i++){
        	scanf("%lf", &p[i]);
            if(i){
            	p[i] *= p[i-1];
            }
        }

        ans = 1e16;
        int ok = M - N + 1;
        int no;
        double current_p;
        for(int i = 0; i <= N; i++){
            no = ok + M + 1;

            current_p = ( p[ N - i ] ) * ok  +
            			( 1 - p[ N - i ] ) * no;

            ans = min( ans, current_p );
            ok +=2;
        }

        //enter
        ans = min( ans, (double)(M+2) );

        printf("Case #%d: %.6f\n", caseID++ ,ans);
    }

    return 0;
}
