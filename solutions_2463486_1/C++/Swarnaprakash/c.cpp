// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

/***********************************************************************************************************************************
								ARBITRARY PRECISION ARITHMETIC
									written by U.Swarnaprakash

************************************************************************************************************************************/

struct bigint
{
	char digit[200];
	int length;
	
	
	bigint();
	bigint(int);
	bigint(long long);
	bigint(char *);
	bigint(string);
	
	void print();
	
	bigint operator+(bigint);
	bigint operator-(bigint);
	bigint operator*(bigint);
	bigint operator/(int);
	bigint operator/(long long);
	int operator%(int);
	long long operator%(long long);
	
	bool operator==(bigint);
	bool operator!=(bigint);
	bool operator<=(bigint);
	bool operator>(bigint);
	bool operator>=(bigint);
	bool operator<(bigint);
	
	friend ostream & operator<<(ostream &,bigint);
	
	operator int();
	operator long long();
	operator string();
};
/************************************************************************************************************************************/




/************************************************************************************************************************************/
bigint::bigint()
{
	length=0;
}

/************************************************************************************************************************************/
bigint::bigint(int n)
{
	int pos=0;
	
	while(n!=0)
	{
		digit[pos++]=n%10;
		n/=10;
	}
	
	length=pos;
}

/************************************************************************************************************************************/
bigint::bigint(long long n)
{
	int pos=0;
	
	while(n!=0)
	{
		digit[pos++]=n%10;
		n/=10;
	}
	
	length=pos;
}

/************************************************************************************************************************************/
bigint::bigint(char *n)
{
	int pos,len;
	
	length=len=strlen(n);
	pos=0;
	
	while(len--)
		digit[pos++]=n[len]-'0';
		
	for(pos=length-1;pos>=0 && digit[pos]==0;--pos);
	
	length=pos+1;
}

/************************************************************************************************************************************/
bigint::bigint(string n)
{
	int pos,len;
	
	length=len=n.size();
	pos=0;
	
	while(len--)
		digit[pos++]=n[len]-'0';
		
	for(pos=length-1;pos>=0 && digit[pos]==0;--pos);
	
	length=pos+1;
}

/************************************************************************************************************************************/
void bigint::print()
{
	int i;
	
	if(length==0)
		putchar('0');
	for(i=length-1;i>=0;--i)
		putchar(digit[i]+'0');
}

/************************************************************************************************************************************/
bigint bigint::operator+(bigint x)
{
	int i,carry,d;
	bigint aaa,bbb,result;

	if(length>x.length)
	{
		aaa=*this;
		bbb=x;
	}
	else
	{
		aaa=x;
		bbb=*this;
	}
	
	carry=0;
	for(i=0;i<bbb.length;++i)
	{
		d=aaa.digit[i]+bbb.digit[i]+carry;
		result.digit[i]=d%10;
		carry=d/10;
	}
	for(;i<aaa.length;++i)
	{
		d=aaa.digit[i]+carry;
		result.digit[i]=d%10;
		carry=d/10;
	}
	
	if(carry!=0)
		result.digit[i++]=carry;
		
	result.length=i;
	return result;
}

/************************************************************************************************************************************/
bigint bigint::operator-(bigint x)
{
	int i,borrow,d;
	bigint result;
	
	borrow=0;
	for(i=0;i<x.length;++i)
	{
		d=digit[i]-x.digit[i]-borrow;
		if(d<0)
		{
			result.digit[i]=d+10;
			borrow=1;
		}
		else
		{
			result.digit[i]=d;
			borrow=0;
		}
	}
	
	for(;i<length;++i)
	{
		d=digit[i]-borrow;
		if(d<0)
		{
			result.digit[i]=d+10;
			borrow=1;
		}
		else
		{
			result.digit[i]=d;
			borrow=0;
		}
	}
	
	for(i=length-1;i>=0 && result.digit[i]==0;--i);
	
	result.length=i+1;
	return result;
}

/************************************************************************************************************************************/
bigint bigint::operator*(bigint x)
{
	int r,i,j,hi,lo,carry,tmp;
	bigint result;
	
	r=length+x.length-1;
	carry=0;
	
	for(i=0;i<r;++i)
	{
		lo=0;hi=i+1;
		
		if(hi>length)
			hi=length;
		if((i-lo)>=x.length)
			lo=i-x.length+1;
		
		tmp=carry;
		for(j=lo;j<hi;++j)
			tmp+=digit[j]*x.digit[i-j];
		
		result.digit[i]=tmp%10;
		carry=tmp/10;
	}
	
	if(carry!=0)
		result.digit[i++]=carry;
	
	result.length=i;
	for(i=result.length-1;i>=0 && result.digit[i]==0;--i);

	result.length=i+1;
	return result;
}

/************************************************************************************************************************************/
bigint bigint::operator/(int x)
{
	bigint result;
	int i;
	int tmp,n;
	
	n=0;
	for(i=length-1;i>=0;--i)
	{
		tmp=n*10+digit[i];
		if(tmp>=x)
			break;
		n=tmp;
	}
	
	result.length=i+1;
	for(;i>=0;--i)
	{
		n*=10;
		n+=digit[i];
		result.digit[i]=n/x;
		n%=x;
	}
	return result;
}

/************************************************************************************************************************************/

bigint bigint::operator/(long long x)
{
	bigint result;
	int i;
	long long tmp,n;
	
	n=0;
	for(i=length-1;i>=0;--i)
	{
		tmp=n*10+digit[i];
		if(tmp>=x)
			break;
		n=tmp;
	}
	
	result.length=i+1;
	for(;i>=0;--i)
	{
		n*=10;
		n+=digit[i];
		result.digit[i]=n/x;
		n%=x;
	}
	return result;
}

/************************************************************************************************************************************/
int bigint::operator%(int x)
{
	int result=0;
	int i;
	for(i=length-1;i>=0;--i)
		result=(result*10+digit[i])%x;
	return result;
}

/************************************************************************************************************************************/
long long bigint::operator%(long long x)
{
	long long result=0;
	int i;
	for(i=length-1;i>=0;--i)
		result=(result*10+digit[i])%x;
	return result;
}

/************************************************************************************************************************************/
bool bigint::operator==(bigint x)
{
	int i;
	
	if(length!=x.length)
		return false;
	for(i=0;i<length;++i)
		if(digit[i]!=x.digit[i])
			return false;
	return true;
}

/************************************************************************************************************************************/
bool bigint::operator!=(bigint x)
{
	int i;
	
	if(length!=x.length)
		return true;
	for(i=0;i<length;++i)
		if(digit[i]!=x.digit[i])
			return true;
	return false;
}

/************************************************************************************************************************************/
bool bigint::operator<=(bigint x)
{
	int i;
	
	if(length!=x.length)
		return length<x.length;
		
	for(i=length-1;i>=0;--i)
		if(digit[i]!=x.digit[i])
			return digit[i]<x.digit[i];
	
	return true;
}

/************************************************************************************************************************************/
bool bigint::operator>(bigint x)
{
	int i;
	
	if(length!=x.length)
		return length>x.length;
		
	for(i=length-1;i>=0;--i)
		if(digit[i]!=x.digit[i])
			return digit[i]>x.digit[i];
	
	return false;
}

/************************************************************************************************************************************/
bool bigint::operator>=(bigint x)
{
	int i;
	
	if(length!=x.length)
		return length>x.length;
	
	for(i=length-1;i>=0;--i)
		if(digit[i]!=x.digit[i])
			return digit[i]>x.digit[i];
			
	return true;
}

/************************************************************************************************************************************/
bool bigint::operator<(bigint x)
{
	int i;
	
	if(length!=x.length)
		return length<x.length;
	
	for(i=length-1;i>=0;--i)
		if(digit[i]!=x.digit[i])
			return digit[i]<x.digit[i];
			
	return false;
}

/************************************************************************************************************************************/
ostream & operator<<(ostream &bout,bigint x)
{
	int i;
	
	if(x.length==0)
		bout<<0;
	for(i=x.length-1;i>=0;--i)
		bout<<(char)(x.digit[i]+'0');
	return bout;
}

/************************************************************************************************************************************/
bigint::operator int()
{
	int result=0;
	int i;
	for(i=length-1;i>=0;--i)
	{
		result*=10;
		result+=digit[i];
	}
	return result;
}

/************************************************************************************************************************************/
bigint::operator long long()
{
	long long result=0;
	int i;
	for(i=length-1;i>=0;--i)
	{
		result*=10;
		result+=digit[i];
	}
	return result;
}

/************************************************************************************************************************************/
bigint::operator string()
{
	string result;
	int i;
	for(i=length-1;i>=0;--i)
		result+=digit[i]+'0';
	return result;
}

bool is_palin(LL n) {
    LL on = n;
    LL r = 0;
    while(n>0) {
        r*=10;
        r += n%10;
        n/=10;
    }
    return r == on;
}

vector<bigint> fair;

bool is_palin(string s) {
    string rs = s;
    reverse(ALL(rs));
    return s == rs;
}

void addFair(string s) {
    bigint b(s);
    bigint x(b*b);
    string sq_str = (string) x;
    if(is_palin(sq_str)) fair.push_back(x);
}

void doit(string s) {
    string rs = s;
    reverse(ALL(rs));
    addFair(s + '0' + rs);
    addFair(s + '1' + rs);
    addFair(s + '2' + rs);
    addFair(s + rs);
}
void doit(int d) {
    int x = d / 2 - 1;

    for (int i = 0; i < (1 << x); ++i) {
        string s(x+1,'0');
        s[0] = '1';
        for (int j = 0; j < x; ++j) {
            if ((i & (1 << j)) != 0) {
                s[j+1] = '1';
            }
        }
        doit(s);
    }

    string s2(x+1, '0');
    s2[0] = '2';
    doit(s2);
}

int main() {

    int a[10] = {1, 4, 9, 121, 484,
                10201, 12321, 14641, 40804, 44944};

    for(int i=0;i<10;++i) fair.push_back(bigint(a[i]));
    for(int d = 4; d <= 20; d += 2) {
        doit(d);
    }
    
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t<=tc;++t) {
        char a[200], b[200];
        scanf("%s %s", a, b);
        bigint A(a);
        bigint B(b);
        int c = 0;
        for(int i=0; i<=SZ(fair);++i) {
            if(fair[i] >= A && fair[i] <=B) ++c;
        }
        printf("Case #%d: %d\n",t,c);
    }
    return 0;
}

