#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0 ;i < cnt; ++i)
    {
      cout << "Case #" << i+1 << ": ";
      int X,R,C;
      cin >> X >> R >> C;
      if(R>C){swap(R,C);}
      if(X>6 || (R*C)%X)
	{cout << "RICHARD" << endl; continue;}
      if(X==1 || X==2){cout << "GABRIEL" << endl; continue;}
      if(X==3 || X==4)
	{
	  if(R==1){cout << "RICHARD" << endl; continue;}
	  if(R>=3){cout << "GABRIEL" << endl; continue;}
	  if(R==2)
	    {
	      if(X==3){cout << "GABRIEL" << endl;continue;}
	      if(X==4)
		{
		  cout << "RICHARD" << endl;
		  continue;
		}
	    }
	}
      if(X==5 || X==6)
	{
	  if(R<=2){cout << "RICHARD" << endl; continue;}
	  if(R>=4){cout << "GABRIEL" << endl; continue;}
	  if(R==3)
	    {
	      if(X==5)
		{
		  if(C==5){cout << "RICHARD" << endl; continue;}
		  else {cout << "GABRIEL" << endl; continue;}
		}
	      if(X==6)
		{
		  cout << "RICHARD" << endl; continue;
		}
	    }
	}
      cerr << "ERROR" << endl;
    }
}
