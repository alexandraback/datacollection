/*
ID: enggi231
LANG: C++
PROG: 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

int a, b, power;

 int isr(int n) {
	int m = n;

	m = m/10 + (m%10)*power;
	int cnt = 0;
        while (m != n) {
		//cout << m << " ";
		if ((m <= b) && (n<m)) {
		    cnt++;
                }
		m = m/10 + (m%10)*power;
	}
	//cout <<n << " 0" << endl;
	return cnt;
}

int main()
{
	fstream in("in.txt", ios_base::in);
	int t, x;
	in >> t;
	//t = 1;
	
	for (int v = 1; v <= t; v++){
		in >> a >> b;
		//a = 10; b=99;
		x = a;
		power = 1;
		while (x) {
			x /= 10;
			power *= 10;
		}
		power /= 10;
		int cnt = 0;
		for (int i = a; i < b; i++)
		    cnt += isr(i) ;
		
		cout << "Case #" << v << ": " << cnt << endl;
	}
	/*
	a = 100;
	b = 500;
	//for (int i = 0; i < 100000000; i++)
		isr(414);
	*/

	return 0;
}

