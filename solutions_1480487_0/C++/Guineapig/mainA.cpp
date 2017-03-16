#include "..\..\my_header.h"


class solver
{
public:

	int solve(int N, int_v &Js, double_v &min_Ys)
	{
	  double X = 0;
	  for (int i=0 ; i < N ; i++)
	    X += Js[i];

    int_v sJs = Js;
    sort(sJs.begin(), sJs.end());	  

    double totJ = sJs[0];
    double min_safe_S = 0;

    for (int k = 1 ; k < N ; k++)
    {
      int Jk = sJs[k];
      
      totJ += Jk;
      
      double Y_used = ((Jk * (k+1)) - totJ) / X;
      
      if (Y_used > 1)
        break;
      
      double min_safe_Y = (1.0 - Y_used) / (k + 1);
      
      min_safe_S = Jk + min_safe_Y * X;
    }
    
    // Now k is the number of 
	  for (int i=0 ; i < N ; i++)
	  {
	    int J = Js[i];
	    double min_Y = (min_safe_S - J) / X;
	    if (min_Y > 0)
        min_Ys[i] = min_Y;
	  }
	  

	  ////sort(Js.begin(), Js.end());
	  //
	  //int i0 = sidxs[0];
	  //int i1 = sidxs[1];
	  //min_Ys[i0] = (1.0 + (Js[i1] - Js[i0]) / X) / 2;
	  //for (int k=1 ; k < N ; k++)
	  //{
	  //  int ik = sidxs[k];
	  //  min_Ys[ik] = (1.0 + (Js[i0] - Js[ik]) / X) / 2;
	  //}
	  
		return 0;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int N;
  ifs >> N;

  int_v Js(N);
  for (int i=0 ; i < N ; i++)
    ifs >> Js[i];
  
  double_v min_Ys(N);
	int res = solver().solve(N, Js, min_Ys);

	cout << "Case #" << case_num << ":";
	for (int i=0 ; i < N ; i++)
	  cout << " " << (100 * min_Ys[i]);
	cout << endl;

	ofs << "Case #" << case_num << ":";
	for (int i=0 ; i < N ; i++)
	  ofs << " " << (100 * min_Ys[i]);
	ofs << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
  //ifstream ifs("E:\\Projects\\GCJ2012\\Round1B\\Debug\\Atiny.txt", ifstream::in);
  //ofstream ofs("E:\\Projects\\GCJ2012\\Round1B\\Debug\\Atiny.out.txt");

	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(10);
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
