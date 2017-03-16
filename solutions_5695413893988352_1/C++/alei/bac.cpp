#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=22;
char a[mx],b[mx];
int n;
string bp="",bq;
uli up=-1,uq=-1;
uli abso(uli a){
   if(a<0)return -a;
   return a;
}
void check(int idx){
   string p="",q="";
   for(int i=0;i<=idx;i++){
      p.push_back(a[i]);
      q.push_back(b[i]);
   }
   if(a[idx]<b[idx]){
      for(int i=idx+1;i<n;i++){
         char cha=a[i];
         if(cha=='?')cha='9';
         char chb=b[i];
         if(chb=='?')chb='0';
         p.push_back(cha);
         q.push_back(chb);
      }
   }
   else{
      for(int i=idx+1;i<n;i++){
         char cha=a[i];
         if(cha=='?')cha='0';
         char chb=b[i];
         if(chb=='?')chb='9';
         p.push_back(cha);
         q.push_back(chb);
      }
   }
   //   cout<<p<<";"<<q<<endl;
   assert((int)p.size()==n);
   assert((int)q.size()==n);
   for(int i=0;i<n;i++)assert(p[i]!='?');
   for(int i=0;i<n;i++)assert(q[i]!='?');

   uli pv=0,qv=0;   
   for(int i=0;i<int(p.size());i++)pv=pv*10ll+uli(p[i]-'0');
   for(int i=0;i<int(q.size());i++)qv=qv*10ll+uli(q[i]-'0');
   pair<uli,pair<uli,uli> >dif1=make_pair(abso(pv-qv),make_pair(pv,qv));
   pair<uli,pair<uli,uli> >dif2=make_pair(abso(up-uq),make_pair(up,uq));
   if(up==-1 || dif1<dif2){
      bp=p,bq=q;
      up=pv;
      uq=qv;
   }
}
string itos(int v){
   if(v==0)return "0";   
   string ans="";
   for(;v!=0;v/=10)ans=string(1,'0'+(v%10))+ans;
   if((int)ans.size()<n)ans=string(n-int(ans.size()),'0')+ans;
   return ans;
}
int main(){
   freopen("bal.in","r",stdin);
   freopen("bal.out","w",stdout);
   int t;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      bp=bq="";
      up=uq=-1;
      scanf("%s %s",a,b);
      n=strlen(a);
      bool eq=true;
      for(int i=0;i<n;i++){
         if(a[i]=='?' && b[i]=='?'){
            for(int x=0;x<10;x++){
               for(int y=0;y<10;y++)if(x!=y){
                  a[i]=x+'0';
                  b[i]=y+'0';
                  check(i);
               }
            }
            a[i]=b[i]='0';
         }
         else if(a[i]=='?' && b[i]!='?'){
            for(int x=0;x<10;x++)if(x!=b[i]-'0'){
               a[i]=x+'0';
               check(i);
            }
            a[i]=b[i];
         }
         else if(a[i]!='?' && b[i]=='?'){
            for(int x=0;x<10;x++)if(x!=a[i]-'0'){
               b[i]=x+'0';
               check(i);
            }
            b[i]=a[i];
         }
         else if(a[i]!=b[i]){
            eq=false;
            check(i);
            break;
         }
      }
      /*
         uli bestp=-1,bestq;
         string sp,sq;
         for(int a=0,a<1000;a++){
         for(int b=0,b<1000;b++){
         string sa=itos(a,n);
         string sb=itos(b,n);
         if(sa.size()!=n || sb.size()!=n)continue;
         bool ok=true;
         for(int i=0;i<n;i++){
         if(a[i]==sa[i] || a[i]=='?'){}
         else ok=false;
         if(b[i]==sb[i] || b[i]=='?'){}
         else ok=false;
         }
         if(ok){
         if(bestp==-1 || dif1<dif2){
         }
         }
         }
         }
      */
      if(eq)check(n-1);
      printf("Case #%d: %s %s\n",tt,bp.c_str(),bq.c_str());
   }
   return 0;
}
