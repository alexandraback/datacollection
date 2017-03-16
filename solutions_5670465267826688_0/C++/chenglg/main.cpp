#ifdef __GNUC__
#include <ext/hash_map>
#include <ext/hash_set>
#else
#include <hash_map>
#include <hash_set>
#endif

namespace std
{
 using namespace __gnu_cxx;
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <climits>
#include <iomanip> 
using namespace std;

typedef long long LL;
typedef long double LD;
template<class T>

T prime(T a , T b)
{
	cout << a << "\t"<<b << endl;
	if ( a >= b)
		return (prime(b , a));
	if(a == 0)
		return b;
	return prime(a , b%a);
}

string its(int n)
{
	string ret;
	if(n == 0)
	{
		ret = "0";
		return ret;
	}
	while(n > 0)
	{
		ret += (n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin() , ret.end());
	return ret;
}
struct comp {

	int sign;
	char c;
	comp (int sign, char c) : sign(sign),c(c) {}
	static comp mult(comp c1 , comp c2) {
		int s = c1.sign * c2.sign;
		int s1 = 1;
		char t;
		if (c1.c == '1') {
			t = c2.c;	
		}
		else if (c2.c == '1') {
			t = c1.c;
		}
		else if (c1.c == 'i') {
			if (c2.c == 'i') {
				s1 = -1;
				t = '1';
			}
			else if (c2.c == 'j') {
				s1 = 1;
				t = 'k';
			}
			else {
				s1 = -1;
				t = 'j';
			}
		}
		else if (c1.c == 'j') {
			if (c2.c == 'i') {
				s1 = -1;
				t = 'k';
			}
			else if (c2.c == 'j') {
				s1 = -1;
				t = '1';
			}
			else {
				s1 = 1;
				t = 'i';
			}
		}
		else if (c1.c == 'k') {
			if (c2.c == 'i') {
				s1 = 1;
				t = 'j';
			}
			else if (c2.c == 'j') {
				s1 = -1;
				t = 'i';
			}
			else {
				s1 = -1;
				t = '1';
			}
		}
		return comp(s*s1, t);
	}

	static comp power(comp c1 , long long n) {
		if (n == 0)
			return comp(1,'1');
		if (n == 1) {
			return c1;
		}
		long long k = n / 2;
		comp t = power(c1, k);
		if (k * 2 == n)
			return mult(t, t);
		return mult(mult(t,t), c1);
	}
};


int main()
{
//==============in put=================
	ifstream curFile("C-small-attempt1.in");
	vector<string> result;
	int T; // testcases count
	int L;
	long long X;
	string src;
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			cout << "Enter Test case:" << c + 1 << endl;
			curFile >> L;
			curFile >> X;
			curFile >> src;
			vector<comp> dict;
			vector<comp> rdict;
			comp a(1,'1');
			comp b(1, '1');
			for (int i = 0 ; i < L ; i ++) {
				comp t1(1,src[i]);
				a = comp::mult(a , t1);
				dict.push_back(a);
				comp t2(1,src[L - i - 1]);
				b = comp::mult(t2, b);
				rdict.push_back(b);
			}
			comp r = comp::power(dict.back(), X);
			if (r.sign != -1 || r.c != '1') {
				result.push_back("NO");
				continue;
			}
			int pre = 999999;
			int post = 999999;
			comp p1 = comp::power(dict.back(), 1);
			comp p2 = comp::power(dict.back(), 2);
			comp p3 = comp:: power(dict.back() , 3);
			for (int i = 0 ; i < L ; i ++) {
				comp x = dict[i];
				comp y = rdict[i];
				if (x.sign == 1 && x.c == 'i')
					pre = min(pre, i + 1);
				if (y.sign == 1 && y.c =='k')
					post = min(post, i + 1);
				comp x1 = comp::mult(p1, x);
				comp y1 = comp::mult(y, p1);
				if (x1.sign == 1 && x1.c == 'i')
					pre = min(pre, i + L + 1);
				if (y1.sign == 1 && y1.c =='k')
					post = min(post, i + L + 1);
				comp x2 = comp::mult(p2, x);
				comp y2 = comp::mult(y, p2);
				if (x2.sign == 1 && x2.c == 'i')
					pre = min(pre, i + 2*L + 1);
				if (y2.sign == 1 && y2.c =='k')
					post = min(post, i +2* L + 1);
				comp x3 = comp::mult(p3, x);
				comp y3 = comp::mult(y, p3);
				if (x3.sign == 1 && x3.c == 'i')
					pre = min(pre, i +3* L + 1);
				if (y3.sign == 1 && y3.c =='k')
					post = min(post, i + 3*L + 1);
			}
			cout << pre << endl;
			cout << post << endl;
			if (pre == 999999 || post == 999999)
				result.push_back("NO");
			else {
				long long prel = pre;
				long long postl = post;
				long long l = L;
				if (prel + postl < X * l)
					result.push_back("YES");
				else
					result.push_back("NO");
			}
//==============solution end==============
		}	
	}
	curFile.close();
//==============out put==================
	ofstream outfile;
	outfile.open("result.txt");
	if(outfile.is_open())
	{
//		outFile << setprecision(6);
		for(int i = 0; i < result.size() ; i++) {
			outfile << "Case #" << i + 1<< ": " <<result[i] << endl;
			cout << "Case #" << i + 1<< ": " <<result[i] << endl;
		}
	}
	outfile.close();
	return 0;
}
