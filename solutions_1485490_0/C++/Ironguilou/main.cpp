#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;
typedef vector<long long> vl ;

long long min(long long a, long long b)
{
	return a < b ? a : b ;
}

long long max(long long a, long long b)
{
	return a > b ? a : b ;
}

long long nbMatches(vl &Bn, vl &Bt, vl &Tn, vl &Tt, int iB, int iT, long long rB, long long rT)
{
	
	if (rB == 0)
		iB++ ;
	if (rT == 0)
		iT++ ;

	if (iB >= Bt.size() || iT >= Tt.size())
		return 0 ;

	if (rB == 0)
		rB = Bn[iB] ;
	if (rT == 0)
		rT = Tn[iT] ;

	// same type
	if (Bt[iB] == Tt[iT])
	{
		long long n = min(rB, rT) ;
		rB -= n ;
		rT -= n ;

		return n + nbMatches(Bn, Bt, Tn, Tt, iB, iT, rB, rT) ;
	}

	// different type
	long long n1 = nbMatches(Bn, Bt, Tn, Tt, iB, iT, 0, rT) ;
	long long n2 = nbMatches(Bn, Bt, Tn, Tt, iB, iT, rB, 0) ;
	return max(n1, n2) ;
}

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
		int NB, NT ;
		cin >> NB ;
		cin >> NT ;
		long long n, t ;
		vector<long long> Bn(NB), Bt(NB), Tn(NT), Tt(NT) ;
		for (int i = 0 ; i < NB ; i++)
		{
			cin >> n ; cin >> t ;
			Bn[i] = n ; Bt[i] = t ;
		}

		for (int i = 0 ; i < NT ; i++)
		{
			cin >> n ; cin >> t ;
			Tn[i] = n ; Tt[i] = t ;
		}



        // writing output file
        cout << "Case #" << iCase + 1 << ": " ;

		cout << nbMatches(Bn, Bt, Tn, Tt, -1, -1, 0, 0) ; 

        cout << endl ;
    }


    return 0;
}
