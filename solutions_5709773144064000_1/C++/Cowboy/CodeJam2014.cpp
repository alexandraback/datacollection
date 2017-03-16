/*
 *ID:   Cowboy
 *TASK:
 *Judge:
 */
#include <bits/stdc++.h>
#define INF 0x7fffffff
#define PI 2*acos(0.0)
#define EPS 10E-9
using namespace std;

#define PB(t) push_back(t)
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))

int main( ){
    freopen("B-large.in","r",stdin);
    freopen("solution.out","w",stdout);
    int T, k = 0;
    for( cin>>T; k<T; k++){
        double C, F, X, res, time, cookies;

        cin>>C>>F>>X;
        time = 0.0;
        cookies = 2.0;
        res = X/cookies;

        //cout<<C<<" "<<F<<" "<<X<<endl;
        while( time+EPS < res ){
            time += C/cookies;
            cookies+=F;
            res = min( res, time+X/cookies);
        }
        //cout<<X<<" "<<cookies<<" "<<time<<" "<<C<<" "<<F<<endl;
        time += X/cookies;
        res = min( res, time);

        printf("Case #%d: %.8lf\n", k+1, res);

    }

return 0;
}
