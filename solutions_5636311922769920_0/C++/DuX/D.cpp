#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

int main() {

    FILE *ff=fopen("D-small-attempt0.in", "r"), *gg=fopen("D-small-attempt0.out", "w");

    int tt,ttt;
    long long k,c,s,p,i,t;
    vector<long long> res;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        res.clear();

        fscanf(ff,"%lld%lld%lld", &k, &c, &s);

        p=0;
        while(p<k) {
            t = 0;
            for(i=0; i<c; i++) {
                t = t*k + min(k-1,p);
                p++;
            }
            res.pb(t+1);
        }

        if (res.size() > s) {
            fprintf(gg, "IMPOSSIBLE\n");
        } else {
            for(i=0; i<res.size(); i++) fprintf(gg, "%lld ", res[i]);
            fprintf(gg, "\n");
        }
    }

    fclose(ff); fclose(gg);

    return 0;
}
