//大整数运算模板（不考虑负数）
//注意长整形是用long long还是__int64

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 200;

class HugeInt
{
	friend ostream &operator<<( ostream&, const HugeInt& );
	friend istream &operator>>( istream&, HugeInt& );
public:
	HugeInt( char* );
	HugeInt( long long = 0 );

	//支持大数和小数的运算，可以连续运算
	HugeInt operator+( HugeInt& );
	HugeInt operator+( long long );
	HugeInt operator-( HugeInt& );
	HugeInt operator-( long long );
	HugeInt operator*( HugeInt& );
	HugeInt operator*( long long );
	HugeInt operator/( HugeInt& );
	HugeInt operator/( long long );

	int num[maxn], len;
};

ostream &operator<<( ostream& output, const HugeInt& a)
{
	for( int i = a.len - 1; i >= 0; --i )
		output << a.num[i];

	if( a.len == 0 )
		output << '0';

	return output;
}

istream &operator>>( istream& input, HugeInt& a)
{
	int i, len;
	char s[maxn+5];
	input >> s;
	len = strlen(s) - 1;

	memset(a.num, 0, sizeof(a.num));

	i = 0;
	while( i <= len && s[i] == '0' ) ++i;

/*      //更改进制时候的输入
	long long k, tt;
	for( a.len = 0; len >= 0 && len >= i; )
	{
		k = s[len--] - '0';
		for( j = 1, tt = 10; len >= 0 && len >= i && j < 进制位数(1000是3）; ++j, tt *= 10 )
			k += (s[len--] - '0') * tt;

		a.num[a.len++] = k;
	}
*/

	for( a.len = 0; len >= 0 && len >= i; ++a.len, --len )
		a.num[a.len] = s[len] - '0';

	return input;
}

HugeInt::HugeInt( char* s )
{
	int i, j = strlen(s) - 1;
	num[0] = 0;

	memset(num, 0, sizeof(num));

	i = 0;	
	while( i <= j && s[i] == '0' ) ++i;

	for( len = 0; j >= 0 && j >= i; ++len, --j )
		num[len] = s[j] - '0';
}

HugeInt::HugeInt( long long n )
{
	len = 0;
	memset(num, 0, sizeof(num));

	while( n )
	{
		num[len++] = n % 10;
		n /= 10;
	}
}

int hugecmp( HugeInt& a, HugeInt& b )
{
	if( a.len < b.len )
		return -1;
	else if( a.len == b.len )
	{
		for( int i = a.len - 1; i >= 0; --i )
		{
			if( a.num[i] < b.num[i] )
				return -1;
			else if( a.num[i] > b.num[i] )
				return 1;
		}

		return 0;
	}
	else
		return 1;
}

HugeInt HugeInt::operator +( HugeInt& a ) 
{
	HugeInt res = a;

	res.len = len > a.len ? len : a.len;

	for( int i = 0; i < res.len; ++i )
	{
		res.num[i] += num[i];
		if( res.num[i] >= 10 )
		{
			res.num[i+1]++;
			res.num[i] %= 10;
		}
	}

	if( res.num[res.len] > 0 )
		res.len++;

	return res;
}

HugeInt HugeInt::operator +( long long n )
{
	HugeInt temp = n;
	return *this + temp;
}

HugeInt HugeInt::operator -( HugeInt& a) 
{
	HugeInt res = *this;

	for( int i = 0; i < a.len; ++i )
	{
		if( res.num[i] < a.num[i] )
		{
			res.num[i+1]--;
			res.num[i] += 10 - a.num[i];
		}
		else
			res.num[i] -= a.num[i];
	}

	for( int i = 0; i < res.len; ++i )	
		if( res.num[i] < 0 )
		{
			res.num[i+1]--;
			res.num[i] += 10 - a.num[i];
		}

	while( res.len > 0 && res.num[res.len - 1] == 0 )
		res.len--;

	return res;
}

HugeInt HugeInt::operator -( long long n )
{
	HugeInt temp = n;
	return *this - temp;
}

HugeInt HugeInt::operator *( HugeInt& a )
{
	int i, j;
	HugeInt res;

	for( i = 0; i < len; ++i )
		for( j = 0; j < a.len; ++j )
			res.num[i+j] += num[i]*a.num[j];

	for( i = 0; i <= len + a.len; ++i )
	{
		res.num[i+1] += res.num[i]/10;
		res.num[i] %= 10;
	}

	for( res.len = len + a.len + 1; res.len > 0 && res.num[res.len - 1] == 0; --res.len );

	return res;
}

HugeInt HugeInt::operator *( long long n )
{
	HugeInt temp = n;
	return *this * temp;
}

HugeInt HugeInt::operator /( HugeInt& b )
{
	int t, i, n;
	HugeInt res, temp, a = *this; //若要求余数，可将a改成全局变量
	res.len = len;

	for( t = len - b.len; t >= 0; --t )
	{
		for( i = 1; i <= b.len; ++i )
			temp.num[t + b.len - i] = b.num[b.len - i];
		temp.len = b.len + t;

		for( n = 0; hugecmp(a, temp) >= 0; ++n, a = a - temp );
		res.num[t] = n;
	}

	for( ; res.len > 0 && !res.num[res.len - 1]; --res.len );

	return res;
}

HugeInt HugeInt::operator /( long long n )
{
	HugeInt a = n;
	return *this / a;
}

unsigned long long r, s;

int chk( unsigned long long n )
{
	HugeInt S(s);
	HugeInt a(n);
	HugeInt b(n);
	a = a*n;	a = a*2;
	b = b*(2*r-1);
	a = a+b;
	return hugecmp(a, S);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T, cases = 1;
	unsigned long long rr, ll, mid;

	cin >> T;
	while( T-- )
	{
		cin >> r >> s;
		ll = 1, rr = s;

		while( rr-ll > 1 )
		{
			mid = (ll+rr)/2;
			if( chk(mid) <= 0 )
				ll = mid;
			else
				rr = mid;
		}

		cout << "Case #" << cases++ << ": " << ll << endl;
	}

	return 0;
}