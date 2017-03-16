#include <cstdio>

using namespace std;

int T;
int n;
char s[101];

FILE *in, *out;

int main()
{
    in = fopen("B-small-attempt0.in","r");
    out = fopen("B-small-attempt0.out","w");

    fscanf(in,"%d",&T);
    for(int t=1; t<=T; t++) {
        fscanf(in,"%s",s);
        int sol(0);
        char prev(s[0]);
        for(n=0; s[n]!='\0'; n++) {
            sol += (s[n]!=prev);
            prev = s[n];
        }
        sol += (s[n-1]=='-');
        fprintf(out,"Case #%d: %d\n",t,sol);
    }

    fclose(in);
    fclose(out);

    return 0;
}
