///////////////////////////////////////////////////////////////////////
/////    The code is written for Google Code Jam 2013 contest.    /////
/////    You may use any part of this code without exception.     /////
/////    The author is not responsible for any consequences       /////
/////    of using this code.                                      /////
/////                                                             /////
/////    Author: Andrey Rubtsov                                   /////
///////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <hash_map>
#include <hash_set>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <utility>
#include <valarray>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;
class bigint
{
	static const int maxlength = 100;
    int oper,length,a[maxlength];

public:
	
	bigint(int=0);
    bigint(char const* s);
	void check();
	void operator=(bigint const& m);
	void operator=(int m);
	void operator=(char const *s);
	bool operator<(bigint const& m) const;
	bool operator<=(bigint const& m) const;
	bool operator>(bigint const& m) const;
	bool operator>=(bigint const& m) const;
	bool operator==(bigint const& m) const;
	bool operator!=(bigint const& m) const;
	bigint operator-() const;
	bigint operator+(bigint const& m) const;
	void operator+=(bigint const& m);
	bigint operator-(bigint const& m) const;
	void operator-=(bigint const& m);
	bigint operator*(bigint const& m) const;
	bigint operator*(int m) const;
	void operator*=(bigint const& m);
	void operator*=(int m);
	bigint operator/(bigint const& m) const;
	bigint operator/(int m) const;
	void operator/=(bigint const& m);
	void operator/=(int m);
	bigint operator%(bigint const& m) const;
	bigint operator%(int m) const;
	void operator%=(bigint const& m);
	void operator%=(int m);

    friend std::istream& operator >> (std::istream& stream, bigint& m);
    friend std::ostream& operator << (std::ostream& stream, bigint const& m);
    friend bigint abs(bigint const& m);
    friend bigint sqr(bigint const& m);
    friend bigint sqrt(bigint const& m);
    friend bigint gcd(bigint const& a,bigint const& b);
    friend bigint lcm(bigint const& a,bigint const& b);
};


bigint::bigint(int v)
{
	(*this)=v;
	check();
}
bigint::bigint(char const* s)
{
    (*this) = s;
    check();
}
void bigint::check()
{
	for (;length>0 && a[length]==0;length--);
	if (length==0)
		oper=1;
}
void bigint::operator=(bigint const& m)
{
	oper=m.oper;
	length=m.length;
	memcpy(a,m.a,maxlength*sizeof(int));
	check();
}
void bigint::operator=(int m)
{
	oper=(m>0)?1:-1;
	m=abs(m);
	memset(a,0,maxlength*sizeof(int));
	for (length=0;m>0;m=m/10000)
		a[++length]=m%10000;
	check();
}
void bigint::operator=(char const*s)
{
	int i,L;
	(*this)=0;
    char const* p = s;

	if (s[0]=='-' || s[0]=='+')
	{
		if (s[0]=='-')
			oper=-1;

        ++p;
	}

	L=strlen(p);
	length=(L+3)/4;
	for (i=0;i<L;i++)
		a[(L-i+3)/4]=a[(L-i+3)/4]*10+(p[i]-'0');
	check();
}
bool bigint::operator<(bigint const& m) const
{
	if (oper!=m.oper)
		return oper<m.oper;
	if (length!=m.length)
		return oper*length<m.length*oper;
	for (int i=length;i>=1;i--)
		if (a[i]!=m.a[i])
			return a[i]*oper<m.a[i]*oper;
	return false;
}
bool bigint::operator<=(bigint const& m) const
{
	return !(m<(*this));
}
bool bigint::operator>(bigint const& m) const
{
	return m<(*this);
}
bool bigint::operator>=(bigint const& m) const
{
	return !((*this)<m);
}
bool bigint::operator==(bigint const& m) const
{
	return (!((*this)<m)) && (!(m<(*this)));
}
bool bigint::operator!=(bigint const& m) const
{
	return ((*this)<m) || (m<(*this));
}
bigint bigint::operator-() const
{
	bigint c=(*this);
	c.oper=-c.oper;
	c.check();
	return c;
}
bigint bigint::operator+(bigint const& m) const
{
	if (m.length==0)
		return (*this);
	if (length==0)
		return m;
	if (oper==m.oper)
	{
		bigint c;
		c.oper=oper;
        c.length=std::max(length,m.length)+1;
		for (int i=1,temp=0;i<=c.length;i++)
			c.a[i]=(temp=(temp/10000+a[i]+m.a[i]))%10000;
		c.check();
		return c;
	}
	return (*this)-(-m);
}
bigint bigint::operator-(bigint const& m) const
{
	if (m.length==0)
		return (*this);
	if (length==0)
		return (-m);
	if (oper==m.oper)
	{
		bigint c;
		if (abs(*this)>=abs(m))
		{
			c.oper=oper;
			c.length=length;
			for (int i=1,temp=0;i<=length;i++)
				c.a[i]=((temp=(-int(temp<0)+a[i]-m.a[i]))+10000)%10000;
			c.check();
			return c;
		}
		return -(m-(*this));
	}
	return (*this)+(-m);
}
bigint bigint::operator*(bigint const& m) const
{
	bigint c;
	c.oper=oper*m.oper;
	c.length=length+m.length;
	for (int i=1;i<=m.length;i++)
	{
		int number=m.a[i],j,temp=0;
		for (j=1;j<=length;j++)
			c.a[i+j-1]+=number*a[j];
		if (i%10==0 || i==m.length)
			for (j=1;j<=c.length;j++)
				c.a[j]=(temp=(temp/10000)+c.a[j])%10000;
	}
	c.check();
	return c;
}
bigint bigint::operator*(int m) const
{
	if (m<0)
		return -((*this)*(-m));
	if (m>100000)
		return (*this)*bigint(m);
	bigint c;
	c.length=length+2;
	c.oper=oper;
	int t=0;
	for (int i=1;i<=c.length;i++)
		c.a[i]=(t=(t/10000+a[i]*m))%10000;
	c.check();
	return c;
}
bigint bigint::operator/(bigint const& m) const
{
	if (m.length==0)
	{
		printf("Division by zero.\n");
		exit(0);
	}
    
	bigint c, left, right(abs(m));

	if (abs(*this)<right)
		return 0;

	c.oper=oper/m.oper;
	c.length=length-m.length+1;
	left.length=m.length-1;
	memcpy(left.a+1,a+length-left.length+1,left.length*sizeof(int));
	for (int i=c.length;i>=1;i--)
	{
		left=left*10000+a[i];
		int head=0,tail=10000,mid;
		while (head+1<tail)
		{
			mid=(head+tail)/2;
			if (right*mid<=left)
				head=mid;
			else
				tail=mid;
		}
		c.a[i]=head;
		left-=right*head;
	}
	c.check();
	return c;
}
bigint bigint::operator/(int m) const
{
	if (m<0)
		return -((*this)/(-m));
	if (m>100000)
		return (*this)/bigint(m);
	bigint c;
	c.oper=oper;
	c.length=length;
	int t=0;
	for (int i=c.length;i>=1;i--)
		c.a[i]=(t=(t%m*10000+a[i]))/m;
	c.check();
	return c;
}
bigint bigint::operator %(bigint const& m) const
{
	return (*this)-((*this)/m)*m;
}
bigint bigint::operator%(int m) const
{
	if (m<0)
		return -((*this)%(-m));
	if (m>100000)
		return (*this)%bigint(m);
	int t=0;
	for (int i=length;i>=1;i--)
		t=(t*10000+a[i])%m;
	return t;
}

void bigint::operator+=(bigint const& m)
{
	(*this)=(*this)+m;
}
void bigint::operator-=(bigint const& m)
{
	(*this)=(*this)-m;
}
void bigint::operator*=(bigint const& m)
{
	(*this)=(*this)*m;
}
void bigint::operator/=(bigint const& m)
{
	(*this)=(*this)/m;
}
void bigint::operator%=(bigint const& m)
{
	(*this)=(*this)%m;
}
void bigint::operator*=(int m)
{
	(*this)=(*this)*m;
}
void bigint::operator/=(int m)
{
	(*this)=(*this)/m;
}
void bigint::operator%=(int m)
{
	(*this)=(*this)%m;
}

std::istream& operator >> (std::istream& stream, bigint& m)
{
    std::string str;
    stream >> str;

    if (str.size() > m.maxlength)
    {
        cout << "invalid size";
        exit(0);
    }

    if (str.npos != str.find_first_not_of("0123456789", (str[0] == '+' || str[0] == '-') ? 1 : 0))
    {
        cout << "invalid chars";
        exit(0);
    }

    m = str.c_str();
    return stream;
}

std::ostream& operator << (std::ostream& stream, bigint const& m)
{
	if (m.oper==-1)
		stream << "-";

    stream << m.a[m.length];

	for (int i=m.length-1;i>=1;i--)
        stream << std::setw(4) << std::setfill('0') << m.a[i];

    return stream;
}

bigint abs(bigint const& m)
{
	bigint c=m;
	c.oper=abs(c.oper);
	c.check();
	return c;
}
bigint sqr(bigint const& m)
{
	return m*m;
}
bigint sqrt(bigint const& m)
{
	if (m.oper<0 || m.length==0)
		return 0;
	bigint c,last,now,templast;
	c.length=(m.length+1)/2;
	c.a[c.length]=int(sqrt((double)m.a[c.length*2]*10000+m.a[c.length*2-1])+1e-6);
	templast.length=c.length*2;
	templast.a[c.length*2-1]=(c.a[c.length]*c.a[c.length])%10000;
	templast.a[c.length*2]=(c.a[c.length]*c.a[c.length])/10000;
	templast.check();
	for (int i=c.length-1;i>=1;i--)
	{
		last=templast;
		int head=0,tail=10000,mid,j,temp;
		while (head+1<tail)
		{
			mid=(head+tail)/2;
			now=last;
			now.a[2*i-1]+=mid*mid;
			for (j=i+1;j<=c.length;j++)
				now.a[i+j-1]+=mid*c.a[j]*2;
			now.length++;
			for (j=2*i-1,temp=0;j<=now.length;j++)
				now.a[j]=(temp=(temp/10000+now.a[j]))%10000;
			now.check();
			if (now<=m)
			{
				templast=now;
				head=mid;
			}
			else
				tail=mid;
		}
		c.a[i]=head;
	}
	c.check();
	return c;
}

bigint gcd(bigint const& a,bigint const& b)
{
	return (b==0)?a:gcd(b,a%b);
}
bigint lcm(bigint const& a,bigint const& b)
{
	return a*b/gcd(a,b);
}

#define PROBLEM_NAME "C"
#define LARGE_INPUT 1

#if LARGE_INPUT
    #define INPUT_FILE PROBLEM_NAME "-large-1.in"
    #define OUTPUT_FILE PROBLEM_NAME "-large-1.out"
#else
    #define INPUT_FILE PROBLEM_NAME "-small-attempt.in"
    #define OUTPUT_FILE PROBLEM_NAME "-small1.out"
#endif

std::vector<bigint> table;

void AddToTable(char* num)
{
    table.push_back(sqr(bigint(num)));
}

void PrintTable()
{
    for (size_t i = 0; i != table.size(); ++i)
        cout << table[i] << "\t\t\t" << sqrt(table[i]) << endl;
}

void MakeTable()
{
    table.push_back(1);
    table.push_back(4);
    table.push_back(9);

    char num[110] = {};

    for (size_t size = 2; size <= 50; ++size)
    {
        size_t z1 = 0, z2 = 0, z3 = 0;

        size_t lMid = size / 2;
        size_t rMid = size / 2 - !(size % 2);

        for (;;)
        {
            memset(num, '0', size);

            num[0] = num[size - 1] = '1';

            if (z1)
                num[lMid - z1] = num[rMid + z1] = '1';
            if (z2)
                num[lMid - z2] = num[rMid + z2] = '1';
            if (z3)
                num[lMid - z3] = num[rMid + z3] = '1';

            AddToTable(num);

            if (lMid == rMid)
            {
                num[lMid] = '1';
                AddToTable(num);

                if (!z1 + !z2 + !z3 > 1)
                {
                    num[lMid] = '2';
                    AddToTable(num);
                }
            }

            ++z3;

            if (z3 >= z2)
            {
                ++z2; z3 = 0;
            }

            if (z2 >= z1)
            {
                ++z1; z2 = 0;
            }

            if (z1 >= size / 2)
            {
                break;
            }
        }

        memset(num, '0', size);
        num[0] = num[size - 1] = '2';
        AddToTable(num);

        if (lMid == rMid)
        {
            num[lMid] = '1';
            AddToTable(num);
        }
    }

}

int main()
{
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);

    MakeTable();

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        std::string A, B;
        cin >> A >> B;

        std::vector<bigint>::const_iterator from = std::lower_bound(table.begin(), table.end(), bigint(A.c_str()));
        std::vector<bigint>::const_iterator to = std::upper_bound(table.begin(), table.end(), bigint(B.c_str()));

        int count = to - from;
        cout << "Case #" << i + 1 << ": " << count << endl;
    }

    return 0;
}