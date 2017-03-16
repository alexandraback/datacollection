#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

void start()
{
	printf("%d\n", TestCase);
  int result;
	// read test case
  int N;
  ein >> N;
  int M[10];
  int D[10];
  int nH = 0;
  for (int n=0;n<N;n++)
  {
	  int Di, Mi, Hi;
	  ein >> Di >> Hi >> Mi;
	  for (int hi=0;hi<Hi;hi++)
	  {
		  D[nH] = Di;
		  M[nH] = Mi + hi;
		  nH++;
	  }
  }

  if (nH == 1)
  {  result = 0; }
  else
  {
	  // nH = 2
	  if (M[0] == M[1])
	  {
		  result = 0;
	  }
	  else
	  {
		  if (M[0] < M[1])
		  {	
			  M[2] = M[0];
			  D[2] = D[0];
			  M[0] = M[1];
			  D[0] = D[1];
			  M[1] = M[2];
			  D[1] = D[2];
		  }
		  double e0 = double(M[0])*(1-double(D[0])/360.0);
		  double f1 = double(M[1])*(2-double(D[1])/360.0);
		  if (e0 < f1) 
		  {
			  result = 0;
		  }
		  else
		  {
			  result = 1;
		  }
	  }
  }
	// output result
    fprintf(aus, "Case #%d: %d\n", TestCase, result);     // %llu , %ll
}

void main()
{
	int NumTestCases;	
	ein.open("C-small-1-attempt0.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
