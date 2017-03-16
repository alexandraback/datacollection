//============================================================================
// Name        : Fair.cpp
// Author      : alpc92
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <math.h>
using namespace std;

#define eps 1e-8
#define inf 0x3fffffff
#define zero(x) (fabs(x)<=eps)
#define FORIT(iter,STL) for (typeof(STL.begin()) iter(STL.begin());iter!=STL.end();++iter)
#define PB push_back
#define MP make_pair
#define REP(iterator,upperbound) for(int iterator(0);iterator<(upperbound);++iterator)
#define FOR(iterator,lowerbound,upperbound) for(int iterator(lowerbound);iterator<=(upperbound);++iterator)
#define FORD(iterator,upperbound,lowerbound) for(int iterator(upperbound);iterator>=(lowerbound);--iterator)
#define SZ(STL) ((int)STL.size())
#define CL(STL) (STL.clear())
#define CL0(array) memset(array,0,(int)sizeof(array))
#define CL1(array) memset(array,-1,(int)sizeof(array))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
template<typename T>
void chkmax(T a, T &b) {
	if (a > b)
		b = a;
}
template<typename T>
void chkmin(T a, T &b) {
	if (a < b)
		b = a;
}
template<typename T>
T sqr(T a) {
	return a * a;
}
template<typename T>
T gcd(T a, T b) {
	while (b != 0) {
		T c = a;
		a = b;
		b = c % b;
	}
	return a;

}
bool check(LL k) {
	VI v;
	while (k) {
		v.push_back(k % 10);
		k /= 10;
	}
	REP(i,SZ(v))
		if (v[i] != v[SZ(v) - 1 - i])
			return 0;
	return 1;
}
LL val[70][2] =
		{ { 1, 1 }, { 2, 4 }, { 3, 9 }, { 11, 121 }, { 22, 484 },
				{ 101, 10201 }, { 111, 12321 }, { 121, 14641 }, { 202, 40804 },
				{ 212, 44944 }, { 1001, 1002001 }, { 1111, 1234321 }, { 2002,
						4008004 }, { 10001, 100020001 }, { 10101, 102030201 }, {
						10201, 104060401 }, { 11011, 121242121 }, { 11111,
						123454321 }, { 11211, 125686521 }, { 20002, 400080004 },
				{ 20102, 404090404 }, { 100001, 10000200001 }, { 101101,
						10221412201 }, { 110011, 12102420121 }, { 111111,
						12345654321 }, { 200002, 40000800004 }, { 1000001,
						1000002000001 }, { 1001001, 1002003002001 }, { 1002001,
						1004006004001 }, { 1010101, 1020304030201 }, { 1011101,
						1022325232201 }, { 1012101, 1024348434201 }, { 1100011,
						1210024200121 }, { 1101011, 1212225222121 }, { 1102011,
						1214428244121 }, { 1110111, 1232346432321 }, { 1111111,
						1234567654321 }, { 2000002, 4000008000004 }, { 2001002,
						4004009004004 }, { 10000001, 100000020000001 }, {
						10011001, 100220141022001 },
				{ 10100101, 102012040210201 }, { 10111101, 102234363432201 }, {
						11000011, 121000242000121 },
				{ 11011011, 121242363242121 }, { 11100111, 123212464212321 }, {
						11111111, 123456787654321 },
				{ 20000002, 400000080000004 }, { 100000001, 10000000200000001 },
				{ 100010001, 10002000300020001 },
				{ 100020001, 10004000600040001 },
				{ 100101001, 10020210401202001 },
				{ 100111001, 10022212521222001 },
				{ 100121001, 10024214841242001 },
				{ 101000101, 10201020402010201 },
				{ 101010101, 10203040504030201 },
				{ 101020101, 10205060806050201 },
				{ 101101101, 10221432623412201 },
				{ 101111101, 10223454745432201 },
				{ 110000011, 12100002420000121 },
				{ 110010011, 12102202520220121 },
				{ 110020011, 12104402820440121 },
				{ 110101011, 12122232623222121 },
				{ 110111011, 12124434743442121 },
				{ 111000111, 12321024642012321 },
				{ 111010111, 12323244744232321 },
				{ 111101111, 12343456865434321 },
				{ 111111111, 12345678987654321 },
				{ 200000002, 40000000800000004 },
				{ 200010002, 40004000900040004 } };
int main() {
	int t;
	freopen("/Users/yunfengzhou/Downloads/C-large-1.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> t;
	FOR(ca,1,t)
	{
		printf("Case #%d: ", ca);
		LL a, b;
		cin >> a >> b;
		int num(0);
		REP(i,70)
			if (val[i][1] >= a&&val[i][1]<=b)
				++num;

		cout<<num<<endl;
	}

	//for (LL i(1);i<=1000000000;++i)if (check(i)&&check(sqr(i)))cout<<i<<" "<<sqr(i)<<endl;

	return 0;
}
