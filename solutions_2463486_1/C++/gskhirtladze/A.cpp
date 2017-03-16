#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

long long c[500];
long long i;
vector <long long> v;
long long t,tT,j,A,B,now;

bool ispalin(long long A)
 {
  int k=0;
  while (A>0)
   {
    k++;
    c[k]=A%10;
    A/=10;
   }
  for (int o=1;o<=k;o++)
   if (c[o] != c[k-o+1]) return false;
  return true;
 }

main()
 {
  freopen("text.in","r",stdin);
  freopen("text.out","w",stdout);
  for (i=1;i<=2001002;i++)
   if (ispalin(i) && ispalin(i*i)) v.push_back(i*i);
  cin>>tT;
  for (t=1;t<=tT;t++)
   {
    cin>>A>>B;
    now=0;
    for (j=0;j<v.size();j++)
     if (v[j] >= A && v[j] <= B) now++;
    cout<<"Case #"<<t<<": "<<now<<endl;
   }
 }
