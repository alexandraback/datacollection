#include<stdio.h>
int t,n;
char s[1005];
FILE *in,*out;
int main(){
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int x,y,i,j;
    fscanf(in,"%d",&t);
    for(i=0;i<t;i++){
        fscanf(in,"%d",&n);
        fscanf(in,"%s",s);
        x=y=0;
        for(j=0;j<=n;j++){
            y+=s[j]-'0';
            if(s[j]=='0')   continue;
            if(x<j) x=j;
            x+=s[j]-'0';
        }
        fprintf(out,"Case #%d: %d\n",i+1,x-y);
    }
    return 0;
}
