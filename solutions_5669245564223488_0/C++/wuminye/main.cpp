#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int DFN[103],LOW[103],Stap[1003],Belong[103],ccnt[103];
int Dindex,Stop,Bcnt;
bool instack[103];
int N;
int mmap[103][103];
void tarjan(int i)
{
    int j;
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;
    Stap[++Stop]=i;
    for (int j=0;j<N;++j)
    {
        if (mmap[i][j]==0) continue;
        if (!DFN[j])
        {
            tarjan(j);
            if (LOW[j]<LOW[i])
                LOW[i]=LOW[j];
        }
        else if (instack[j] && DFN[j]<LOW[i])
            LOW[i]=DFN[j];
    }
    if (DFN[i]==LOW[i])
    {
        Bcnt++;
        int cnt=0;
        do
        {
            j=Stap[Stop--];
            instack[j]=false;
            Belong[j]=Bcnt;
            ++cnt;
        }
        while (j!=i);
        ccnt[Bcnt-1]=cnt;
    }
}
void solve()
{
    int i;
    Stop=Bcnt=Dindex=0;
    memset(DFN,0,sizeof(DFN));
    memset(ccnt,0,sizeof(ccnt));
    for (i=0;i<N;i++)
        if (!DFN[i])
            tarjan(i);
}
string data[102];
bool check(string t)
{
     bool ifv[26];
     memset(ifv,0,sizeof ifv);
      int j=0;
     while (j<(int)t.length())
    {
        if (ifv[t[j]-'a']) return false;
        ifv[t[j]-'a']=true;
        char tp=t[j];
        while (t[j]==tp) ++j;
    }
    return true;
}
int  findchar(string t,char p)
{
    int i=t.length();
    int e=0;
    while (t[e]==t[0]) ++e;
    while (i>=e)
    {
        if (t[i]==p) return i;
        --i;
    }
    return 0;
}
bool check1()
{

    for (int i=0;i<N;++i)
        if (!check(data[i])) return false;
    memset(mmap,0,sizeof mmap);
   for (int k=0;k<26;++k)
    for (int i=0;i<N;++i)
      for (int j=0;j<N;++j)
    {
        if (i==j) continue;
        if (findchar(data[i],'a'+k) && (findchar(data[j],'a'+k) ))
            return false;
    }
   for (int i=0;i<N;++i)
      for (int j=0;j<N;++j)
      {
          if (i==j) continue;
           int tem;
            if (tem=findchar(data[j],data[i][data[i].length()-1]))
            {
                int pos=0;
                while (data[j][pos]==data[i][data[i].length()-1]) ++pos;
            //    if (pos<=tem) return false;
            }

          if (data[i][data[i].length()-1]==data[j][0])
            mmap[i][j]=1;
      }
   return true;
}
bool iifv[103];
void dfs(int k)
{
    if (iifv[k]) return;
    iifv[k]=true;
    for (int i=0;i<N;++i)
    {
        if (mmap[k][i]) dfs(i);
    }
}
int getn()
{
    int res=0;
    memset(iifv,0,sizeof iifv);
    for (int i=0;i<N;++i)
    {
        if (!iifv[i])
        {
            ++res;
            dfs(i);
        }
    }
    return res;
}
int main()
{
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
  int T,cas=0;
  cin>>T;

  while (T--)
  {
      cin>>N;
      for (int i=0;i<N;++i)
        cin>>data[i];
      printf("Case #%d: ",++cas);
      if (!check1())
      {
          cout<<"0"<<endl;
          continue;
      }
//       for (int i=0;i<N;++i)
//       {
//
//      for (int j=0;j<N;++j)
//      {
//          cout<<mmap[i][j]<<" ";
//      }
//      cout<<endl;
//       }

      solve();
//      cout<<Bcnt<<endl;
//      for (int i=0;i<Bcnt;++i)
//        cout<<ccnt[i]<<" ";
//      cout<<endl;
      int rr=getn();
      long long ans=1;
      for (int i=1;i<=rr;++i)
        ans=(ans*i)%mod;
      for (int i=0;i<Bcnt;++i)
      {
          ans=(ans*ccnt[i])%mod;
      }
      cout<<ans<<endl;
  }
}
