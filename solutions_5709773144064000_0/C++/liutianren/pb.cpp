#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

double cookieTime(double C, double F, double X)
{
	double timeNeed = 1000000;
	//unsigned int factOwned = 0;
	double timeSpent = 0;
	for(unsigned int factOwned=0;;factOwned++)
	{
		double tn = timeSpent + X/(factOwned*F+2);
		if(tn < timeNeed)
			timeNeed = tn;
		else
			return timeNeed;

		timeSpent += C/(factOwned*F+2);
	}
}

int main()
{
	int caseNum;
	cin >> caseNum;
	double C,F,X;

	for(int t=1; t <= caseNum; t++)
	{
		cin >> C >> F >> X;
		cout << "Case #"<<t<<": "<<std::setprecision(9)<<cookieTime(C,F,X)<<endl;
	}
}

