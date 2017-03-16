#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#define maxn 105
#define eps 1e-8

using namespace std;

int test,ttest,f[maxn][maxn],n,l,s,root,tot,q[maxn],len,tmax;

char a[maxn],c[maxn];

double g[maxn][maxn][maxn],ans;

struct Tnode
 {
  int son[26],fail,en;
 }trie[maxn];


int ins()
 {
  int i,j,k;
  root=0;
  for (i=0;i<l;i++)
   {
    k=c[i]-'A';
    if (!trie[root].son[k])
     {
      tot++;trie[root].son[k]=tot;
     }
    root=trie[root].son[k];
   }
  trie[root].en=1;
  return root;
 }

void getfail()
 {
  int i,j,k,head,tail,f;
  head=0;tail=0;
  for (i=0;i<26;i++)if (trie[0].son[i])
   {
    k=trie[0].son[i];q[++tail]=k;
   }
  while (head<tail)
   {
    j=q[++head];f=trie[j].fail;
    for (i=0;i<26;i++)if (trie[j].son[i])
     {
      k=trie[j].son[i];
      trie[k].fail=trie[f].son[i];q[++tail]=k;
     }
    else trie[j].son[i]=trie[f].son[i];
   }
 }

void init()
 {
     scanf("%d%d%d\n",&n,&l,&s);
     int i,j;
     gets(a);
     gets(c);
 }

void work()
 {
    printf("Case #%d: ",ttest);
    memset(trie,0,sizeof(trie));
    int i,j,k,t,nxt;
    for (i=0;i<=100;i++)
     {
         for (j=0;j<26;j++)trie[i].son[j]=0;trie[i].fail=trie[i].en=0;
     }
    root=0;tot=0;
    ins();
    getfail();
    memset(g,0,sizeof(g));
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for (i=0;i<s;i++)
        for (j=0;j<=tot;j++)if (f[i][j]!=-1)
    {
        for (k=0;k<n;k++)
            f[i+1][trie[j].son[a[k]-'A']]=max(f[i+1][trie[j].son[a[k]-'A']],f[i][j]+trie[trie[j].son[a[k]-'A']].en);
    }
    tmax=0;
    for (i=0;i<=tot;i++)tmax=max(tmax,f[s][i]);
    /*for (i=0;i<=s;i++)
        for (j=0;j<=tot;j++)if (f[i][j]!=-1)printf("%d %d %d\n",i,j,f[i][j]);*/
    g[0][0][0]=1;
    for (i=0;i<s;i++)
        for (j=0;j<=tot;j++)
          for (k=0;k<=s;k++)
    {
        if (fabs(g[i][j][k])<=eps)continue;
        for (t=0;t<n;t++)
        {
            nxt=trie[j].son[a[t]-'A'];
            if (trie[nxt].en)
              g[i+1][nxt][k+1]+=g[i][j][k]/n;
              else g[i+1][nxt][k]+=g[i][j][k]/n;
        }
    }
    ans=0;
    for (i=0;i<=tot;i++)
        for (j=0;j<=s;j++)
            ans+=j*g[s][i][j];
    printf("%.8lf\n",tmax-ans);
 }

int main()
 {
     freopen("B.in","r",stdin);
     freopen("B.out","w",stdout);
     scanf("%d\n",&test);
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
