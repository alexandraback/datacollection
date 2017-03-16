#include<stdio.h>
#include<algorithm>
#define oo 0x7fffffff
using namespace std;
int b[1005],n,test;
FILE *in,*out;
bool sort_cmp(int x,int y){return x>y;}
int main(){
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int t,i,j,x,y;
    fscanf(in,"%d",&test);
    for(t=1;t<=test;t++){
        fscanf(in,"%d",&n);
        for(i=0;i<n;i++)    fscanf(in,"%d",&b[i]);
        sort(b,b+n,sort_cmp);
        y=oo;
        for(i=b[0];i>=1;i--){
            x=i;
            for(j=0;j<n;j++){
                if(i>=b[j]) continue;
                x+=(b[j]-1)/i;
            }
            y=x<y?x:y;
        }
        fprintf(out,"Case #%d: %d\n",t,y);
    }
    return 0;
}
