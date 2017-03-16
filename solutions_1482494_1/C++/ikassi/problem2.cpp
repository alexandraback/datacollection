#include <iostream>
#define INF  2002
using namespace std;



int handle(int l)
{
  
  int not_done = l;
  int levels[l][2];
  int completed[l];
  for(int j = 0; j<l; j++)
  {
    cin >> levels[j][0];
    cin >> levels[j][1];
    completed[j] = 0;
  }
  int count = 0;
  bool smtd = true;
  int stars = 0;
  while(smtd)
  {
    // check every 2-star opportuinity until no opportunity
    while(smtd)
    {
      smtd = false;
      for(int i = 0; i<l; i++)
      {
	if(completed[i]<2 && stars>=levels[i][1])
	{
	    
	    not_done--;
	    stars = stars + 2 - completed[i];
	    completed[i]=2;
	    smtd = true;
	    count ++;
	 }
      }
    }
    int maxB = 0;
    int I = -1;
    for(int i = 0; i<l; i++)
    {
      //CHECK NOT COMPLETED
      if(completed[i]<1 && stars>=levels[i][0])
      {
	
	if(levels[i][1]>=maxB)
	{
	  maxB = levels[i][1];
	  I = i;
	}
      }
    }
    smtd = (I>-1);
    if(smtd)
    {
      stars = stars + 1; 
      completed[I] = 1;
      count ++;
    }
  }
  if(not_done) return -1; else return count;
  
}

int main()
{
  int cases,l;
  cin >> cases;
  for(int i = 0; i< cases; i++)
  {
    cin >> l;
    
    cout << "Case #" << i+1 << ": " ;
    int h = handle(l);
    if(h==-1) cout << "Too Bad";
    else cout << h;
    cout << endl;
  }
  return 0;
}