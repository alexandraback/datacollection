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

	/*
	vector <int> ch(N,0);
	// fair 
	int fairresultN = 0;
	for (k=0;k<N;k++)
	{
		int take = -1;
		fairresultN++;
		for (l=0;l<N;l++)
		{
			if (ch[l] == 0 && take == -1)
				take = l;
			
			if (ch[l]==0 && ke[l]>na[k])
			{
				take = l;				
				fairresultN--;
				break;
			}
		}
		ch[take]=1;
	}
	// unfair
	int Ns=0;
	int Ks=N-1;
	
	while( (Ns<N) && (na[Ns]<ke[Ks]))
	{
		Ns++;
		Ks--;
	}
	int unfairresult=Ks+1;
			

	// output result
    fprintf(aus, "Case #%d: %d %d\n", TestCase, unfairresult, fairresultN);
	*/
	fprintf(aus, "Case #%d: %d %d\n", TestCase, scoreCheat(na,ke), N-scoreCheat(ke,na));
}

void main()
{
	int NumTestCases;	
	ein.open("D-small-attempt0.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
