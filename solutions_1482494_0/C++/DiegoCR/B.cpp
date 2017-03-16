#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct p{
  int a,b;
  }arr[1010];

int mem[2005][1010];
int marca[1010];
int n,ok;

int rec(int ns,int pos){
     //cout<<ns<<" "<<pos<<" "<<ok<<endl;
     if(mem[ns][pos]) return mem[ns][pos];
     int st = 0,m = 5000,y;
     if(ns>=arr[pos].b){
       if(marca[pos] == 0) st = 2;
       else st = 1;
       marca[pos] = 2;
       ok ++;
       }
     if(ns>=arr[pos].a && marca[pos] == 0){
       marca[pos] = 1;
       st = 1;
       }
     if(st == 0){ mem[ns][pos]=5000; return 5000;}
     if(ok == n){ if(marca[pos] == 2)ok--; marca[pos] = 0; return 1;}
     for(int i=0;i<n;i++){
       if(marca[i] == 2) continue;
       y = rec(ns+st,i);
       if(y<m) m = y;
       }
     if(marca[pos] == 2)ok--;
     marca[pos] = 0;
     mem[ns][pos] = 1 + m;
     return m + 1;
     }

int main(){
    
    int tc=0,nc,men,x;
    //freopen("b1.in","r",stdin);
    //freopen("b.out","w",stdout);
    cin>>nc;
    while(nc--){
      scanf("%d",&n);
      tc++;
      men = 5000;
      ok = 0;
      for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].a,&arr[i].b);
        }
      memset(mem,0,sizeof(mem));
      for(int i=0;i<n;i++){
        x = rec(0,i);
        if(x<men) men = x;
        }
      if(men == 5000)
             printf("Case #%d: Too Bad\n",tc);
      else
             printf("Case #%d: %d\n",tc,men);
      }
    
    }
