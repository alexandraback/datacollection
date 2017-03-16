#include <stdio.h>
#include <memory.h>

using namespace std;

int E,R,n;
int v[100];

int T;

int  solve(int x, int e){
    int i;
    int max,sum,temp,en;
   // printf("now %d %d\n",x,e);
    if ( x == n ) {
        //printf("return %d\n",e*v[n]);
        return e*v[x];
    }
    //if ( e <= R ) {
    //    sum = 0;
    //    for ( i = x; i<=n; i++ )
    //        sum+=v[i];
    //    //printf("sum %d\n",sum);
    //    return sum*e;
   // }
    max = 0;
    for ( i = 0; i <= e; i++ ){
        en = (e-i+R) < E ? (e-i+R):E ;
        //printf("next %d %d %d\n",i,x+1,en);
        temp = i*v[x] + solve(x+1,en);
        max = max > temp ? max : temp;
        }

    return max;
    }


int main(){
    int cas,i;
    int ans;
    FILE* fin = fopen ("d:\\g1.in","r");
    FILE* fout = fopen ("d:\\out.txt","w");
    //if ( fin == NULL ) printf("fk\n");
    fscanf(fin,"%d",&T);

    for ( cas = 1; cas <= T; cas++ ){
        fscanf(fin,"%d%d%d",&E,&R,&n);
        printf("E %d R %d n %d\n",E,R,n);
        for ( i = 1; i <= n; i++ ){
            fscanf(fin,"%d",&v[i]);
            printf("%d ",v[i]);
        }
        printf("\n");
    ans = solve(1,E);
    printf("ans %d\n",ans);
    fprintf(fout,"Case #%d: %d\n",cas,ans);

    }
    fclose(fin);
    fclose(fout);
}
