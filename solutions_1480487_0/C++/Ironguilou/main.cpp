#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

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
		//cerr << "Case #" << iCase + 1 << "..." << endl ;

		int N, n ;
		vector<int> notes ;
		vector<int> notesOriginal ;
		
		cin >> N ;
		int somme = 0 ;
		for (int i = 0 ; i < N ; i++)
		{
			cin >> n ;
			notes.push_back(n) ;
			notesOriginal.push_back(n) ;
			somme += n ;
		}

		sort(notes.begin(), notes.end()) ;
		
        // writing output file
        cout << "Case #" << iCase + 1 << ":" ;
		for (int i = 0 ; i < N ; i++)
		{
			int note = notesOriginal[i] ;

			double Yi = 0 ;
			int nAutres = 0 ;
			int notesAutres = 0 ;
			bool doitEviter = true ;
			for (int j = 0 ; j < N ; j++)
			{
				if (notes[j] == note && doitEviter)
				{
					doitEviter = false ;
					continue ;
				}

				nAutres++ ;
				notesAutres += notes[j] ;
				Yi = max(0., (double) (notesAutres - nAutres * note + somme) / (double) (somme * (nAutres + 1))) ;

				if (j == N)
					break ;
				if (note + somme * Yi <= notes[j + 1])
					break ;
			}
			//cout << 100 * Yi << " " ;
			printf(" %.10f", 100*Yi) ;

		}
		cout << endl ;
    }


    return 0;
}
