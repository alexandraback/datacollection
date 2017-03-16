#include<iostream>
#include<fstream>
using namespace std;
long long n1,n2;
int digits(long long n)
{int ans=0;
while(n)
{ans++;
n/=10;
}
return ans;
}
long long pow(long long x,int n)
{long long ans=x;
for(int i=1;i<n;++i)
ans*=x;
return ans;
}
int rec(long long n)
{int dig=digits(n);
long long arr[10];
arr[dig-1]=n;
long long x1=n,x2=n;
for(int i=0;i<dig-1;++i)
{
x2=(x1/10)+((x1%10)*pow(10,dig-1));
x1=x2;
arr[i]=x2;
}
int ans=0;
for(int q=0;q<dig-1;++q)
{
if(digits(arr[q])<dig)continue;
if(arr[q]<n1||arr[q]>n2)continue;
ans++;
for(int j=q+1;j<dig;++j)
{if(arr[q]==arr[j]){ans--;break;}
}
}
return ans;
}
int main()
{
long long n;
ifstream fin("s.in");
ofstream fout("s.out");
int t;
fin>>t;
for(int x=0;x<t;++x)
{
fin>>n1>>n2;
long long ans=0;
for(long long q=n1;q<=n2;++q)
ans+=rec(q);
ans/=2;
fout<<"Case #"<<x+1<<": "<<ans<<endl;
}
return 0;
}
