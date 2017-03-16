#include<string>
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<cctype>
#include<climits>
#define pp pair<int,int>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    string s1,s2,s3;
    long long int T,A,B,j,i,c;
    char ch[100];
    scanf("%lld",&T);
    for(j=1;j<=T;j++)
    {
      
      scanf("%lld%lld",&A,&B);
      c=0;
      sprintf(ch,"%lld",B);
      s2=ch;
      while(A<B)
      {
        set<string> s;
        set<string>::iterator it;
        sprintf(ch, "%lld", A);
        s1=ch;
        for(i=0;i<s1.length()-1;i++)
        {
        s3=s1.substr(s1.length()-1-i,i+1)+s1.substr(0,s1.length()-i-1); 
        it=s.find(s3);
        if(s3.compare(s2)<=0 && s3.compare(s1)>0 &&it==s.end())
        {c++;s.insert(s3);}
        }
      A++;
      }
      printf("Case #%lld: %lld\n",j,c);
    }
    return 0;
}
      
