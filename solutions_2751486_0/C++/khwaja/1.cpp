#include<iostream>
#include<fstream.h>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    int i,j,cnt=0,l,k,m,n;
    ifstream f1;
    ofstream f2;
    int t,r,b,c;
    char a[110];
    f1.open("1a.txt");
    f2.open("1coutput.txt");
    f1>>t;
    m=1;
    while(m<=t)
    {
     f1>>a;
     f1>>n;
     l=0;
     k=strlen(a);
     for(i=0;i<k;++i)
     {
      cnt=0;
       for(j=i;j<k;++j)
       {
         if(a[j]!='a'&&a[j]!='e'&&a[j]!='i'&&a[j]!='o'&&a[j]!='u')
         cnt++;
         else
         cnt=0;
         if(cnt==n)
         {
          l+=(k-j);
          break;
          }
          }
          }
          cout<<endl;
           f2<<"Case #"<<m<<": "<<l<<endl;
         m++;
         }
          f1.close();
    f2.close();
    return 0;
}
