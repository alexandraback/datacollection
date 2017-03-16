#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main()
{
    string s, line ;
    char c ;
    int nCases ;

    cin >> nCases ;


    getline(cin, s) ;

    for (int iCase = 0 ; iCase < nCases ; iCase++)
    {
		cerr << "Case #" << iCase + 1 << "..." << endl ;
		double D, x, t, a ;
		int N, A ;
		cin >> D ; cin >> N ; cin >> A ;
		vector<double> xs(N), ts(N) ;
		for (int i = 0 ; i < N ; i++)
		{
			cin >> t ;
			cin >> x ;
			xs[i] = x ;
			ts[i] = t ;
		}

		double v = (xs[N-1] - xs[N-2]) / (ts[N-1] - ts[N-2]) ;
		double dt = (D - xs[N-2]) / v ;
		xs[N-1] = D ; ts[N-1] = ts[N-2] + dt ;

        // writing output file
        cout << "Case #" << iCase + 1 << ":" << endl ;

		for (int i = 0 ; i < A ; i++)
		{
			cin >> a ;
			double tmax = 0 ;
			for (int j = 0 ; j < N ; j++)
			{
				double td = ts[j] - sqrt(2 * xs[j] / a) ;
				tmax = max(td, tmax) ;
			}
			t = tmax + sqrt(2 * D / a) ;
			printf("%.12lf\n", t) ;
		}

    }


    return 0;
}
