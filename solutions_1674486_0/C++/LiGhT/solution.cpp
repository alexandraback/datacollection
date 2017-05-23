#include<stdio.h>
#include<stdlib.h>

int path[1001][1001];
int a[1001][20];
int m[1001];
int t,n;
bool ans;
   FILE* in;
    FILE* out;

int form;

void dfs(int ii){
    for(int i=1;i<=m[ii];i++){
        if(path[form][a[ii][i]]==1){
            //fprintf(out," | %d %d | \n",form,a[ii][i]);
            ans=1;
            return;
        }
        else {
            path[form][a[ii][i]]=1;
            dfs(a[ii][i]);
        }
    }
}

int main(){
 
    in=fopen("d:/input1.in","r");
    out=fopen("d:/output1.out","w");
    
    fscanf(in,"%d",&t);
    for(int x=1;x<=t;x++){
        for(int xx=0;xx<1002;xx++)for(int yy=0;yy<1002;yy++)path[xx][yy]=0;
        fprintf(out,"Case #%d: ",x);
        fscanf(in,"%d",&n);    
        for(int i=1;i<=n;i++){
            fscanf(in,"%d",&m[i]);
            for(int j=1;j<=m[i];j++) fscanf(in,"%d",&a[i][j]);
        }    
        ans=0;
        for(int i=1;i<=n;i++){
            form=i;
            dfs(i);
        }
        if(ans==1)fprintf(out,"Yes");
        else fprintf(out,"No");
        
        if(x!=t)fprintf(out,"\n");
        
    }
    //system("pause");
}



