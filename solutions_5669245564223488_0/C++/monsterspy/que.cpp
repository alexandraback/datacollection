#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <locale>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
#include <string>
using namespace std;
 
//end of header files
 
 
//definitions
 
#define MOD 10000007
#define MAX 1562501
#define llu long long unsigned
#define lld long long
#define ld long
 
//end of definitions
//#ifndef ONLINE_JUDGE
//#define getchar_unlocked() getchar()
//#define putchar_unlocked(x) putchar(x)
//#endif // ONLINE_JUDGE 
 
 
int scan_d()    {register int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {register int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {register int ip=getchar_unlocked(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {register int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
void scan_str(bool &f)   {register char pr='\0',ip=getchar_unlocked();int flag=0;while(1){ if(ip=='\n') break; if(pr!='\0' && flag!=2){if(ip!=pr) flag++; else flag=0; if(flag==2) f=1;} pr=ip; ip=getchar_unlocked();} return;}  
//end of fast input
 
//fast output
 
//no line break
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
 
//new line
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
 
//special char
char sp;
void printsp_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
 

ill powe(int aa,int b)
{
    ill ans=1;
    ill a=aa*1LL;
    while(b)
    {
        if(b&1)
            ans=(ans*1LL*a)%mod;
        a=(a*1LL*a)%mod;
        b=b/2;
    }
    return ans;
}
ill modinv(int a)
{
    return powe(a,mod-2);
}
#define eps 1e-12
#define gc getchar_unlocked

int adj[27][27],coun[27],vis[27];
ill fact[108];

ill dfs(int node)
{
    vis[node]=1;

    ill ret=fact[coun[node]];
    for(int j=0;j<27;j++)
    {
        if(adj[node][j]&&!vis[node])
            ret=(ret*1LL*dfs(j))%mod;
    }
    return ret;
}


int main()
{
    int m,t,i,j,k,l,n;
    int tt;
    //freopen("a.in","r",stdin);
    //freopen("b.out","w",stdout);

    cin(t);
    fact[0]=1LL;
    tt=1;
    for(i=1;i<=100;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%mod;
    }
    while(t--)
    {

        memset(adj,0,sizeof(adj));
        memset(coun,0,sizeof(coun));
        cin(n);
        int fg=1;
        string s[n+9];
        int indeg[27];
        memset(indeg,0,sizeof(indeg));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            int st=s[i][0]-'a';
            int gg=0;
            for(j=1;j<s[i].length();j++)
            {
                int val=s[i][j]-'a';
                if(val==st)
                    continue;
                gg=1;
                adj[st][val]++;
                indeg[val]++;
                if(adj[st][val]>1)
                    fg=0;
                st=val;
            }
            if(!gg)
                coun[st]++;
        }

        for(i=0;i<26;i++)
        {
            int c=0;
            for(j=0;j<26;j++)
            {
                if(i==j)
                    continue;
                if(adj[i][j])
                    c++;
            }
            if(c>1)
                fg=0;
        }
        //cout<<coun[0]<<"\n";
        cout<<"Case #"<<tt++<<": ";
        if(!fg)
            cout<<"0\n";
        else
        {
            ill ans=1LL;
            int c=0;
            for(i=0;i<26;i++)
            {
                if(vis[i]||indeg[i])
                   continue;
                int zz=0;
                if(coun[i])
                    zz=1;
                for(j=0;j<26;j++)
                {
                    if(adj[i][j])
                    zz=1;
                }
                if(!zz)
                    continue;
                ill z=dfs(i);
                ans=(ans*1LL*z)%mod;
                c++;
            }
            ans=(ans*1LL*fact[c])%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
