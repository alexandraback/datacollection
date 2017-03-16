#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> ans;
int N,M,n,m,d[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char s[55][55];
void print(){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++)
            printf("%c",s[i][j]);
        puts("");
    }
}
int main(){
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,x,y,C=0;
    scanf("%d",&t);
    while(t--){
        int flag=0,res;
        scanf("%d%d%d",&N,&M,&res);
        printf("Case #%d:\n",++C);
        memset(s,0,sizeof(s));
        n=N,m=M;
        while(n>2 && res>=m || m>2 && res>=n){
            if(m<n){
                if(n>2 && res>=m){
                    for(i=0;i<m;i++)
                        s[n-1][i]='*';
                    res-=m;
                    n--;

                }
                if(m>2 && res>=n){
                    for(i=0;i<n;i++)
                        s[i][m-1]='*';
                    res-=n;
                    m--;
                }
            }
            else{
                if(m>2 && res>=n){
                    for(i=0;i<n;i++)
                        s[i][m-1]='*';
                    res-=n;
                    m--;
                }
                if(n>2 && res>=m){
                    for(i=0;i<m;i++)
                        s[n-1][i]='*';
                    res-=m;
                    n--;

                }
            }
        }

        s[0][0]='c';
        //if(res==0)
        if(n==1){
            for(i=0;i<m && res;i++)
                s[n-1-0][m-1-i]='*',res--;
            for(;i<m;i++)
                s[n-1-0][m-1-i]='.';
            s[n-1-0][m-1-(m-1)]='c';
            print();
            continue;
        }
        if(m==1){
            for(i=0;i<n && res;i++)
                s[n-1-i][m-1-0]='*',res--;
            for(;i<n;i++)
                s[n-1-i][m-1-0]='.';
            s[n-1-(n-1)][m-1-0]='c';
            print();
            continue;
        }
        if(res==n*m-1){
            for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                    s[n-1-i][m-1-j]='*';
            s[n-1-(n-1)][m-1-(m-1)]='c';
            print();
            continue;
        }
        if(res>n*m-4){
            puts("Impossible");
            continue;
        }
        for(i=0;i<n-2;i++)
        for(j=0;j<m-2;j++){
            if(res==0) goto go;
            res--;
            s[n-1-i][m-1-j]='*';
        }
        go:;
        if(res%2){
            puts("Impossible");
            continue;
        }
        for(i=0;i<n-2 && res;i++){
            s[n-1-i][m-1-(m-1)]='*';
            s[n-1-i][m-1-(m-2)]='*';
            res-=2;
        }
        for(i=0;i<m-2 && res;i++){
            s[n-1-(n-2)][m-1-i]='*';
            s[n-1-(n-1)][m-1-i]='*';
            res-=2;
        }
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(s[n-1-i][m-1-j]==0){
            s[n-1-i][m-1-j]='.';
        }
        print();
    }
}
