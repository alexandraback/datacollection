#include<cstdio>
#include<cstring>
using namespace std;
long long T,n,ac,a[1000005],k,cnt,len,tmp,p,t;
char s[1000005];
int main(){
    scanf("%I64d",&T); t=0;
    while (T--){
          scanf("%s%I64d",s,&n);
          len=strlen(s);
          cnt=0; k=0;
          for (int i=0; i<len; i++){
              if (s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'){
                 ++cnt;
                 if (i==len-1){
                   for (int j=n; j<=cnt; j++){
                       a[++k]=i-(cnt-j+1)+1-n+1;
                   }
                   cnt=0;                                  
                 }
              }
              else{
                   for (int j=n; j<=cnt; j++){
                       a[++k]=i-(cnt-j+1)+1-n;
                   }
                   cnt=0;
              }
          }
          p=1; ac=0;
          for (int i=0; i<len; i++){
              if (k==0) break;
              if (i>a[p]) ++p;
              if (p>k) break;
              tmp=a[p]+n-1;
              ac+=(len-tmp);
          }
          printf("Case #%I64d: %I64d\n",++t,ac);
    }
    return 0;    
}
