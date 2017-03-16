#include "..\..\my_header.h"


class solver
{
public:

	void solve(int N, int_v &ns, int_v &s1, int_v &s2)
	{
	  int max_bitmap = 1 << N;
	  int max_sum = 100000 * N;
	  
	  int_v sum_to_mask(max_sum+10, -1);

	  for (int bitmap=1 ; bitmap < max_bitmap ; bitmap++)
	  {
	    int sum = 0;
	    for (int i=0 ; i < N ; i++)
	      if (bitmap & (1 << i))
	        sum += ns[i];
	    
	    if (sum_to_mask[sum] == -1)
	      sum_to_mask[sum] = bitmap;
	    else
	    {
	      int m1 = sum_to_mask[sum];
	      int m2 = bitmap;
	      
	      for (int i=0 ; i < N ; i++)
	        if (m1 & (1 << i))
	          s1.push_back(ns[i]);
	     
	      for (int i=0 ; i < N ; i++)
	        if (m2 & (1 << i))
	          s2.push_back(ns[i]);
	      
	      return;
	    }
	  }
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int N;
  ifs >> N;
  
  int_v ns(N);
  for (int i=0 ; i < N ; i++)
    ifs >> ns[i];
  
  int_v s1, s2;  
	solver().solve(N, ns, s1, s2);
	
	if (s1.size() > 0)
	{
	  ofs << "Case #" << case_num << ":\n";
	  for (unsigned int i=0 ; i < s1.size() ; i++)
	  {
	    if (i > 0)
	      ofs << " ";
	    ofs << s1[i];
	  }
	  ofs << endl;
	  for (unsigned int i=0 ; i < s2.size() ; i++)
	  {
	    if (i > 0)
	      ofs << " ";
	    ofs << s2[i];
	  }
	  ofs << endl;
	}
	else
	{
  	ofs << "Case #" << case_num << ": Impossible" << endl;
	}
}

/*************************************************************************************/

void main(int argc, char **argv)
{
  ifstream ifs("E:\\Projects\\GCJ2012\\Round1B\\Debug\\C-small-attempt0.in", ifstream::in);
  ofstream ofs("E:\\Projects\\GCJ2012\\Round1B\\Debug\\C-small-attempt0.out");

	//ifstream ifs(argv[1], ifstream::in);
	//ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;

	int n = to_int(get_line(ifs));

	assert(n > 0 && n < 200);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
