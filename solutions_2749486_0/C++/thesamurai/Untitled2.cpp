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
      int t,x,y;
      in>>t;
      for(int i=1;i<=t;i++)
      {
              in>>x>>y;
              out<<"Case #"<<i<<": ";
              if(x>0)
              {
                     for(int j=0;j<x;j++)
                     out<<"WE";
              }
              else
              {
                     for(int j=0;j<-x;j++)
                     out<<"EW";
              }
              if(y>0)
              {
                     for(int j=0;j<y;j++)
                     out<<"SN";
              }
              else
              {
                     for(int j=0;j<-y;j++)
                     out<<"NS";
              }
              out<<"\n";
      }
}
