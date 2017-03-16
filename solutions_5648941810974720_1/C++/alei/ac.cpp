#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=2e3+10;
char s[mx];
int f[30];
int cnt[10];
string words[10]={
   "ZERO","TWO","FOUR","SIX","EIGHT",
   "ONE","THREE","FIVE","SEVEN","NINE"
};
string kernel="ZWUXGOTFSI";
int digs[10]={0,2,4,6,8,1,3,5,7,9};

void rem(string s,int x){
   for(int i=0;i<int(s.size());i++){
      f[s[i]-'A']-=x;
   }
}
int main(){
   freopen("al.in","r",stdin);
   freopen("al.out","w",stdout);
   int t;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      memset(f,0,sizeof f);
      memset(cnt,0,sizeof cnt);
      scanf("%s",s);      
      int n=strlen(s);
      for(int i=0;i<n;i++){
         f[s[i]-'A']++;
      }
      for(int i=0;i<10;i++){
         cnt[digs[i]]+=f[kernel[i]-'A'];
         rem(words[i],cnt[digs[i]]);
      }
      string ans="";
      for(int i=0;i<10;i++){
         ans+=string(cnt[i],i+'0');
      }
      printf("Case #%d: %s\n",tt,ans.c_str());
   }
   return 0;
}
