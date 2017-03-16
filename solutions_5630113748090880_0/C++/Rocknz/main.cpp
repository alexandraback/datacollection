#include<stdio.h>
#include<memory.h>
#include <stdlib.h>

FILE *fo = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Roun1/2/input.txt","r");
FILE *fp = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Roun1/2/output.txt","w");
int l[110][55],table[55][55],n,lc;
int xx[55],yy[55],t;
bool checkx(int pos,int x,int y){
    int i;
    for(i=0;i<y;i++) {
        if (table[x][i] != l[pos][i] && table[x][i] != 0)
            return false;
    }
    return true;
}
bool checky(int pos,int x,int y){
    int i;
    for(i=0;i<x;i++) {
        if (table[i][y] != l[pos][i] && table[i][y] != 0)
            return false;
    }
    return true;
}
bool end = false;
void add(int pos,int x,int y){
    if(pos == lc){
        end = true;
        return;
    }else{
        int i;
        bool ches;
        if(x != n){
            if(checkx(pos,x,y)) {
                ches = true;
                for (i = y; i < n; i++) {
                    table[x][i] = l[pos][i];
                    if (x != 0 && table[x - 1][i] > table[x][i]) {
                        ches = false;
                    }
                }
                if (ches) {
                    xx[x] = pos;
                    add(pos + 1, x + 1, y);
                    if (end)return;
                    xx[x] = -1;
                }
                for(i=y;i<n;i++){
                    table[x][i] = 0;
                }
            }
        }
        if(y != n){
            if(checky(pos,x,y)){
                ches = true;
                for(i=x;i<n;i++){
                    table[i][y] = l[pos][i];
                    if (y != 0 && table[i][y-1] > table[i][y]) {
                        ches = false;
                    }
                }
                if(ches) {
                    yy[y] = pos;
                    add(pos + 1, x, y + 1);
                    if (end)return;
                    yy[y] = -1;
                }
                for(i=x;i<n;i++){
                    table[i][y] = 0;
                }
            }
        }
        if(x+1 < n){
            if(checkx(pos,x+1,y)){
                ches = true;
                for(i=y;i<n;i++){
                    table[x+1][i] = l[pos][i];
                    if (x != 0 && table[x - 1][i] > table[x+1][i]) {
                        ches = false;
                    }
                }
                if(ches) {
                    xx[x] = -1;
                    xx[x + 1] = pos;
                    add(pos + 1, x + 2, y);
                    if (end)return;
                    xx[x] = -1;
                    xx[x + 1] = -1;
                }
                for(i=y;i<n;i++){
                    table[x+1][i] = 0;
                }
            }
        }
        if(y+1 < n){
            if(checky(pos,x,y+1)){
                ches = true;
                for(i=x;i<n;i++){
                    table[i][y+1] = l[pos][i];
                    if (y != 0 && table[i][y-1] > table[i][y+1]) {
                        ches = false;
                    }
                }
                if(ches) {
                    yy[y] = -1;
                    yy[y + 1] = pos;
                    add(pos + 1, x, y + 2);
                    if (end)return;
                    yy[y] = -1;
                    yy[y + 1] = -1;
                }
                for(i=x;i<n;i++){
                    table[i][y+1] = 0;
                }
            }
        }
    }
}
int main(){
    int t,T,i,j,k,temp;
    fscanf(fo,"%d",&T);
    for(t=1;t<=T;t++){
        memset(l,0,sizeof(l));
        memset(table,0,sizeof(table));
        memset(xx,-1,sizeof(xx));
        memset(yy,-1,sizeof(yy));

        fscanf(fo,"%d",&n);
        lc = n * 2 - 1;
        for(i=0;i<lc;i++){
            for(j=0;j<n;j++){
                fscanf(fo,"%d ",&l[i][j]);
            }
        }
        for(i=0;i<lc;i++){
            for(j=i+1;j<lc;j++){
                int a = 0;
                for(k=0;k<n;k++){
                    if(l[i][k] != l[j][k]){
                        if(l[i][k] < l[j][k]) a = 1;
                        else a = 2;
                        break;
                    }
                }
                if(a == 2){
                    for(k=0;k<n;k++){
                        temp = l[i][k];
                        l[i][k] = l[j][k];
                        l[j][k] = temp;
                    }
                }
            }
        }
        end = false;
        add(0,0,0);
        fprintf(fp,"Case #%d: ",t);
        for(i=0;i<n;i++){
            if(xx[i] == -1){
                for(j=0;j<n;j++){
                    fprintf(fp,"%d ",l[yy[j]][i]);
                }
            }
            if(yy[i] == -1){
                for(j=0;j<n;j++){
                    fprintf(fp,"%d ",l[xx[j]][i]);
                }
            }
        }
        fprintf(fp,"\n");
    }
    return 0;
}