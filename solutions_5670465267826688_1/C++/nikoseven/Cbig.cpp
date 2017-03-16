#include <cstdio>
#include <iostream>
using namespace std;

enum {
	ONE = 1,
	I,
	J,
	K
};
const int _mul[5][5] = 
{
	{0, 0, 0, 0, 0},
	{0, 1, I, J ,K},
	{0, I,-1, K,-J},
	{0, J,-K,-1, I},
	{0, K, J,-I,-1}
};

int inv(int i) {
	if(i == -1 || i == 1)
		return i;
	return -i;
}

int mul(int i,int j) {
	bool isneg = false;
	if( i < 0 ) {
		isneg = !isneg;
		i = -i;
	}
	if( j < 0 ) {
		isneg = !isneg;
		j = -j;
	}
	return isneg ? -_mul[i][j] : _mul[i][j];
}

int qPow(int b,long long p) {
	int r = 1,t = b;
	while(p) {
		if( p & 1 )
			r = mul(r,t);
		
		t = mul(t,t);
		p >>= 1;
	}
	return r;
}

char str[20000];
int getVal(int idx) {
	return str[idx]-'i'+2;
}
int s[20000];


int main() {
	int T,ics = 0;
	cin >> T;
	while(T--) {
		long long L;
		long long X;
		cin >> L >> X >> str;
		long long len = L*X;
		s[0] = getVal(0);
		for(int i=1;i<L;++i) {
			s[i] = mul(s[i-1],getVal(i));
		}
		bool found = false;
		if( qPow(s[L-1],X) == -1 ) {
			long long si = -1;
			int ss = 1;
			for(long long i=0;i<4*L&&i<len;++i) {
				ss = mul(ss,getVal(i%L));
				if( ss == I ) {
					si = i;
					break;
				}
			}
			if( si >= 0 ) {
				for(int i=si+1;i<len && i<=si+4*L;++i) {
					ss = mul(ss,getVal(i%L));
					if( ss == K ) {
						found = true;
						break;
					}
				}
			}
		}
		printf("Case #%d: %s\n",++ics,found?"YES":"NO");
	}
	return 0;
}
