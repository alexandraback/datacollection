#include <bits/stdc++.h>
#define fr(i,a,b) for(int i =(a); i < (b); ++i)
#define frr(i,a,b) for(int i =(a); i >= (b); --i)
#define cl(a,b) memset(a, b, sizeof a)
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;

iii in[1010];
ii hiks[101000];

int main() {
    int T; scanf("%d", &T);
    for(int cases = 1; cases <= T; ++cases) {
        int n; scanf("%d", &n);
        int k = 0;
        fr(i,0,n) {
            scanf("%d %d %d", &in[i].st, &in[i].nd.st, &in[i].nd.nd);
            fr(ct,0,in[i].nd.st) hiks[k++] = ii(in[i].st,in[i].nd.nd+ct);
        }
        if(k==1) printf("Case #%d: 0\n", cases);
        else {
            double ini1 = hiks[0].st;
            double ini2 = hiks[1].st;
            double v1 = 360.0/hiks[0].nd;
            double v2 = 360.0/hiks[1].nd;
            double vRel;
            double distRel;
            if(ini1 > ini2) {
                if(v1 > v2) {
                    vRel = v1-v2;
                    distRel = 360.0-(ini1-ini2);
                } else {
                    vRel = v2-v1;
                    distRel = (ini1-ini2);
                }
            } else if(ini1 == ini2) {
                distRel = 360.0;
                vRel = abs(v1-v2);
            } else {
                if(v1 > v2) {
                    vRel = v1-v2;
                    distRel = (ini2-ini1);
                } else {
                    vRel = v2-v1;
                    distRel = 360.0-(ini2-ini1);
                }
            }
            double tEnc = distRel/vRel;
            double whereEnc;
            if(ini1 < ini2)
                whereEnc = ini1+tEnc*v1;
            else if(ini1 == ini2) {
                if(v1 < v2)
                    whereEnc = ini1+tEnc*v1;
                else
                    whereEnc = ini2+tEnc*v2;
            } else 
                whereEnc = ini2+tEnc*v2;
            if(whereEnc > 360.0)
                printf("Case #%d: 0\n", cases);
            else
                printf("Case #%d: 1\n", cases);
        }
    }
    return 0;
}