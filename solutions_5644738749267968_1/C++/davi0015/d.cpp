#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B, I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main()
{
	int T;
	cin >> T;
	
	forn (i, T)
	{
		int N;
		cin >> N;
		
		vector <double> Naomi(N), Ken(N);
		forn (j, N)
			cin >> Naomi[j];
		forn (j, N)
			cin >> Ken[j];
			
		sort (Naomi.begin(), Naomi.end());
		sort (Ken.begin(), Ken.end());
		
		int war = N;
		int deceit = 0;
		int left = 0;
		int right = N-1;
		forn (j, N)
		{
			if (Naomi[j] > Ken[left])
			{
				deceit++;
				left++;
			}
			else
			{
				if (Naomi[j] < Ken[right])
				{
					right--;
				}
				else
				{
					deceit++;
					left++;
				}
			}
		}
		
		vector <bool> taken(N);
		int lost = 0;
		forn (j, N)
		{
			forn (k, N)
			{
				if (Naomi[j]<Ken[k] && !taken[k])
				{
					taken[k] = true;
					war--;
					break;
				}
			}
		}
		
		cout << "Case #" << i+1 << ": " << deceit << " " << war << endl;
	}
	
	return 0;
}