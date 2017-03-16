#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1000000;

void mul(bool &minus, char &value, char t)
{
	switch (value) {
	case '1':
		value = t;
		break;
	case 'i':
		switch (t) {		
		case 'i':
			minus = !minus;
			value = '1';
			break;
		case 'j':
			value = 'k';
			break;
		case 'k':
			minus = !minus;
			value = 'j';
			break;
		}
		break;
	case 'j':
		switch (t) {		
		case 'i':
			minus = !minus;
			value = 'k';
			break;
		case 'j':
			minus = !minus;
			value = '1';
			break;
		case 'k':			
			value = 'i';
			break;
		}
		break;
	case 'k':
		switch (t) {		
		case 'i':
			value = 'j';
			break;
		case 'j':
			minus = !minus;
			value = 'i';
			break;
		case 'k':	
			minus = !minus;
			value = '1';
			break;
		}
		break;
	}		
}

bool work()
{	
	int L;
	long long X;
	string st;
	cin >> L >> X >> st;
	
	bool minus = false;
	char value = '1';
	for (int i = 0; i < st.size(); ++i)
		mul(minus, value, st[i]);
	
	bool _minus = false;
	char _value = '1';
	for (int i = 0; i < X % 4; ++i) {
		mul(_minus, _value, value);
		if (minus)
			_minus = !_minus;
	}
	if (!_minus || _value != '1')
		return false;
			
	int n;
	if (L * X > maxn)
		n = maxn;
	else
		n = int(L * X);
	minus = false;
	value = '1';
	int flag = 0;
	for (int i = 0; i < n; ++i) {
		mul(minus, value, st[i % L]);
		if (flag == 0 && !minus && value == 'i') {
			flag = 1;
			minus = false;
			value = '1';
		}
		if (flag == 1 && !minus && value == 'j')
			return true;
	}
	return false;	
}

int main()
{
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);        ;
        printf("%s\n", work() ? "YES" : "NO");
    }
    
    return 0;
}

