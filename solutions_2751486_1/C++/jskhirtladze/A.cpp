#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);

const int H=(1<<20);
int T[2*H],t,l,n,i,j,c[H];
string s;
long long answer,tmp;


bool fv(char c)
{
 if ( c=='a' || c=='e' || c=='i' || c=='o' || c=='u' )
  return true;
 else return false;;
}

void upd(int i)
{
 T[H-1+i]=i;
 i=H-1+i;
 while ( i>1 )
  {
   i/=2;
   if ( T[i*2]==0 ) T[i]=T[i*2+1];
               else T[i]=T[i*2];
  }
}

int ans(int l,int r)
{
 l+=H-1;
 r+=H-1;

 int ret = 2000000;

 while ( l<r )
  {
   if ( l%2==1 )
    {
     if ( T[l]!=0 ) ret=min(ret,T[l]);
     l++;
    } l/=2;
   if ( r%2==0 )
    {
     if ( T[r]!=0 ) ret=min(ret,T[r]);
     r--;
    } r/=2;
  }
 if ( l==r )
  if ( T[l]!=0 ) ret=min(ret,T[l]);

 if ( ret==2000000 ) ret=0;
 return ret;
}

main()
{
 cin>>t;
 for ( l=1;l<=t;l++ )
  {
   cin>>s;
   s="#"+s;
   cin>>n;

   for ( i=1;i<s.size();i++ )
    if ( fv(s[i]) ) c[i]=0;
               else c[i]=c[i-1]+1;

   for ( j=0;j<2*H;j++ )
    {
     T[j]=0;
    }

   for ( i=1;i<s.size();i++ )
    if ( c[i]>=n ) upd(i);

   answer=0;

   for ( i=1;i<s.size();i++ )
    {
     j=i+n-1;
   //  cout<<i<<" --> "<<j<<endl;
     if ( j>=s.size() ) break;
  //   cout<<"dafuq"<<endl;
     j=ans(j,s.size()-1);
   //  cout<<"find "<<j<<endl;
     if ( !j ) break;
     tmp=s.size()-j;
 //    cout<<"find "<<j<<" --> "<<tmp<<endl;
     answer+=tmp;
    }

   cout<<"Case #"<<l<<": "<<answer<<endl;
 //  system("pause");
  }
}
