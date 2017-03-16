#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
const int n_max=1000005;
int t,i,j,k,n,l[n_max],T,r[n_max];
string s;
bool f[n_max];
long long ans;

bool vov(char a){
     if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')return 0;
     return 1;
}

main()
{freopen("A-large.in","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>T;
 for(t=1;t<=T;t++){
          cin>>s>>k;
          for(i=0;i<s.size();i++)l[i]=r[i]=0;
          if(vov(s[0]))l[0]=1;
          for(i=1;i<s.size();i++){
                    if(vov(s[i]))l[i]=l[i-1]+1;else l[i]=0;
          }
          //for(i=0;i<s.size();i++)cout<<l[i]<<' ';cout<<endl;
          for(i=0;i<s.size();i++)
                    if(l[i]>=k)f[i]=1;else f[i]=0;
          ans=0;
          r[s.size()]=s.size();
          for(i=s.size()-1;i>=0;i--){
                    r[i]=r[i+1];if(f[i])r[i]=i;
          }
         //  for(i=0;i<s.size();i++)cout<<r[i]<<' ';cout<<endl;
          for(i=0;i<s.size();i++)
                    if(i+k-1<s.size())ans+=(long long)MAX(0,s.size()-r[i+k-1]);
          cout<<"Case #"<<t<<": "<<ans<<endl;
 }

}
