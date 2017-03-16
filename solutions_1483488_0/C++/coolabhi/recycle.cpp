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
    int T,A,B,j,i,c;
    char ch[100];
    scanf("%d",&T);
    for(j=1;j<=T;j++)
    {
      scanf("%d%d",&A,&B);
      c=0;
      sprintf(ch,"%d",B);
      s2=ch;
      while(A<B)
      {
        sprintf(ch, "%d", A);
        s1=ch;
        for(i=0;i<s1.length()-1;i++)
        {
        s3=s1.substr(s1.length()-1-i,i+1)+s1.substr(0,s1.length()-i-1);
        if(s3.compare(s2)<=0 && s3.compare(s1)>0)
        c++;
        }
      A++;
      }
      printf("Case #%d: %d\n",j,c);
    }
    return 0;
}
      
