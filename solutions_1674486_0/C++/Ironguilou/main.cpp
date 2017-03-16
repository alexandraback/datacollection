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
		int N ;
		cin >> N ;
		vector< set<int> > succ(N+1), prev(N+1) ;


		for (int i = 1 ; i < N+1 ; i++)
		{
			int M, s ;
			cin >> M ;
			for (int j = 0 ; j < M ; j++)
			{
				cin >> s ;
				succ[i].insert(s) ;
				prev[s].insert(i) ;

			}
		}

		vector < vector<bool> > at(N+1, vector<bool>(N+1, false)) ;

		for (int i = 1 ; i < N+1 ; i++)
			at[i][i] = true ;

		for (int iter = 0 ; iter < N+2 ; iter++)
		{
			for (int j = 1 ; j < N+1 ; j++)
			{
				for (set<int>::iterator it = succ[j].begin() ; it != succ[j].end() ; it++)
				{
					for (int k = 1 ; k < N+1 ; k++)
					{
						at[*it][k] = at[*it][k] | at[j][k] ;
					}
				}
			}
		}

		bool at2 = false ;
		for (int i = 1 ; i < N+1 ; i++)
		{
			vector<int> nb(N+1, 0) ;
			for (set<int>::iterator it = prev[i].begin() ; it != prev[i].end() ; it++)
			{
				for (int k = 1 ; k < N+1 ; k++)
				{
					if (at[*it][k])
						nb[k]++ ;
				}
			}

			for (int j = 1 ; j < N+1 ; j++)
			{
				if (nb[j] > 1)
				{
					at2 = true ;
					break ;
				}
			}
			if (at2)
				break ;
		}


        // writing output file
        cout << "Case #" << iCase + 1 << ": " ;
		if (at2)
			cout << "Yes" << endl ;
		else
			cout << "No" << endl ;

    }


    return 0;
}
