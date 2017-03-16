#include<stdio.h>
int a[30],b[30],c[30];
int n;
bool flag;
FILE *inf, *outf;

int abs(int x){
    if (x>0) return x;
    return -x;
}
int search(int l,int r,int i){
    if(!flag)return 0;
    if (l>0 && l==r){
        int j;
        for(j=0;j<i;j++)
            if (c[j]==0)
                fprintf(outf,"%d ",a[j]);
        fprintf(outf,"\n");
        for(j=0;j<i;j++)
            if (c[j]==1)
                fprintf(outf,"%d ",a[j]);
        fprintf(outf,"\n");
        flag =false;
        return 0;
    }
    if(abs(l-r)>b[i]) return 0;
    c[i]=0;
    search(l+a[i],r,i+1);
    c[i]=1;
    search(l,r+a[i],i+1);
    c[i]=2;
    search(l,r,i+1);
    c[i]=0;
    return 0;
}

int main(){
    outf = fopen("c.out","w");
    inf = fopen("c.in","r");

    int ii,nn,i,j;
    fscanf(inf,"%d",&nn);
    for (ii=0;ii<nn;ii++){
        fscanf(inf,"%d",&n);
        for (i=0;i<n;i++)
            fscanf(inf,"%d",&a[i]);
        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
                if(a[i]<a[j]){
                    int tmp =a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
        b[n]=0;
        for (i=n-1;i>=0;i--)
            b[i]=b[i+1]+a[i];
        fprintf(outf,"Case #%d:\n",ii+1);
        flag=true;
        search(0,0,0);
        if (flag)
            fprintf(outf,"Impossible\n");
    }
    fclose(outf);
    fclose(inf);
}
