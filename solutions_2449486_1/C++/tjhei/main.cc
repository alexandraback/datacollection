#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main()
{
  std::ifstream in("in");
  int cases;
  std::string casess;
  getline(in,casess);
  sscanf(casess.c_str(),"%d",&cases);
  

  char c;
//  in >> c;

  char orig []="abcdefghijklmnopqrstuvwxyz";
  char trans[]="yhesocvxduiglbkrztnwjpfmaq";

  int ar[100][100];
  
  for (int i=0;i<cases;++i)
    {
      int N,M;

      int maxv[200];
      
      in >> N >> M;
      for (int y=0;y<N;++y)
      for (int x=0;x<M;++x)
	{
	  int v;
	  in >> v;
	  ar[x][y]=v;
	}

      for (int y=0;y<N;++y)
	{
	  int v=0;
	  for (int x=0;x<M;++x)
	    {
	      v=std::max(ar[x][y],v);
	    }
	  maxv[y]=v;
	}
      
      for (int x=0;x<M;++x)
	{
	  int v=0;
	  for (int y=0;y<N;++y)
	    {
	      v=std::max(ar[x][y],v);
	    }
	  maxv[100+x]=v;
	}

      bool no=false;
      
      for (int y=0;y<N;++y)
      for (int x=0;x<M;++x)
	if (ar[x][y]<maxv[y] && ar[x][y]<maxv[100+x])
	  no=true;
      
      
      
      std::cout << "Case #" << i+1 << ": ";
      std::cout << ((no)?"NO":"YES");
      
      // int off=pow(2,N)-1;

      // if (K>0 && K%(off+1)==off)
      // 	std::cout << "ON";
      // else
      // 	std::cout << "OFF";

      std::cout << std::endl;

    }
  return 0;
}
