#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>

#define ss(x) scanf("%d",&x)
//scanf(in,"%d",&x)
using namespace std;

int main()
{ 
   freopen ("in.in", "r",stdin);
   freopen("out.out","w",stdout);
   string s;
   vector <unsigned int> b;
   unsigned int t,k,l;
 unsigned long long L,n,x,i;
  unsigned long long cur ,ans;
  //cout<<s.max_size();
  cin>>t;
  k=0;                          
  while(k<t){k++; s.clear(); b.clear();
  cin>>s;
  cin>>n;
  L=s.length(); b.push_back(-1);
     for(l=-1,x=0,i=0;i<L;i++)
     { if(s[i] == 'a' ||s[i] =='e'||s[i] =='i'||s[i] =='o'|| s[i] =='u')
       {l=i;}
       else
       {  if(i-l==n){b.push_back(l+1); x++; l++;
                    }
       }
     }
     ans=0;
     for(i=1;i<=x;i++)
     {                  //L,x,(l),n
      //printf("%d %d %d %d %d\n",i, b[i] , L , n,ans);
        cur=(b[i]-b[i-1])*(L-n-b[i]+1);
        ans+=cur;
     }
     printf("Case #%d: %lld\n",k,ans);

  }
  
  //system("pause");
}
