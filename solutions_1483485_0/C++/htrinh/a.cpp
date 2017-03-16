#include <vector>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)		for(int i=(a),_b=(b);i<(_b);++i)
#define FORD(i,a,b)		for(int i=(a),_b=(b);i>(_b);--i)
#define pb			push_back
#define mp			make_pair
#define	all(c)			(c).begin(),(c).end()
#define	tr(c,i)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define	present(c,x)		((c).find(x) != (c).end())
#define	cpresent(c,x)		(find(all(c),x) != (c).end())

typedef long long			ll;
typedef unsigned long long	ull;
typedef unsigned char	 	byte;
typedef vector<int>			vi;
typedef pair<int, int>		pii;
typedef pair<ll, ll>		pll;
typedef vector<pii>			vpii;

const int N = 25;

char convert(char c)
{
    switch (c) {
        case 'a': return 'y';
        case 'b': return 'h';
        case 'c': return 'e';
        case 'd': return 's';
        case 'e': return 'o';
        case 'f': return 'c';
        case 'g': return 'v';
        case 'h': return 'x';
        case 'i': return 'd';
        case 'j': return 'u';
        case 'k': return 'i';
        case 'l': return 'g';
        case 'm': return 'l';
        case 'n': return 'b';
        case 'o': return 'k';
        case 'p': return 'r';
        case 'q': return 'z';
        case 'r': return 't';
        case 's': return 'n';
        case 't': return 'w';
        case 'u': return 'j';
        case 'v': return 'p';
        case 'w': return 'f';
        case 'x': return 'm';
        case 'y': return 'a';
        case 'z': return 'q';
        case ' ': return ' ';
    }
    return '\0';
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen(argv[1],"r",stdin);
#endif
#ifndef ONLINE_JUDGE
	ifstream cin(argv[1]);
#endif
#if 1
	ofstream cout(argv[2]);
#endif
	int T;
	cin >> T;
    string line;
    getline(cin,line);
    FOR(t,1,T+1) {
        getline(cin,line);
        int n = line.size();
        cout << "Case #" << t << ": ";
        FOR(i,0,n) cout << convert(line[i]);
        cout << "\n";
    }

	return 0;
}
