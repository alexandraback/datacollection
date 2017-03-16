#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>


      struct str
      {
	  int l1,l2;
	  bool d1,d2;
/*	  str():
			  l1(0),l2(0),d1(false),d2(false)
	    {}
*/	  
      };


bool myfunction (const str &i,const str &j) { return i.l2<j.l2 || j.l1<j.l1; }

int main()
{
  std::ifstream in("in");
  int cases;
  in >> cases;

  for (int i=0;i<cases;++i)
    {
      int N;
      in >> N;
      
      std::vector<str> ll;
      for (int j=0;j<N;++j)
	{
	  str s;
	  in >> s.l1 >> s.l2;
	  s.d1=s.d2=false;
	  
	  ll.push_back(s);
	  }

      std::sort(ll.begin(), ll.end(), myfunction);

      int curstars=0;
      int steps=0;
      


      std::cout << "Case #" << i+1 << ": ";
//      for (int j=0;j<N;++j)
//	std::cout << ll[j].l1 << " " << ll[j].l2 << std::endl;

      
      while (true)
	{
	  for (int j=0;j<ll.size();++j)
	    {
	      if (ll[j].d1 && !ll[j].d2 && curstars>=ll[j].l2)
		{
		  steps++;
		  ll[j].d2=true;
		  curstars++;
		  ll.erase(ll.begin()+j);		  
		  goto on;
		}
	      if (curstars<ll[j].l2)
		break;
	      
	    }
	  
	  for (int j=0;j<ll.size();++j)
	    {
	      
	      if (curstars>=ll[j].l1 && !ll[j].d1 && curstars>=ll[j].l2 && !ll[j].d2)
		{
		  ll[j].d1=true;
		  curstars+=2;
		  steps++;
		  
		  ll[j].d2=true;
		  ll.erase(ll.begin()+j);		  
		  goto on;
		}
	    }
	  for (int j=0;j<ll.size();++j)
	    {
	      int jj=ll.size()-1-j;

	      if (curstars>=ll[jj].l1 && !ll[jj].d1)
		{
		  ll[jj].d1=true;
		  curstars++;
		  steps++;
		  goto on;
		}
	      
	    }
	  
	  

	  if (ll.size()==0)
	    std::cout << steps;
	  else	    
	    std::cout << "Too Bad";
	  
	  break;
	  
	  
	  

on:
	  int ggg=0;
	  
	}
      
      

      /*      std::vector<bool> on;
      on.resize(N);
      for (int k=0;k<K;++k)
	{
	  for (int j=0;j<N;++j)
	    {
	    on[j]=!on[j];
	    if (on[j])
	      break;
	    }
	  //	  for (int j=0;j<=N;++j)
	  //	    std::cout << on[j];
	  //	  std::cout << std::endl;
	}
      
      bool ison=true;
      for (int j=0;j<N;++j)
	if (!on[j])
	  {ison=false;break;}
      */



      std::cout << std::endl;

    }
  return 0;
}
