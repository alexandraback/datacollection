#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <map>
using namespace std;
int c[8][2];
int n,m;
int dc[9],ct;
char aa[20000][20];
int tb[20000][9];
int list[12];
long long tmp[5000];
map<long long,int> gg[19000];

void dfs(int x,int p){
    if(x==n){
        int t=0;
        for( int i=2; i<=m; i++ ){
            tb[ct][i]=dc[i];
            for( int j=0; j<dc[i]; j++ ){
                list[t++]=i;
            }
        }
        for( int i=0; i<t; i++ ){
            aa[ct][i]=list[i]+'0';
        }
        int N=(1<<n);
        for( int i=0; i<N; i++ ){
            long long d=0;
            for( int j=0; j<n; j++ ){
                if(i&(1<<j)){
                    d*=list[j];
                }
            }
            tmp[i]=d;
        }
        sort(tmp,tmp+N);
        tmp[N]=-1;
        for( int i=0,j=-1; i<N; i++ ){
            if(tmp[i]!=tmp[i+1]){
                gg[ct][tmp[i]]=i-j;
                j=i;
            }
        }
        ct++;
    }else{
        for( int i=p; i<=m; i++ ){
            dc[i]++;
            dfs(x+1,i);
            dc[i]--;
        }
    }
}

int main(){
    int TT,tt,r,i,j,k,h,d,z,x;
    scanf("%*d");
    scanf("%d %d %d %d",&TT,&n,&m,&r);
    puts("Case #1:");
    dfs(0,2);

    for( tt=0; tt<TT; tt++ ){
        map<long long,int> tc;
        for( i=0; i<r; i++ ){
            long long xx;
            cin >> xx;
            tc[xx]++;
        }
        int ans=0;
        double md=0;
        for( i=0; i<ct; i++ ){
            int flag=1;
            double d=1;
            for( map<long long,int>::iterator it=tc.begin(); it!=tc.end(); ++it ){
                if(gg[i].find(it->first)==gg[i].end()){
                    flag=0;
                    break;
                }
                d*=gg[i][it->first];
            }
            if(flag){
                if(d>md){
                    md=d;
                    ans=i;
                }
            }
        }
        puts(aa[ans]);
    }
    return 0;
}
