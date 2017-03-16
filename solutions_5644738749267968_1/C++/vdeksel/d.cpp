#include <vector>
#include <algorithm>
#include <fstream>
#include <deque>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

int scoreCheat(vector <double> na, vector<double> ke)
{
	int res = 0;
	vector<double>::iterator ina,ike;
	ina = na.begin();
	ike = ke.begin();
	for (ina=na.begin(); ina != na.end(); ina++)
	{
		if (*ina>*ike)
		{			
			ike++;
			res++;
		}
	}
	return res;
}


void start()
{
	int result;
	// read test case
	int N;
	ein >> N;
	vector <double> na(N);
	vector <double> ke(N);
	int k,l;	
	for (k=0;k<N;k++)	
		ein >> na[k];		
	for (k=0;k<N;k++)
		ein >> ke[k];
	sort(na.begin(),na.end());	
	sort(ke.begin(),ke.end());
	fprintf(aus, "Case #%d: %d %d\n", TestCase, scoreCheat(na,ke), N-scoreCheat(ke,na));
}

void main()
{
	int NumTestCases;	
	ein.open("D-large.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
