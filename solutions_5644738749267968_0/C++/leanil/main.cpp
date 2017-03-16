#include <cstdio>
#include <algorithm>

using namespace std;

double naomi[1000], ken[1000];

int main()
{
    FILE* in = fopen("input.txt","r");
    FILE* out = fopen("output.txt","w");
    int t;
    fscanf(in,"%d",&t);
    for(int i=1;i<=t;i++) {
        int n;
        fscanf(in,"%d",&n);
        for(int j=0;j<n;j++) {
            fscanf(in,"%lf",&naomi[j]);
        }
        for(int j=0;j<n;j++) {
            fscanf(in,"%lf",&ken[j]);
        }
        sort(naomi,naomi+n);
        sort(ken,ken+n);
        int ni = 0, ki = 0, out1 = 0;
        while(ni < n) {
            if(naomi[ni] > ken[ki]) {
                out1++;
                ki++;
            }
            ni++;
        }
        int out2 = 0;
        ni = 0;
        ki = 0;
        while(ki < n) {
            if(naomi[ni] > ken[ki]) {
                out2++;
            }
            else {
                ni++;
            }
            ki++;
        }
        fprintf(out,"Case #%d: %d %d\n",i,out1,out2);
    }
    fclose(in);
    fclose(out);
    return 0;
}
