#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#define PB push_back
#define MP make_pair
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
string ss,mul;
int pos1,pos2,l,x;
char multi(char c1,char c2);
int getid(char ch);
int Find(char ch);
void solve();
int main()
{
         freopen("C-large.in","r",stdin);
         freopen("C-large.out","w",stdout);
         int T,ca=0;
         scanf("%d",&T);
         while(T--){
                  ss="",mul="";
                  cin>>l>>x;
                  cin>>ss;
                  mul+=ss[0];
                  for(int i=1;i<l;i++){
                           mul+=multi(mul[i-1],ss[i]);
                  }
                  char now='a';
                  int tmp=x%4;
                  for(int i=0;i<tmp;i++){
                           now=multi(now,mul[l-1]);
                  }
                  printf("Case #%d: ",++ca);
                  if(now!='A') puts("NO");
                  else {
                           solve();
                           if(pos1==-1||pos2==-1) puts("NO");
                           else {
                                    if(pos1>pos2) puts("NO");
                                    else puts("YES");
                           }
                  }

         }
         return 0;
}
char multi(char c1,char c2)
{
         if(c1=='a') return c2;
         else if(c1=='A') return c2>='A'&&c2<='Z'?(c2-'A'+'a'):(c2-'a'+'A');
         else if(c1=='i') {
                  if(c2=='a') return 'i';
                  else if(c2=='A') return 'I';
                  else if(c2=='i') return 'A';
                  else if(c2=='I') return 'a';
                  else if(c2=='j') return 'k';
                  else if(c2=='J') return 'K';
                  else if(c2=='k') return 'J';
                  else if(c2=='K') return 'j';
         }
         else if(c1=='I'){
                  if(c2=='a') return 'I';
                  else if(c2=='A') return 'i';
                  else if(c2=='i') return 'a';
                  else if(c2=='I') return 'A';
                  else if(c2=='j') return 'K';
                  else if(c2=='J') return 'k';
                  else if(c2=='k') return 'j';
                  else if(c2=='K') return 'J';
         }
         else if(c1=='j'){
                  if(c2=='a') return 'j';
                  else if(c2=='A') return 'J';
                  else if(c2=='i') return 'K';
                  else if(c2=='I') return 'k';
                  else if(c2=='j') return 'A';
                  else if(c2=='J') return 'a';
                  else if(c2=='k') return 'i';
                  else if(c2=='K') return 'I';
         }
         else if(c1=='J'){
                  if(c2=='a') return 'J';
                  else if(c2=='A') return 'j';
                  else if(c2=='i') return 'k';
                  else if(c2=='I') return 'K';
                  else if(c2=='j') return 'a';
                  else if(c2=='J') return 'A';
                  else if(c2=='k') return 'I';
                  else if(c2=='K') return 'i';
         }
         else if(c1=='k'){
                  if(c2=='a') return 'k';
                  else if(c2=='A') return 'K';
                  else if(c2=='i') return 'j';
                  else if(c2=='I') return 'J';
                  else if(c2=='j') return 'I';
                  else if(c2=='J') return 'i';
                  else if(c2=='k') return 'A';
                  else if(c2=='K') return 'a';
         }
         else if(c1=='K'){
                  if(c2=='a') return 'K';
                  else if(c2=='A') return 'k';
                  else if(c2=='i') return 'J';
                  else if(c2=='I') return 'j';
                  else if(c2=='j') return 'i';
                  else if(c2=='J') return 'I';
                  else if(c2=='k') return 'a';
                  else if(c2=='K') return 'A';
         }
}
void solve()
{
         int now='a';
         pos1=pos2=-1;
         for(int i=0;i<min(8,x);i++){
                  for(int j=0;j<l;j++){
                           if(multi(now,mul[j])=='i'&&pos1==-1) pos1=i*l+j;
                           else if(multi(now,mul[j])=='k') pos2=i*l+j;
                  }
                  now=multi(now,mul[l-1]);
         }
}
