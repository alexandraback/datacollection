#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
char a[30], b[30];
long long warta=0, wartb=0;
pair<long long, long long> f(int x, int option){
  pair<long long, long long>ans;
  long long tmpa=warta, tmpb=wartb; //wartośći do poz wcześniejszej
  if(!a[x]) return make_pair(warta, wartb); //return wart końcowe
  
  warta*=10; wartb*=10;
  if(a[x]!='?') warta+=a[x]-'0';
  if(b[x]!='?') wartb+=b[x]-'0';
  if(a[x]!='?' and b[x]!='?') {
    if(!option and a[x]!=b[x]){
      if(a[x]<b[x]) option=1;
      else option=2;
    }
    ans=f(x+1,option);
    warta=tmpa; wartb=tmpb;
    return ans;
  }
  
  if(option){ //1 - A<B
    if(a[x]=='?' and option==1) warta+=9;
    if(b[x]=='?' and option==2) wartb+=9;
    ans=f(x+1, option);
    warta=tmpa; wartb=tmpb;
    return ans;
  }
  //dotychczas były równe
  if(a[x]=='?' and b[x]=='?'){
    pair<long long,long long>tab[3];
    long long r[3];
    tab[0]=f(x+1,0);
    r[0]=abs(tab[0].f-tab[0].s);
    wartb+=1;
    tab[1]=f(x+1,1);
    r[1]=abs(tab[1].f-tab[1].s);
    wartb-=1;
    warta+=1;
    tab[2]=f(x+1,2);
    r[2]=abs(tab[2].f-tab[2].s);
    long long mini=min(r[0], min(r[1],r[2]));
    for(int i=0;i<3;i++) if(r[i]==mini) { warta=tmpa; wartb=tmpb; return tab[i]; }
  }  
  pair<long long,long long>tab[3];
  long long r[3];
  
  if(a[x]=='?'){
    warta+=b[x]-'0';
    tab[1]=f(x+1,0);
    r[1]=abs(tab[1].f-tab[1].s);
    
    if(b[x]-'0'!=0) {
      warta--;
      tab[0]=f(x+1,1);
      r[0]=abs(tab[0].f-tab[0].s);
      warta++;
    }
    else r[0]=r[1]+1;

    if(b[x]-'0'!=9){
      warta++;
      tab[2]=f(x+1,2);
      r[2]=abs(tab[2].f-tab[2].s);
      warta--;
    }
    else r[2]=r[1]+1;
    long long mini=min(r[0], min(r[1],r[2]));
    for(int i=0;i<3;i++) if(r[i]==mini) { warta=tmpa; wartb=tmpb; return tab[i]; }
  }
    wartb+=a[x]-'0';
    tab[1]=f(x+1,0);
    r[1]=abs(tab[1].f-tab[1].s);
    
    if(a[x]-'0'!=0) {
      wartb--;
      tab[0]=f(x+1,2);
      r[0]=abs(tab[0].f-tab[0].s);
      wartb++;
    }
    else r[0]=r[1]+1;

    if(a[x]-'0'!=9){
      wartb++;
      tab[2]=f(x+1,1);
      r[2]=abs(tab[2].f-tab[2].s);
      wartb--;
    }
    else r[2]=r[1]+1;
    long long mini=min(r[0], min(r[1],r[2]));
    for(int i=0;i<3;i++) if(r[i]==mini) { warta=tmpa; wartb=tmpb; return tab[i]; }
}
int main(){
  int test;
  scanf("%d",&test);
  for(int t=1;t<=test;t++){
    scanf(" %s %s", a, b);
    int s=0;
    while(a[s]) s++;
    pair<long long,long long>ans=f(0,0);
    for(int j=s-1;j>=0;j--){
      
      a[j]=ans.f%10+'0';
      ans.f/=10;
      b[j]=ans.s%10+'0';
      ans.s/=10;
    }
    //liczbę zer trzeba zmienić
    printf("Case #%d: ",t);
    for(int i=0;i<s;i++) printf("%c", a[i]); printf(" ");
    for(int i=0;i<s;i++) printf("%c", b[i]); puts("");
  }
  return 0;
}