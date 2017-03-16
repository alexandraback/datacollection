#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
void work();
int main()
{
  int T;
  scanf("%d", &T);
  for(int i = 1; i <=T; i++){
    printf("Case #%d: ",i);
    work();
  }
}

void work()
{
  int n;
  double ken[2000],nao[2000];
  scanf("%d",&n);
  for(int i =0; i < n;i++)
    scanf("%lf",&nao[i]);
  for(int i = 0; i < n;i++)
    scanf("%lf", & ken[i]);
  sort(nao,nao+n);
  sort(ken,ken+n);
  int p =n-1,q=n-1, x = 0,y=0;
  int ans1=0,ans2=0;
  int usen[2000]={0},usek[2000]={0};
  for(int i = 0;i < n;i++){
    p = n-1;q=n-1;
    while(usen[p])p--;
    while(usek[q])q--;
    if(nao[p]>ken[q]){
      ans1++;
      x =0;y=0;
      while(usek[y])y++;
      usek[y]=1;
      while(nao[x] < ken[y] || usen[x]==1)x++;
      usen[x]=1;
    }
    else{
      usek[q]=1;
      x = 0;
      while(usen[x])x++;
      usen[x]=1;
    }
  }
  p = n-1, q=n-1;
  for(int i = 0; i <n;i++){
    if(nao[p] > ken[q]){
      p--;
      ans2++;
    }
    else{
      p--;
      q--;
    }
  }
  printf("%d %d\n",ans1,ans2);
  /*for(int i = 0; i <n;i++)
    cerr << nao[i] << ' ';
  cerr << endl;
  for(int i = 0; i <n;i++)
    cerr << ken[i] << ' ';
    cerr << endl;*/
  
}
