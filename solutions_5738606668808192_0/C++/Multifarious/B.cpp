
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <stack>
#include <cmath>
#include <string.h>
#include <queue>
#include <set>
#include <bitset>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;


string get_rep(int x)
{
    string ret = "";
    for(int i = 0; i < 16; i++)
    {
        if(x % 2) ret = '1' + ret;
        else ret = '0' + ret;


    }
    return ret;
}




long long is_prime(long long x)
{
    for(long long i = 2; (i*i) <= x; i++)
    {
        if ( (x%i) == 0) return i;
    }
    return 0;
}


inline long long conv(bitset<16> a, long long base)
{
    long long mult = 1;
    long long ret = 0;
    for(int idx = 0; idx < 16; idx++)
    {
        ret += a[idx] * mult;
        mult *= base;
    }
    return ret;
}

int main()
{

	for(int start = 32769; start < 52780; start += 2)
	{
        //cout << 'S ' << start << endl;
        bitset<16> foo(start);
        bool good = true;
        for(long long i = 2; i <= 10; i++)
        {
            long long next = conv(foo,i);
            if(is_prime(next) == 0)
            {
                good = false;
                break;
            }
        }
        if(good)
        {
            cout << foo;
            for(long long base = 2; base <= 10; base++)
            {
                long long next = conv(foo,base);
                cout << ' ' << is_prime(next);
            }
            cout << endl;
        }
	}
	return 0;
}