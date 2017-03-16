#include<utility>
#include<limits>
#include<cstring>
#include<locale>
#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>

#define ll long long
#define ull unsigned long long
using namespace std;

int tab[1000010];

int isvowel(char c);
int main()
{
    freopen("A.txt","r",stdin);
     freopen("out.txt","w",stdout);


          int t;

          cin>>t;

          for(int T=1;T<=t;T++)
          {
                                  char s[1000010];

                                  int x;

                                  cin>>s>>x;


                                  int n=strlen(s);

                                  ll ans=0,cnt=0,st=(int)1e7;

                                  int tmp=0;

                                  memset(tab,0,sizeof tab);

                                  for(int i=0;i<n;i++)
                                  {
                                          if(!isvowel(s[i]))
                                          {
                                                     st=min(st,(ll)i);

                                                     if(cnt+1==x)
                                                     {

                                                     if(tmp==0)
                                                     ans+=(n-(i+1)+1)*(st+1);
                                                     else
                                                     ans+=(n-(i+1)+1)*st;

                                                     tmp++;
                                                     //ans-=1;
                                                     tab[st]=1;
                                                     tab[i]=1;
                                                     cnt=x-1;
                                                     }
                                                     else cnt++;
                                          }
                                          else cnt=0,st=(int)1e7;
                                  }



                                  cout<<"Case #"<<T<<": "<<ans<<"\n";
          }
          scanf("\n");
          return 0;
}
int isvowel(char c)
{
    return ((c=='a') or (c=='o') or (c=='e') or (c=='i') or (c=='u'));
}
