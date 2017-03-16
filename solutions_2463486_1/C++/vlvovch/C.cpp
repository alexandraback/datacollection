#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;

vector<long long> fsqr;

vector<int> digi;

bool pali(long long num)
{
	vector<int> digits(0);
	while (num>0)
	{
		digits.push_back(num%10);
		num /= 10;
	}
	rep(i, digits.size()/2) if (digits[i]!=digits[digits.size()-1-i]) return 0;
	return 1;
}

void gopali(int len, int st)
{
	if (st==0) digi.resize(len/2 + len%2);
	if (st>=digi.size())
	{
		long long num = 0;
		rep(i, digi.size()) num = num*10 + digi[i];
		if (len & 1)
			rep(i, digi.size()-1) num = num*10 + digi[digi.size()-2-i];
		else rep(i, digi.size()) num = num*10 + digi[digi.size()-1-i];
		if (pali(num*num)) fsqr.push_back(num);
		return;
	}
	else
	{
		int cst = 0;
		if (st==0) cst = 1;
		for(int dig=cst;dig<10;++dig)
		{
			digi[st] = dig;
			gopali(len, st + 1);
		}
	}
}

int main()
{
    fstream fin("C-large-1.in",ifstream::in);
    fstream fout("C-large-1.out",ofstream::out);
    fin >> T;
	fsqr.resize(0);
	for(int d=1;d<8;++d) gopali(d, 0);
	sort(fsqr.begin(), fsqr.end());
	/*rep(i, fsqr.size())
		cout << fsqr[i] << " ";*/
	for(int tc=1;tc<=T;tc++)
    {
        long long A, B;
		fin >> A >> B;
		long long ret = 0;
		rep(i, fsqr.size()) if (A<=fsqr[i]*fsqr[i] && fsqr[i]*fsqr[i]<=B) ret++;
        fout << "Case #" << tc << ": " << ret << "\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    system("PAUSE");
    return 0;
}
