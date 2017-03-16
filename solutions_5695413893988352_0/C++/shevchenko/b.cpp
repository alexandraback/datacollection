#include<stdio.h>
#include<string.h>

int l;
char C[20], J[20];
long long d[20][3];
int v[20][3][2];

int valid(int i, int c, int j){
    if(C[l-i-1] != '?' && C[l-i-1]-'0' != c) return false;
    if(J[l-i-1] != '?' && J[l-i-1]-'0' != j) return false;
    return true;
}

long long labs(long long d){
    if(d<0) return -d;
    return d;
}
long long f(int i, int c, int j){
    long long mul=1;
    for(;i>0;i--) mul*=10;
    return mul * (long long)(c-j);
}

void upd(int i, int k, int c, int j, long long val){
    if(d[i][k] == val){
        if(c < v[i][k][0] || (c == v[i][k][0] && j < v[i][k][1])){
            v[i][k][0] = c;
            v[i][k][1] = j;
        }
    }
    if(d[i][k] > val || v[i][k][0] == -1){
        d[i][k] = val;
        v[i][k][0] = c;
        v[i][k][1] = j;
    }
}

void process(){
    int i,c,j,k,cp,jp;
    for(k=0;k<3;k++) v[0][k][0] = -1;
    for(c=0;c<10;c++){
        for(j=0;j<10;j++){
            if(!valid(0,c,j)) continue;
            upd(0,0, c,j, c-j);
            upd(0,1, c,j, labs(c-j));
            upd(0,2, c,j, j-c);
        }
    }

    for(i=1;i<l;i++){
        for(k=0;k<3;k++) v[i][k][0] = -1;
        for(c=0;c<10;c++){
            for(j=0;j<10;j++){
                if(!valid(i,c,j)) continue;
                if(c > j){
                    upd(i,0, c,j, f(i,c,j)+d[i-1][0]);
                    upd(i,1, c,j, f(i,c,j)+d[i-1][0]);
                    upd(i,2, c,j, f(i,j,c)+d[i-1][2]);
                }
                else if(c < j){
                    upd(i,0, c,j, f(i,c,j)+d[i-1][0]);
                    upd(i,1, c,j, f(i,j,c)+d[i-1][2]);
                    upd(i,2, c,j, f(i,j,c)+d[i-1][2]);
                }
                else{
                    upd(i,0, c,j, d[i-1][0]);
                    upd(i,1, c,j, d[i-1][1]);
                    upd(i,2, c,j, d[i-1][2]);
                }
            }
        }
    }

    i = l-1; k = 1;
    while(1){
        c = v[i][k][0]; j = v[i][k][1];
        C[l-i-1] = c+'0';
        J[l-i-1] = j+'0';
        if(i == 0) break;
        if(k == 1){
            if(c > j) k = 0;
            if(c < j) k = 2;
        }
        i--;
    }
    printf("%s %s\n", C, J);
}

int main(){
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%s%s",C,J);
        l = strlen(C);
        printf("Case #%d: ", t);
        process();
    }
    return 0;
}
