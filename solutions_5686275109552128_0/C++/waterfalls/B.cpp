#include <cstdio>
#include <algorithm>

using namespace std;

int D;
int P[1013];

int main() {
    FILE* fin = fopen("B-small-attempt3.in","r");
    FILE* fout = fopen("B-small-attempt3.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for (int t=1;t<=T;t++) {
        fscanf(fin,"%d",&D);
        for (int i=0;i<D;i++) fscanf(fin,"%d",&P[i]);
        int ans = 1000;
        for (int lim=1;lim<=1000;lim++) {
            int cur = 0;
            int big = 0;
            for (int i=0;i<D;i++) {
                int num = (P[i]+lim-1)/lim;
                cur+=num-1;
                int j = lim;
                for (;j>0;j--) if (j*num<P[i]) break;
                big = max(big,j+1);
            }
            cur+=big;
            ans = min(ans,cur);
        }
        fprintf(fout,"Case #%d: %d\n",t,ans);
    }

    return 0;
}
