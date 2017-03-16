#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int t,T;
int a,b;
double p[100000],s[100000];
double ans,temp;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    t=0;cin>>T;
    while (T--) {
          t++;
          cin>>a>>b;
          memset(p,0,sizeof(p));memset(s,0,sizeof(s));
          p[0]=1.0;s[0]=1.0;
          for (int i=1;i<=a;i++) {cin>>p[i];s[i]=s[i-1]*p[i];}
          ans=s[a]*(b-a+1)+(1-s[a])*(b-a+1+b+1);
          for (int i=1;i<=a;i++) {
              temp=s[a-i]*(b-(a-i)+1+i)+(1-s[a-i])*(b-(a-i)+1+i+b+1);
              if (ans-temp>1e-6) ans=temp;
          }
          if (ans-b-2>1e-6) ans=b+2;
          printf("Case #%d: %.6lf\n",t,ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
