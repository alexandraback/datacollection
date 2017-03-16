#include<iostream>
#include<vector>
#include<cstdio>
#include<sstream>

#define pii pair<int,int>
#define ppiii pair<pii,int>
#define vi vector<int>
#define uli unsigned long int
#define ulli unsigned long long int
#define pss pair<string,string>
#define mapspss map<string,pair<string,string> >

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("A-small-attempt1.in","r",stdin);
        //freopen("input.txt","r",stdin);
        freopen("outp1.txt","w",stdout);
    #endif
    
    int T;
    scanf("%d",&T);
    int t=1;
    while(T--)
    {
              int a,n;
              cin>>a>>n;
              
              vector<int> mark(1000001,0);
              int maxn=0;
              
              for(int i=0;i<n;i++)
              {
                      int x;
                      scanf("%d",&x);
                      mark[x]++;
                      if(x>maxn)     maxn=x;
              }
              
              int done=n;
              int best=n;
              
              for(int i=0;i<=maxn;)
              {
                      while(i<a && (mark[i]>0))
                      {
                                a+=i;
                                mark[i]--;
                                done--;
                      }
                      
                      if(done<best)    best=done;
                      
                      if(done>(n+n)) break;
                      
                      if(mark[i]>0)
                      {
                                   done++;
                                   a=a+a-1;
                      }
                      else
                          i++;
              }
              
              printf("Case #%d: %d\n",t++, best);
    }
    
    return 0;
}
