#include<stdio.h>
#include<string.h>
#include<memory.h>
FILE *fo = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Roun1/1/input.txt","r");
FILE *fp = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Roun1/1/output.txt","w");
int main(){
    int t,T,l,cnt,i,j,k;
    char g[1010],len[1010];
    fscanf(fo,"%d",&T);
    for(t=1;t<=T;t++){
        memset(g,0,sizeof(g));
        memset(len,0,sizeof(len));
        fscanf(fo,"%s",g);
        l = strlen(g);
        cnt = 1;
        len[0] = g[0];
        for(i=1;i<l;i++){
            if(len[0] <= g[i]){
                for(j=cnt;j>=1;j--){
                    len[j] = len[j-1];
                }
                len[0] = g[i];
                cnt ++;
            }else{
                len[cnt++] = g[i];
            }
        }
        fprintf(fp,"Case #%d: %s\n",t,len);
    }
    return 0;
}