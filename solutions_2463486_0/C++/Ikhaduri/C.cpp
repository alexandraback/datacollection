#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
long long i,a[12000000],j,n,m,t,A,B,num,nnum;
vector<long long> X;
bool check(long long num)
{
long long n = num;
long long rev = 0;
long long dig=0;
 while (num > 0)
 {
      dig = num % 10;
      rev = rev * 10 + dig;
      num = num / 10;
 }
if (n==rev) return true;
return false;
}
int main()
{
freopen("C.in","r",stdin);
freopen("C.out","w",stdout);
for(i=1;i<=10005000;i++)
{if (check(i)&&check(i*i)) a[i]=a[i-1]+1,X.push_back(i);
else a[i]=a[i-1];
}
/*for (i=1;i<=20;i++)
    cout<<a[i]<<" "; cout<<endl;*/
cin>>t;
for (i=1;i<=t;i++)
{
cin>>A>>B;
cout<<"Case #"<<i<<": ";
for (j=0;j<X.size();j++)
if (X[j]*X[j]>A-1) {num=j-1; break;}
for (j=0;j<X.size();j++)
if (X[j]*X[j]>B) {nnum=j-1; break;}
if (A==1) cout<<a[X[nnum]]<<endl; else
cout<<a[ X[nnum] ]-a[ X[num] ]<<endl;

}



}
