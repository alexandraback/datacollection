#include<cmath>
#include<cstdio>
#include<fstream>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<cassert>

#define f(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define BIG 2000005
#define inp(x) scanf("%d",&(x))
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,bool> pib;
typedef long long lol;
typedef unsigned long long ull;
typedef pair<lol,lol> pll;

ifstream fin;
ofstream fout;

int main()
{
    
    fin.open("C-small-attempt0.in");
    fout.open("C.out");
    
    int cas;
    int n;
    int tmp,maxn,curr,currp2;
    int s1,s2;
    fin>>cas;
    f(caseno,1,cas+1)
    {
       fin>>n;
       int num[n];
       f(i,0,n)fin>>num[i];
       maxn=1;
       f(i,0,n)maxn*=2;
       int dp[maxn];
       dp[0]=0;
       curr=0;
       currp2=1;
       fout<<"Case #"<<caseno<<":\n";
       vector<pair<int,int> > anses;
       cerr<<"h";
       f(i,1,maxn)
       {
                  
		  if(currp2*2<=i)
                  {
                                     currp2*=2;
                                     curr++;
				     cerr<<curr<<"\n";
                  }
                  dp[i]=dp[i-currp2]+num[curr];
                  anses.pb(mp(dp[i],i));
       }        
       sort(anses.begin(),anses.end());
       cerr<<"h";
       f(i,0,anses.sz-1)
       {
                        if(anses[i].x==anses[i+1].x)
                        {
                                                    s1=anses[i].y;
                                                    s2=anses[i+1].y;
                                                    tmp=s1&s2;
                                                    s1-=tmp;
                                                    s2-=tmp;
                                                    int at=1;
                                                    vector<int> a1,a2;
                                                    f(i,0,20)
                                                    {
                                                             if(s1&at) a1.pb(num[i]);
                                                             if(s2&at) a2.pb(num[i]);
                                                             at<<=1;
                                                    }
                                                    f(i,0,a1.size())
                                                    {
                                                                    fout<<a1[i]<<" ";
                                                    }
                                                    fout<<"\n";
                                                     f(i,0,a2.size())
                                                    {
                                                                    fout<<a2[i]<<" ";
                                                    }
                                                    fout<<"\n";     
                                                    break;
                        }
       }
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
