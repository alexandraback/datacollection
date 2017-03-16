#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int smax;
char s[1013];

int main() {
    FILE* fin = fopen("A-small-attempt0.in","r");
    FILE* fout = fopen("A-small-attempt0.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for (int t=1;t<=T;t++) {
        fscanf(fin,"%d %s",&smax,&s);
        int ans = 0;
        int prev = 0;
        for (int i=0;i<=smax;i++) {
            if (prev<i) ans+=i-prev, prev = i;
            prev+=s[i]-'0';
        }
        fprintf(fout,"Case #%d: %d\n",t,ans);
    }

    return 0;
}
