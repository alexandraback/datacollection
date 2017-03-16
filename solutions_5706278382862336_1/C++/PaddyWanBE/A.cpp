#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
typedef unsigned int uint;
typedef unsigned long ulong;

uint aantal;
uint casei;
void flushLine();
void opl();

string l[155];
string cl[155];

int main()
{
    cin >> aantal;
    flushLine();
    for(casei = 1; casei <= aantal; casei++)
	opl();
    return 0;
}

void flushLine()
{
    string str;
    getline(cin, str);
}
ulong gcd(ulong a, ulong b)
{
    ulong c;
    while(a!=0)
    {
	c=a;
	a=b%a;
	b=c;
    }
    return b;
}

void opl()
{
    ulong P, Q;
    char hulp;
    cin >> P >> hulp >> Q;
    {
	const ulong gcdg = gcd(P,Q);
	P/=gcdg;
	Q/=gcdg;
    }
    if((Q&(Q-1)) == 0)
    {
	cout << "Case #" << casei << ": " << static_cast<ulong>(log2(Q)) - static_cast<ulong>(log2(P)) << endl;
    }
    else
    cout << "Case #" << casei << ": impossible" << endl;
}

