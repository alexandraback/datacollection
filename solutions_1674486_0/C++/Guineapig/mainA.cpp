#include "..\..\my_header.h"

typedef vector<int_v> int_vv;

void append(int_v &v, int_v &tail)
{
  int n = tail.size();
  for (int i=0 ; i < n ; i++)
    v.push_back(tail[i]);
}

bool has_duplicates(int_v &v)
{
  sort(v.begin(), v.end());
  int n = v.size();
  for (int i=1 ; i < n ; i++)
    if (v[i] == v[i-1])
      return true;
  return false;
}

int_v unique(int_v &v)
{
  if (v.empty())
    return int_v();

  int n = v.size();
  
  int_v res;
  res.push_back(v[0]);
  for (int i=1 ; i < n ; i++)
    if (v[i] != res.back())
      res.push_back(v[i]);
 
  return res;
}

class solver
{
  int_vv cache;
  
public:

  int_v &ancestors(int c, int nc, int_vv &parents)
  {
    if (!parents[c].empty() && cache[c].empty())
    {
      int_v res = parents[c];
      
      int np = parents[c].size();
      for (int i=0 ; i < np ; i++)
      {
        int p = parents[c][i];
        int_v par_ancs = ancestors(p, nc, parents);
        append(res, par_ancs);
      }
      
      sort(res.begin(), res.end());
      res = unique(res);
      
      cache[c] = res;
    }
    
    return cache[c];
  }
  
	bool solve(int nc, int_vv &parents)
	{
	  cache.resize(nc);
	  
	  for (int c=0 ; c < nc ; c++)
	  {
	    int np = parents[c].size();
	    
	    int_v all_ancs = parents[c];
	    for (int ip=0 ; ip < np ; ip++)
	    {
	      int_v &ancs = ancestors(parents[c][ip], nc, parents);
	      append(all_ancs, ancs);
	    }
	    
	    if (has_duplicates(all_ancs))
	      return true;
	  }

		return false;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int nc;
  ifs >> nc;
  
  int_vv parents(nc);
  for (int i=0 ; i < nc ; i++)
  {
    int np;
    ifs >> np;
    for (int j=0 ; j < np ; j++)
    {
      int p;
      ifs >> p;
      parents[i].push_back(p-1);
    }
  }
  
	bool res = solver().solve(nc, parents);

	cout << "Case #" << case_num << ": " << (res ? "Yes" : "No") << endl;
	ofs << "Case #" << case_num << ": " << (res ? "Yes" : "No") << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
  //ifstream ifs("E:\\Projects\\GCJ2012\\Round1C\\Debug\\A-tiny.in", ifstream::in);
  //ofstream ofs("E:\\Projects\\GCJ2012\\Round1C\\Debug\\A-tiny.out");

	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

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
