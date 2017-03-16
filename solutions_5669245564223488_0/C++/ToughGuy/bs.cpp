#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib> 
#include <cstring>



using namespace std;

int ans;
char in[110][110];
bool isusd[110];
int n;
int se[110];  
bool isappear[110];
void bt(int now){
  if(now==n){
    memset(isappear,false,sizeof(isappear));
    char tmp=0;
    char nchar;
    for(int i=0;i<n;i++){
      for(int j=0;in[se[i]][j];j++){
        nchar = in[se[i]][j];
        if(nchar==tmp) continue;
        if(nchar!=tmp){
          if(isappear[nchar-'a'] ) return;
          isappear[nchar-'a']= true;
          tmp = nchar;    
        }


      }
    }
    ans++;
    return;
  }
  for(int i=0;i<n;i++){
    if(isusd[i]) continue;
    isusd[i]=true;
    se[now] =i;
    bt(now+1);
    isusd[i]=false;

  }

}
void ini(){
  ans=0;
  memset(isusd,false,sizeof(isusd)); 
}
int main(){
freopen("bs.out","w",stdout);
  int ca;
  int cs;
  scanf("%d",&ca);
 
 for(cs=1;cs<=ca;cs++){
    ini();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%s",in[i]);
    } 
    bt(0);
  
    printf("Case #%d: %d\n",cs,ans);
    
  }


  return 0;
}
