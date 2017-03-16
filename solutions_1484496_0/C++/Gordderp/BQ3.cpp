#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int T,n;
int s[60];
int f[60];
  
int tot;
int flag;
int Ncase;
void check()
{
    flag=1;
    printf("Case #%d:\n",Ncase);
    for (int i=1;i<=n;i++) if (f[i]==1) printf("%d ",s[i]);printf("\n");
    for (int i=1;i<=n;i++) if (f[i]==-1) printf("%d ",s[i]);printf("\n");
    
    
}    

void search(int x,int t1,int t2,int num,int tot)
{
    if (flag) return;
    if (t1>0 && t1==t2) check();
    if (num>10) return;
    if (t1+tot<t2 || t2+tot<t1) return;
    if (x>n) return;
    else
    {
        f[x]=1;
        search(x+1,t1+s[x],t2,num+1,tot-s[x]);
        f[x]=-1;
        search(x+1,t1,t2+s[x],num,tot-s[x]);
        f[x]=0;
        search(x+1,t1,t2,num,tot-s[x]);
    }
}
    

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("outC.txt","w",stdout);
    cin >> T;
    Ncase=0;
    while (Ncase<T)
    {
        Ncase++;
        
        cin >> n;
        for (int i=1;i<=n;i++) cin >> s[i];
        for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (s[i]<s[j])
        {
            int tmp=s[i];s[i]=s[j];s[j]=tmp;
        }
        
        memset(f,0,sizeof f);
        tot=0;
        for (int i=1;i<=n;i++) tot+=s[i];
        flag=0;
        search(1,0,0,0,tot);
        
//        cout << " as";

        if (flag==0)
        {
            printf("Case #%d:\n",Ncase);            
            printf("Impossible\n");
        }
    }
}
    
