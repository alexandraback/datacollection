#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

#define PB push_back
#define REVERSE(a) reverse(a.begin(),a.end())

#define MAX 100001
typedef int ARR[MAX];


int main()
{
    freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	double * tab =new double[MAX];

	int casenum;
	cin >> casenum;
	for (int i=1; i<=casenum; i++)
	{
		int A,B;
		cin >> A;
		cin >> B;
		
		double sum=1.0;
		for (int j=1; j<=A; j++)
		{
			cin >> tab[j];
			sum=sum*tab[j];
			tab[j]=sum;
		}

		double min=B+2;
		double tmp;

		for (int j=0; (j<A) && (2*j<1+A); j++)
		{
			tmp=(B-A+1+2*j)+(1-tab[A-j])*(B+1);
			if (tmp<min) min=tmp;
		}

		cout << "Case #" << i << ": " << fixed << setprecision(6) << min << endl;
	}

	return 0;
}
