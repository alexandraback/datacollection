#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
main()
{
      ifstream in;
      ofstream out;
      in.open("input.txt");
      out.open("output.txt");
      int t,n,flag=0,val,ans;
      in>>t;
      char name[101];
      for(int i=1;i<=t;i++)
      {
              in>>name>>n;
              ans=0;
              for(int j=0;j<strlen(name);j++)
              {
                      flag=0;val=0;
                      for(int k=j;k<strlen(name);k++)
                      {
                      if(name[k]!='a' && name[k]!='e' && name[k]!='i' && name[k]!='o' && name[k]!='u')
                      val+=1;
                      else 
                      val=0;
                      if(val>=n)
                      flag=1;
                      if(flag==1)
                      ans++;
                      }
              }
              
              out<<"Case #"<<i<<": "<<ans<<"\n";
      }
}
