#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100001];
int s1[100001];
int s2[100001];
inline int get(int ans,char x)
{
     if(ans==1)
     {
          if(x=='i')
               ans=2;
          else if(x=='j')
               ans=3;
          else if(x=='k')
               ans=4;
     }
     else if(ans==2)
     {
          if(x=='i')
               ans=-1;
          else if(x=='j')
               ans=4;
          else if(x=='k')
               ans=-3;
     }
     else if(ans==3)
     {
          if(x=='i')
               ans=-4;
          else if(x=='j')
               ans=-1;
          else if(x=='k')
               ans=2;
     }
     else if(ans==4)
     {
          if(x=='i')
               ans=3;
          else if(x=='j')
               ans=-2;
          else if(x=='k')
               ans=-1;
     }
     else if(ans==-1)
     {
          if(x=='i')
               ans=-2;
          else if(x=='j')
               ans=-3;
          else if(x=='k')
               ans=-4;
     }
     else if(ans==-2)
     {
          if(x=='i')
               ans=1;
          else if(x=='j')
               ans=-4;
          else if(x=='k')
               ans=3;
     }
     else if(ans==-3)
     {
          if(x=='i')
               ans=4;
          else if(x=='j')
               ans=1;
          else if(x=='k')
               ans=-2;
     }
     else if(ans==-4)
     {
          if(x=='i')
               ans=-3;
          else if(x=='j')
               ans=2;
          else if(x=='k')
               ans=1;
     }
     return ans;
}
int main()
{
	 freopen("C-small-attempt1.in","r",stdin);
	 freopen("C-small-attempt1.out","w",stdout);
     int t;
     scanf("%d",&t);
     int k=0;
     while(t>0)
     {
     	  t--;
     	  k++;
          long long n,x;
          scanf("%I64d%I64d",&n,&x);
          long long i;
          if(x>13)
          {
               for(i=13;i<=x;i++)
               {
                    if(i%(long long)4==x%(long long)4)
                    {
                         x=i;
                         break;
                    }
               }
          }
          scanf("%s",s);
          for(i=n;i<=n*x-1;i++)
               s[i]=s[i-n];
          n=n*x;
          int ans=1;
          for(i=0;i<=n-1;i++)
          {
               ans=get(ans,s[i]);
               s1[i]=ans;
          }
          if(s1[n-1]!=-1)
          {
               printf("Case #%d: NO\n",k);
               continue;
          }
          ans=1;
          char xt;
          int ta;
          for(i=n-1;i>=0;i--)
          {
          	   if(s[i]=='i')
          	        ta=2;
          	   else if(s[i]=='j')
          	        ta=3;
          	   else if(s[i]=='k')
          	        ta=4;
          	   if(ans==1)
          	        ans=ta;
          	   else if(ans==2)
          	        ans=get(ta,'i');
          	   else if(ans==3)
          	        ans=get(ta,'j');
          	   else if(ans==4)
          	        ans=get(ta,'k');
          	   else if(ans==-1)
          	        ans=-ta;
          	   else if(ans==-2)
          	        ans=-get(ta,'i');
          	   else if(ans==-3)
          	        ans=-get(ta,'j');
          	   else if(ans==-4)
          	        ans=-get(ta,'k');
               s2[i]=ans;
          }
          for(i=0;i<=n;i++)
               if(s1[i]==2)
                    break;
          if(s1[i]!=2)
          {
               printf("Case #%d: NO\n",k);
               continue;
          }
          long long j;
          for(j=i+1;j<=n;j++)
               if(s2[j]==4)
                    break;
          if(s2[j]!=4)
          {
               printf("Case #%d: NO\n",k);
               continue;
          }
          printf("Case #%d: YES\n",k);
     }
     return 0;
}
