#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#define sc(b,c) fscanf(in,b,c)
#define pr(b,c) fprintf(out,b,c)
#define eps 1e-9
FILE *in,*out;
using namespace std;
int n;
vector<int> adj[1002];
bool vis[1002];
int dp[1002][1002];
int mat[1002][1002];
int ans;
int T;
vector<int> tsort;
int main(){
    in = fopen("input.txt","r");
    out = fopen("output.txt","w");
    int cases=1;
    sc("%d",&T);
    while(T--){
        sc("%d",&n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) mat[i][j]=0;
        for(int i=0;i<n;i++){
            int num,u;
            sc("%d",&num);
            for(int j=0;j<num;j++){
                sc("%d",&u);
                adj[i].push_back(u-1);
                mat[i][u-1]++;
            }
        }
        ans=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                if(mat[i][k])
                for(int j=0;j<n;j++){
                    mat[i][j]+=(mat[i][k]*mat[k][j]);
                    if(mat[i][j]>1){
                        ans=1;
                        break;
                    }
                }
            }
        }
        end:
        pr("Case #%d: ",cases);
        if(ans) fprintf(out,"Yes");
        else fprintf(out,"No");
        fprintf(out,"\n");
        cases++;
    }
    fclose(out);
    return 0;
}


