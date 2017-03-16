#include <iostream>
#include <vector>
#include <set>
using namespace std;

__attribute__ ((const, hot)) long long calc(int N){
	set<int> digitsSeen;
	long long f = N;
	while(true){
		long long g = f;
		while (g != 0){
			digitsSeen.insert(g%10);
			g /= 10;
			}
		if (10 == digitsSeen.size()	) return f;
		f += N;
		}
	}
void print(int times, char mander){
	for (int j = 0; j < times; j += 1){
		cout << mander;
		}
	}
void foo(string S){
	int z=0,w=0,u=0,x=0,g=0,f=0,h=0,s=0,i=0,o=0;
	for (uint jj = 0; jj < S.size(); jj += 1){
		char mander = S[jj];
		if ('Z' == mander) z++;
		if ('W' == mander) w++;
		if ('U' == mander) u++;
		if ('X' == mander) x++;
		if ('G' == mander) g++;
		if ('F' == mander) f++;
		if ('H' == mander) h++;
		if ('S' == mander) s++;
		if ('I' == mander) i++;
		if ('O' == mander) o++;
	}
	int _0,_1,_2,_3,_4,_5,_6,_7,_8,_9;
	_0 = z;
	_2 = w;
	_4 = u;
	_6 = x;
	_8 = g;

	_5 = f - _4;
	_3 = h - _8;
	_7 = s - _6;

	_9 = i - _5 - _6 - _8;
	_1 = o - _0 - _2 - _4;
	//cout << "(debug) " <<  z << " " << w << " " << u << " " << x << " " << g << " " << f << " " << h << " " << s << " " << i << " " << o << " " << endl;
	//cout << _0 << " " << _1 << " " << _2 << " " << _3 << " " << _4 << " " << _5 << " " << _6 << " " << _7 << " " << _8 << " " << _9 << endl;
	print(_0,'0');
	print(_1,'1');
	print(_2,'2');
	print(_3,'3');
	print(_4,'4');
	print(_5,'5');
	print(_6,'6');
	print(_7,'7');
	print(_8,'8');
	print(_9,'9');
	}
int main(void){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i += 1){
		string S;
		cin >> S;
		cout << "Case #" << i << ": ";
		foo(S);
		cout << "\n";
	}
	return 0;
}
