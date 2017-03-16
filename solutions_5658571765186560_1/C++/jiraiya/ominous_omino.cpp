#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(int argc,char* argv[])
{
  istream *in;
  ifstream infile;
  if(argc > 1)
  {
    infile.open(argv[1]);
    in = &infile;
  }
  else
  {
    in = &cin;
  }
  string line;
  int noOfCase = -1;
  int case_counter = 1;
  getline(*in, line);
  noOfCase = atoi(line.c_str());


  for(int i=0;i<noOfCase;i++)
  {
    int x,r,c;
    getline(*in,line, ' ');
    x = atoi(line.c_str());
    getline(*in,line, ' ');
    r = atoi(line.c_str());
    getline(*in,line);
    c = atoi(line.c_str());

    int grid_size = r*c;
    grid_size -= x;

    bool flag = true;
    if(x>=7)
    { 
      flag = false;
    }
    else if(x>r and x>c)
    { 
      flag = false;
    }
    else if(r*c%x!=0)
    { 
      flag = false;
    }
    else if (((x+1)/2) > min(r,c))
    { 
      flag = false;
    }
    else if(x == 1 || x==2 || x==3)
    { 
      flag = true;
    }
    else if(x == 4)
    { 
      flag = min(r,c)>2;
    }
    else if(x == 5)
    { 
      flag = not(min(r,c)==3 and max(r,c) == 5);
    }
    else if(x==6)
    {
      flag = min(r,c)>3;
    }

    if(flag == true)
    {
      cout<<"Case #"<<i+1<<": "<<"GABRIEL"<<endl;   
    }
    else
    {
      cout<<"Case #"<<i+1<<": "<<"RICHARD"<<endl;
    }
  }
  return 0;
}
