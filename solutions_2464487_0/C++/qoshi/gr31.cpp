#include <stdio.h>
#include <memory.h>

using namespace std;

long long r,t;

int T;

const double pi = 3.1415926535;

long long  solve(){
    long long count;
    count = 0;
    double s;
    //printf("s %.4lf\n",s);
    while ( 1 ){
        s = (r+1)*(r+1)-(r)*(r);
        if ( t < s ) break;
        t -= s;
        r += 2;
        count++;

        //printf("%.4lf t  %.4lf\n",t,s);
    }
    return count;
    }


int main(){
    int cas,i;
    long long ans;
    FILE* fin = fopen ("d:\\g1.in","r");
    FILE* fout = fopen ("d:\\out.txt","w");
    if ( fin == NULL ) printf("fk\n");
    fscanf(fin,"%d",&T);
    printf("%d\n",T);

    for ( cas = 1; cas <= T; cas++ ){
        fscanf(fin,"%lld%lld",&r,&t);
        printf("%lld %lld\n",r,t);
    //solve();
    ans = solve();
    printf("ans %lld\n",ans);
    fprintf(fout,"Case #%d: %.lld\n",cas,ans);

    }
    fclose(fin);
    fclose(fout);
}
