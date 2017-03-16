#include <bits/stdc++.h>
using namespace std;
int dp[110];
char we[110];
int main()
{
    freopen("Bs.in", "r", stdin);
    freopen("Bs.txt","w",stdout);
  int t;
  cin>>t;
  int p=1;
  while(t--){
    int as=0;
    scanf("%s",(we));
    int n=strlen(we);
    for(int i=n-1;i>=0;i--)
    {
      if(we[i]=='+'){
      continue;
      }
      else 
      {
        we[i]='+';
        as++;
        int j;
        for( j=i-1;j>=1;j--)
        {
        if(we[j]=='-'){
          we[j]='+';
          continue;
        }
        else 
        break;
          }
        i=j;
        for(int k=i;k>=0;k--)
        we[k]=='+'?we[k]='-':we[k]='+';
        i++;
      }
    }
    cout<<"Case #"<<p<<": "<<as<<"\n";
    p++;
  }
}
