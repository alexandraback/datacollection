#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<string.h>

int a[1100], b[1100];
int n,ans;
bool f[2][1100];

int search(int left,int st,int nowans){
    bool flag = true;
    int i;
    while (flag && left>0){
        flag=false;
        for(i=0;i<n;i++)
            if(b[i]<=st&&!f[1][i]){
                nowans++;
                f[1][i]=true;
                st+=2;
                flag =true;
                left--;
                if(f[0][i]) st--;
            }
        if (flag)continue;
        int use;
        use =-1;
        for (i=0;i<n;i++)
            if(a[i]<=st&&!f[0][i]&&!f[1][i])
                if(use==-1 || b[i]<b[use]) use =i;

        if (use>=0){
            f[0][use]=true;
            st++;
            nowans++;
            flag =true;
        }
    }
    if (left==0)
        ans =nowans;
}

int main(){
    FILE *inf, *outf;
    inf = fopen("b.in","r");
    outf = fopen("b.out","w");

    int nn;
    fscanf(inf,"%d",&nn);
    int ii,i;

    for (ii=0;ii<nn;ii++){
        fscanf(inf,"%d", &n);
        for (i=0;i<n;i++)
            fscanf(inf,"%d %d", &a[i], &b[i]);
        memset(f,false,sizeof(f));
        ans=2000000;
        search(n,0,0);
        if(ans<=20000)
            fprintf(outf,"Case #%d: %d\n",ii+1,ans);
        else
            fprintf(outf,"Case #%d: Too Bad\n", ii+1);
    }
    fclose(inf);
    fclose(outf);
}

