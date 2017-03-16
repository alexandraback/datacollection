#include<iostream>
#include<string.h>
#include<iomanip>
#include<math.h>
using namespace std;
typedef long long int ll;
int main()
{ freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
ll l,t;
cin>>t;
for(l=1;l<=t;l++)
{
char s[1005],f[1005]={};
cin>>s;
cout<<"Case #"<<l<<": ";
int len=strlen(s),i,j=502,k=502;
f[j]=s[0];
for(i=1;i<len;i++)
{if(s[i]>=f[j])
 {j--;
 f[j]=s[i];
 }
 else
 {k++;
 f[k]=s[i];
 }
}
while(j<=k)
{cout<<f[j];
j++;
}
cout<<endl;
}
return 0;
}
