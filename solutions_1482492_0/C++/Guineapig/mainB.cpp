#include "..\..\my_header.h"


class solver
{
public:
  double solve_eq(double a, double b, double c)
  {
    double delta = b * b - 4 * a * c;
    double delta_sqrt = sqrt(delta);
    assert(delta_sqrt > 0);
    
    double res1 = (-b + delta_sqrt) / (2 * a);
    double res2 = (-b - delta_sqrt) / (2 * a);
    
    return res1;
  }
  
	double solve(double D, int N, double a, double_v &ts, double_v &xs)
	{
	  double v0 = 0;
	  double t0 = 0;
	  double x0 = 0;
	  
	  double d = xs[0];
	  if (d > 0)
	  {
	    t0 = sqrt(2 * d / a);
	    x0 = d;
	    v0 = a * t0;
	  }
	  
	  for (int i=1 ; i < N ; i++)
	  {
	    if (xs[i] > D)
	    {
	      assert(i == N-1);
	      
	      double d = D - xs[i-1];
        double min_dt = solve_eq(a/2, v0, -d);
        double min_t = t0 + min_dt;
	    
	      double fd = d / (xs[i] - xs[i-1]);
	      
	      double dtc = (ts[i] - ts[i-1]) * fd;
	      double tc = ts[i-1] + dtc;
        double vc = d / dtc;

        if (min_t > tc)
        {
          // No need to slow down
          t0 = min_t;
          v0 = v0 + a * min_dt;
        }
        else
        {
          v0 = max(vc, a * sqrt(2*d/a));
          t0 = tc;
        }
  	    
        x0 = D;
        
        break;
	    }
	    else
	    {
	      double d = xs[i] - xs[i-1];
        double min_dt = solve_eq(a/2, v0, -d);
        double min_t = t0 + min_dt;
  	    
        double tc = ts[i];
        double dtc = tc - ts[i-1];
        double vc = d / dtc;
    	    
        if (min_t > tc)
        {
          // No need to slow down
          t0 = min_t;
          v0 = v0 + a * min_dt;
        }
        else
        {
          v0 = max(vc, a * sqrt(2*d/a));
          t0 = tc;
        }
  	    
        x0 = xs[i];
      }
	  }
	  
	  return t0;
	}

	double_v solve(double D, int N, int A, double_v &ts, double_v &xs, double_v &as)
	{
	  double_v res(A);
	  for (int i=0 ; i < A ; i++)
	    res[i] = solve(D, N, as[i], ts, xs);
		return res;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  double D;
  int N, A;
  ifs >> D >> N >> A;
  
  double_v ts(N), xs(N);
  for (int i=0 ; i < N ; i++)
    ifs >> ts[i] >> xs[i];
  
  double_v as(A);
  for (int i=0 ; i < A ; i++)
    ifs >> as[i];
  
	double_v res = solver().solve(D, N, A, ts, xs, as);

	cout << "Case #" << case_num << ":" << endl;
	for (int i=0 ; i < A ; i++)
	  cout << res[i] << endl;

	ofs << "Case #" << case_num << ":" << endl;
	for (int i=0 ; i < A ; i++)
	  ofs << res[i] << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
  //ifstream ifs("E:\\Projects\\GCJ2012\\Round1C\\Debug\\B-tiny.in", ifstream::in);
  //ofstream ofs("E:\\Projects\\GCJ2012\\Round1C\\Debug\\B-tiny.out");

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
