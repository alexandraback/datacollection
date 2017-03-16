#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;
#define maxdic 2000000
#define maxn 5000
#define maxq 60000000
struct Point
{
       bool end;
       int next[26];
}a[maxdic];
struct Status
{
       int x,i,k; //x：trie位置，i：字符串位置， k:上次变化位置 
       bool operator<(const Status &b)const
       {
            if (x!=b.x) return x<b.x;
            if (i!=b.i) return i<b.i;
            return k<b.k;
       }
       bool operator==(const Status &b)const
       {
            if (x==b.x && i==b.i && k==b.k) return 1;
               else return 0;
       }
}tmp;
Status q[maxq];
map<Status,int> mp;
map<Status,int>::iterator it;
int n,tot=0,i,j,k,tst,cas,l,r,x,nxt;
int val,ans;
char c[51],s[maxn];
void Insert(int x,char *c,int len,int i)
{
     int nxt=(int)(c[i]-'a');
     if (i==len)
     {
        a[x].end=1;
        return;
     }
     if (a[x].next[nxt]==0)
     {
        a[x].next[nxt]=++tot;
     }
     Insert(a[x].next[nxt],c,len,i+1);
}
void update(int x,int val,int j,int k)
{
     k++;
     if (k>4) k=4;
     tmp.x=x;
     tmp.i=j;
     tmp.k=k;
     re:
     it=mp.find(tmp);
     if (it==mp.end())
     {
        mp.insert(pair<Status,int>(tmp,val));
        q[r++]=tmp;
        if (r>=maxq) r=0;
     }
     else
     if ((it->second)>val)
     {
        it->second=val;
     }
     if (a[x].end)
     {
        tmp.x=0;
        x=0;
        goto re;
     }
}
int main()
{
    memset(a,0,sizeof(a));
    FILE *F;
    F=fopen("dictionary.txt","r");
    int cnt=0;
    while (fscanf(F,"%s",c)!=EOF)
    {
          Insert(0,c,strlen(c),0);
          cnt++;
    }
    fclose(F);
//    cout<<" "<<cnt<<" "<<tot<<endl;
    scanf("%d",&tst);
    for (cas=1;cas<=tst;cas++)
    {
        scanf("%s",s);
        n=strlen(s);
        mp.clear();
        tmp.x=0;
        tmp.k=4;
        tmp.i=0;
        l=0;
        r=1;
        q[0]=tmp;
        mp.insert(pair<Status,int>(tmp,0));
        ans=0x7fffffff;
        while (l!=r)
        {
              x=q[l].x;
              j=q[l].i;
              k=q[l].k;
              val=mp[q[l]];
//              cout<<x<<" "<<j<<" "<<k<<" "<<val<<endl;
              l++;
              if (l>=maxq) l=0;
              if (j>=n)
              {
                 if (x==0)
                    if (val<ans) ans=val;
                 continue;
              }
              nxt=(int)(s[j]-'a');
              if (a[x].next[nxt]>0)
              {
                 update(a[x].next[nxt],val,j+1,k);
              }
              if (k==4)
                 for (i=0;i<26;i++)
                     if (a[x].next[i]>0 && i!=nxt)
                     {
                        update(a[x].next[i],val+1,j+1,-1);
                     }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
