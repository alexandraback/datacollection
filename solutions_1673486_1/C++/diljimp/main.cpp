#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <stdlib.h>

using namespace std;

#define repp(I, Start, End)		for(I = Start; I < End; ++I)
#define rep(I, End)				for( ; I < End; ++I)
#define irep(I, End)			for( ; I != End; ++I)
#define idef(Typ, No, Var)		Typ::const_iterator ite##No = Var.begin();	Typ::const_iterator iteEnd##No = Var.end();
#define it(Typ, No, Var)		idef(Typ, No, Var)	irep(ite##No, iteEnd##No)



int main()
{
	ifstream ifs("A-large.in");
	ofstream ofs("output.txt");
	string sLine = "";
	bool bFirstLineRead = false;
	int iTestCaseCount = 0;
	int iTestCaseNo = 0;
	while(getline(ifs, sLine))
	{
		istringstream ss(sLine);
		if(!bFirstLineRead)
		{
			ss >> iTestCaseCount;
			bFirstLineRead = true;
			continue;
		}
		++iTestCaseNo;
		if(iTestCaseNo > iTestCaseCount)
			break;
        
		int A,B;
        ss>>A;
        ss>>B;
        double prob = 1.0;
        getline(ifs, sLine);
        istringstream ss2(sLine);
        double bestexpt = -1.0;
        int i;
        repp(i, 0, A)
        {
            double pp;
            ss2>>pp;
            prob *= pp;
            double expt = ((A+B-2*i-1)*prob + (A+2*B-2*i)*(1.0-prob));
            if(bestexpt < 0.0)
                bestexpt = expt;
            else
            {
                if(bestexpt > expt)
                    bestexpt = expt;
            }
        }
        if(bestexpt > (B+2))
            bestexpt = B+2;
        if(bestexpt > (A+B+1))
            bestexpt = A+B+1;
        char op[100];
        sprintf(op, "%.6f", bestexpt);
        ofs<<"Case #"<<iTestCaseNo<<": "<<op<<endl;
	}
}