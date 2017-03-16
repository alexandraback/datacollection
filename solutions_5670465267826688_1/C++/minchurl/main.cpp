#include<stdio.h>
char s[450005],b[450005];
int b1[4500005];
FILE *in,*out;
void f(char x,char y,char &z,int &k){//x*y를 z에 넣어라(기호는 k)
    if(x=='1' || y=='1'){
        z=y;
        return;
    }
    if(x==y){
        z='1';
        k=-k;
        return;
    }
    if(x=='i' && y=='j'){
        z='k';
        return;
    }
    if(x=='i' && y=='k'){
        z='j';
        k=-k;
        return;
    }
    if(x=='j' && y=='k'){
        z='i';
        return;
    }
    if(x=='j' && y=='i'){
        z='k';
        k=-k;
        return;
    }
    if(x=='k' && y=='i'){
        z='j';
        return;
    }
    if(x=='k' && y=='j'){
        z='i';
        k=-k;
        return;
    }
}
int main(){
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int y,i,j,test,n,l,t;
    long long x;
    fscanf(in,"%d",&test);
    for(t=0;t<test;t++){
        fscanf(in,"%d %lld",&l,&x);
        fscanf(in,"%s",s);
        if(x>=40)    x=x%4+16;
        y=-1;
        n=0;
        b[n]=s[0];
        b1[n++]=1;
        if(b[n-1]=='i')   y=0;
        for(i=0;i<x;i++){
            for(j=0;j<l;j++){
                if(i==j && i==0)    continue;
                b1[n]=b1[n-1];
                f(b[n-1],s[j],b[n],b1[n]);
                if(b[n]=='i' && y==-1)   y=n;
                n++;
            }
        }
        if(b[n-1]!='1' || b1[n-1]!=-1 || l==1 || y==-1){
            fprintf(out,"Case #%d: NO\n",t+1);
            continue;
        }
        j=0;
        for(i=y+1;i<n-1;i++){
            if(b[i]=='k'){
                j=1;
                break;
            }
        }
        if(j==0)    fprintf(out,"Case #%d: NO\n",t+1);
        else    fprintf(out,"Case #%d: YES\n",t+1);
    }
    return 0;
}
