#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
string s,s2;
vector<pair<int,int> > v;

bool isc(char c)
{
     //printf("isc:%c\n",c);
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
       return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    long long tc,ans;
    scanf("%lld",&tc);
    for (int i=0; i<tc; i++)
    {
        v.clear();
        //Read in stuff
        cin >> s;
        long long n;
        scanf("%lld",&n);
        //printf("%lld\n",n);
        long long p1=0,p2=0,cnt=0;
        //Slide window
        ans=0;
        while (p1<s.size())
        {
              //Move until portion with n consec cons reached
              while (p1<s.size())
              {
                  if (isc(s[p1]))
                  {
                     cnt+=1;
                     if (cnt>=n) //Can do
                     {
                        break; //Continue to next portion
                     }
                  }
                  else
                  {
                      cnt=0;
                  }
                  p1++;
              }
              //printf("p1:%lld\n",p1);
              if (p1!=s.size())
              {
                  while (p2<=p1-n+1)
                  {
                        //printf("Ans Increase\n");
                        ans+=(s.length()-p1);
                        p2++;
                  }
                  cnt--;
              }
              //printf("p2:%lld\n",p2);
              p1++;
        }
        printf("Case #%d: %lld\n",i+1,ans);
    }
}
