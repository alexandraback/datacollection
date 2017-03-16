#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL unsigned long long
#define EPS 0.00000000000001
#define MOD 1000000009
#define INF 1000000000000000000LL
#define K 101
#define N 200

char S[N], J[N];
char SR[N], JR[N];

int mmin;
bool bmin;
int mins, minj;

int main()
{
#ifdef _DINARISIO
	ifstream cin("B-small-attempt2.in");
	ofstream cout("A.out");
#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << t + 1 << ": ";
		cin >> S >> J;
		int slen = strlen(S);
		bmin = false;

		for (int s = 0; s < 1000; ++s)
		{
			bool bOK = true;
			for (int p = s, i = 1; i <= slen || p > 0; p /= 10, ++i)
			{
				if (i > slen){
					bOK = false;
					break;
				}
				if (S[slen - i] == '?')continue;
				if ((S[slen - i] - '0') != (p % 10))bOK = false;
			}
			
			if (!bOK)continue;

			for (int j = 0; j < 1000; ++j)
			{
				bOK = true;
				for (int p = j, i = 1; i <= slen || p > 0; p /= 10, ++i)
				{
					if (i > slen){
						bOK = false;
						break;
					}
					if (J[slen - i] == '?')continue;
					if ((J[slen - i] - '0') != (p % 10))bOK = false;
				}
				if (!bOK)continue;

				if (!bmin || abs(s - j) <= mmin)
				{
					if (bmin && abs(s - j) == mmin)
					{
						if (s > mins) continue;
						if (s == mins)
						{
							if (j >= minj)continue;
						}
					}
					mins = s;
					minj = j;
					mmin = abs(s - j);
					bmin = true;

					for (int i = 0; i < slen; ++i)SR[i] = '0';
					for (int i = 0; i < slen; ++i)JR[i] = '0';

					for (int p = s, i = 1; p > 0; p /= 10, ++i){
						SR[slen - i] = (p % 10) + '0';
					}
					for (int p = j, i = 1; p > 0; p /= 10, ++i){
						JR[slen - i] = (p % 10) + '0';
					}
					SR[slen] = 0;
					JR[slen] = 0;
				}
			}
		}
		cout << SR << " " << JR << endl;
	}
	re 0;
}