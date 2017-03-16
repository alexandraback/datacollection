#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


char v(char x)
{
  if (x=='X')
    return 1;
  if (x=='T')
    return 3;
  if (x=='O')
    return 2;
  return 0;
}


int main()
{
  std::ifstream in("in");
  int cases;
  std::string casess;
  getline(in,casess);
  sscanf(casess.c_str(),"%d",&cases);

  char f[16];
  
	 

  char c;
//  in >> c;

  char orig []="abcdefghijklmnopqrstuvwxyz";
  char trans[]="yhesocvxduiglbkrztnwjpfmaq";
  
  
      std::string l;
  for (int i=0;i<cases;++i)
    {
      for (int j=0;j<4;++j)
	{
	  
      getline(in,l);

      f[j*4+0]=v(l[0]);
      f[j*4+1]=v(l[1]);
      f[j*4+2]=v(l[2]);
      f[j*4+3]=v(l[3]);
      
	}
      getline(in,l);

      char won=0;
      bool full=true;

      for (int j=0;j<16;++j)
	if (f[j]==0)
	  full=false;

      for (int k=1;k<=2;++k)
	{
	  for (int y=0;y<4;++y)
	    if ((f[y*4]&k) && (f[y*4+1]&k) && (f[y*4+2]&k) && (f[y*4+3]&k))
	      won=k;
	  
	  for (int x=0;x<4;++x)
	    if ((f[0*4+x]&k) && (f[1*4+x]&k) && (f[2*4+x]&k) && (f[3*4+x]&k))
	      won=k;

	  
	  if ((f[1*4+1]&k) && (f[2*4+2]&k) && (f[3*4+3]&k) && (f[0*4+0]&k))
	      won=k;
	  if ((f[0*4+3]&k) && (f[1*4+2]&k) && (f[2*4+1]&k) && (f[3*4+0]&k))
	      won=k;
	  

	}

      std::cout << "Case #" << i+1 << ": ";
      if (won==1)
	std::cout << "X won";
      else if (won==2)
	std::cout << "O won";
      else if (full)
	std::cout << "Draw";
      else
	std::cout << "Game has not completed";

      std::cout << std::endl;

    }
  return 0;
}
