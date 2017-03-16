#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;


ifstream fin ("C:\\CodeJam\\Round1C\\A\\A-large.in");
ofstream fout ("C:\\CodeJam\\Round1C\\A\\A-large.out");

int testCase = 0;
char WORD[1000001];
bool kk[1000001];


bool vowel(char x)
{
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		return true;
	return false;
}

void Solve()
{
	int n,L,i,j;
	memset(WORD, 0, sizeof(WORD));
	
	fin>>WORD;
	fin>>n;
	L = strlen(WORD);
	/*
	kk[0] = true;
	for (j = 0;j < n; j++)
	{
		if (!vowel(WORD[j])) {
			kk[0] = false;
			break;
		}
	}*/
	for (i = 0; i < L;i++)
		kk[i] = false;
	int strike = 0;
	for (i = 0;i <L; i++)
	{
		if (!vowel(WORD[i])) {
			strike ++;
		} else {
			strike = 0;
		}
		if (strike >= n)
			kk[i-n+1] = true;
	}

	LL res = 0;
	LL count = 0;
	for (i = 0;i <= L-n; i++)
	{
		count++;
		if (kk[i]) {
			res += count * (L-n-i+1);
			count = 0;
		}
	}
	



	fout << "Case #" << testCase << ": "<<res<<endl;

}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();

	}

	cout<<"finished"<<endl;
	getchar();

}



