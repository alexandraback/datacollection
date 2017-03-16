#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

string N="N"; 
string E="E";
string W="W";
string S="S";

  int X=0,Y=0;
  int x=0,y=0;

  int pogo=1;
  
  string direction("");
  


int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    cout << "Error : Input the file" << endl;
    exit(1);
  }
  
  ifstream in_file(argv[1]);
  ofstream out_file(argv[2]);
  
  if(!in_file.is_open() || !out_file.is_open())
  {
    cout << "Error : Cannot open input and output file" << endl;
    exit(1);
  }
  
  uint T;
    
  in_file >> T;
  

  for(int i=0; i<T; i++)
  {
    direction = "";
    pogo = 1;
    in_file >> X >> Y;
    
    x=X;
    y=Y;
    
  //cout << X << " " << Y << endl;   

while(x!=0 || y!=0)    
{
    if(x!=0 && y!=0)
    {
      if(abs(x) >= abs(y))
      {
	if(x>=0)
	{
	  if(abs(x)>=pogo)
	  {
	    x = x - pogo;
	    pogo++;
	    direction = direction + E;
	  }
	  else
	  {
	    x = x + pogo;
	    pogo++;
	    direction = direction + W;
	  }
	}
	else
	{
	 if(abs(x)>=pogo)
	  {
	    x = x + pogo;
	    pogo++;
	    direction = direction + W;
	  }
	  else
	  {
	    x = x - pogo;
	    pogo++;
	    direction = direction + E;
	  }
	}
      }
      else
      {
        if(y>=0)
	{
	  if(abs(y)>=pogo)
	  {
	    y = y - pogo;
	    pogo++;
	    direction = direction + N;
	  }
	  else
	  {
	    y = y + pogo;
	    pogo++;
	    direction = direction + S;
	  }
	}
	else
	{
	 if(abs(y)>=pogo)
	  {
	    y = y + pogo;
	    pogo++;
	    direction = direction + S;
	  }
	  else
	  {
	    y = y - pogo;
	    pogo++;
	    direction = direction + N;
	  }
	}

      }
    }
    else if(x != 0)
    {
     if(abs(x) >= abs(y))
      {
	if(x>=0)
	{
	  if(abs(x)>=pogo)
	  {
	    x = x - pogo;
	    pogo++;
	    direction = direction + E;
	  }
	  else
	  {
	    x = x + pogo;
	    pogo++;
	    direction = direction + W;
	  }
	}
	else
	{
	 if(abs(x)>=pogo)
	  {
	    x = x + pogo;
	    pogo++;
	    direction = direction + W;
	  }
	  else
	  {
	    x = x - pogo;
	    pogo++;
	    direction = direction + E;
	  }
	}
      }
    }
    else if(y != 0)
    {
      if(y>=0)
	{
	  if(abs(y)>=pogo)
	  {
	    y = y - pogo;
	    pogo++;
	    direction = direction + N;
	  }
	  else
	  {
	    y = y + pogo;
	    pogo++;
	    direction = direction + S;
	  }
	}
	else
	{
	 if(abs(y)>=pogo)
	  {
	    y = y + pogo;
	    pogo++;
	    direction = direction + S;
	  }
	  else
	  {
	    y = y - pogo;
	    pogo++;
	    direction = direction + N;
	  }
	}

      }    
     //cout << x << " " << y << endl;
   
  }
 
 out_file << "Case #" << i+1 << ": " << direction << endl;
 
  }
  return 0;
}