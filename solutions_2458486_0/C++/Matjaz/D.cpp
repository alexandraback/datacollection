#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std; 

int prev[1<<20][2];
int vis[1<<20];
int T;
int kv[25][205];
int ko[25];
int in[205];
int numk,n;


bool lahko_odprem(int x,int S){
     int kljuc=ko[x];
     int num=in[kljuc];
     for (int i=0;i<n;i++){
         if ((S&(1<<i))!=0){
            num=num+kv[i][kljuc];
            if (ko[i]==kljuc) num--;                
            }
         }
     if (num>0) return true; else return false;
     }

void dfs(int S){
     vis[S]=1;
     for (int i=0;i<n;i++){
         if (vis[(1<<n)-1]!=0) break;
         if ((S&(1<<i))==0){
             if (vis[S|(1<<i)]==0){
                 if (lahko_odprem(i,S)) {
                    prev[S|(1<<i)][0]=S;
                    prev[S|(1<<i)][1]=i;
                    dfs(S|(1<<i));
                    }
                 }               
             }
         }
     }
     
void initialize(){
     memset(kv,0,sizeof kv);
     memset(ko,0,sizeof ko);
     memset(in,0,sizeof in);
     memset(prev,-1,sizeof prev);
     memset(vis,0,sizeof vis);
     }     

void read(){
     scanf("%d %d",&numk,&n);
     for (int i=0;i<numk;i++){
         int a;
         scanf("%d",&a);
         in[a]++;
         }
     for (int i=0;i<n;i++){
         int num;
         scanf("%d %d",&ko[i],&num);
         for (int j=0;j<num;j++){
             int a;
             scanf("%d",&a);
             kv[i][a]++;
             }
         }
     }     

vector<int> path(int x){
            vector<int> v;
            if (prev[x][0]!=0){
               v=path(prev[x][0]);                
               }
            v.push_back(prev[x][1]);
            return v;
            }     

void solve(int test){
     initialize();
     read();
     prev[0][0]=0;
     prev[0][1]=0;
     dfs(0);
     if (vis[(1<<n)-1]==0) printf("Case #%d: IMPOSSIBLE\n",test); else {
        vector<int> out=path((1<<n)-1);
        printf("Case #%d:",test);
        for (int i=0;i<out.size();i++) printf(" %d",out[i]+1);
        printf("\n");
        }
     }


int main(){
    scanf("%d",&T);
    for (int i=0;i<T;i++) solve(i+1);
    return 0;
    }
