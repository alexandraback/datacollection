#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

bool mas[26] = { 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 };

int main()
{
    freopen( "A-small-attempt0.in", "r", stdin );
    freopen( "A-small-attempt0.out", "w", stdout );
    
    int t, n;
    
    string s;

	

	cin >> t;

	for ( int i = 0; i < t; i++ )
	{
		 cin >> s >> n;

		 bool *ch;

		 int m = s.size();

		 ch = new bool[m];

		 for (int j = 0; j < m; j++)
		 {
			 ch[j] = mas[(int)(s[j] - 'a')];
		 }

		 int k = 0;

		 int loccount = 0;

		 int posa = 0, posb = 0;

		 unsigned long long ans = 0;

		 while ( k < m - 1 )
		 {
			 for (int j = k; j < m; j++)
			{
				if ( ch[j] == 1 ) loccount++;
				else loccount = 0;
				if ( loccount == n ) { posa = j - n + 1; posb = j; break; }
			}

			

			if ( loccount != n ) break;

			ans += ( posa - k + 1 ) * ( m - posb  );

			k = posa + 1;

			loccount = 0;

		 }

		 cout << "Case #" << i + 1 << ": " << ans << endl;

		 ans = 0;

		 loccount = 0;

		 k = 0;

		 posa = 0;

		 posb = 0;

		 delete[] ch;

	}
    
    
    //system("pause");
    return 0;
}