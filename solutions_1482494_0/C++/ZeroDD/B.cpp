#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int nt,T,N;
typedef struct{int a;int b;} level;
level l[1001];
int t[1001],s[1001];
bool ff,f[1001];

bool cmp(level p,level q) {
     if (p.b!=q.b) return (p.b<q.b);
     else return (p.a<=q.a);
}

int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    nt=0;cin>>T;
    while (T--) {
          nt++;
          cin>>N;
          memset(l,0,sizeof(l));
          memset(s,0,sizeof(s));
          memset(t,0,sizeof(t));
          t[0]=0;s[0]=0;ff=true;
          for (int i=1;i<=N;i++) {cin>>l[i].a>>l[i].b;f[i]=false;}
          sort(l+1,l+1+N,cmp);
          for (int i=1;i<=N;i++) {
              s[i]=s[i-1];t[i]=t[i-1];
              while (s[i]<l[i].b) {
                    int temp=s[i];
                    for (int j=N;j>=i;j--) {
                        if ((l[j].a<=s[i])&&(!f[j])) {s[i]++;t[i]++;f[j]=true;break;}
                    }
                    if (s[i]==temp) {ff=false;break;}
              }
              if (l[i].b<=s[i]) {
                 if (!f[i]) s[i]+=2;else s[i]+=1;
                 t[i]++;f[i]=true;
              }
              else break;
          }
          if (ff) printf("Case #%d: %d\n",nt,t[N]);
          else printf("Case #%d: Too Bad\n",nt);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
