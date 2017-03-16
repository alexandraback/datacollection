/*************************************************************************
    > File Name: number.cpp
    > Author: Hu Pengxiang
    > Mail: hpxiangsky@gmail.com 
    > Created Time: Fri 12 Apr 2013 09:53:30 AM CST
 ************************************************************************/

/*************************************************************************
* History: 
*       1. Apr 13th 2013,  modified by Hu Pengxiang, adding support for palindromes number detection, only support integer.
*       2. Apr 12th 2013,  modified by Hu Pengxiang, adding support for singed number. 
*       3. Dec 20th 2012,  created by Hu Pengxiang, support calculations(+ - *) that will not overflow.
*
* Class Presentation:
*       1. extended basic data structe,  supporting int && long && float && double.
*       2. calculation including + - * will not overflow
*       3. support signed number.
****************************************************************************/

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class number
{
public:
	typedef unsigned long ulong;
	typedef unsigned short ushort;

public:
	number();
	~number();
	number(const number &rhs);
	number(const string &s);                      //using a string containg the data to init, such as 25.07
	number(const char *s);
	number(int s);
	const number &operator=(const number &rhs);
public:
	const number &operator *(const number &) const;        
	const number &operator +(const number &) const;
	const number &operator ++();
	const number &operator +=(number &);
	bool operator == (const number &) const;
	bool operator != (const number &) const;
	bool operator > (const number &) const;
	bool operator >= (const number &) const;
	bool operator < (const number &) const;
	bool operator <= (const number &) const;
	int compare(const number &) const;
public:
	void display(void);                     //display the number in the screen
    bool isPalindrome(void) const;          //judge whether the number is a palindrome
public:
	void simple(void);                      //simple the information, eraze uncessary zeros
	void enlarge(void);                     //enlarge data in order to express larger number

public:
	string	*data;                          //saving data information
protected:
	friend ostream & operator<<(ostream &, number &);
	friend istream & operator>>(istream &, number &);
};

number::number()
{
	data = new string;
}

number::number(const string &s)
{
	data = new string(s);
}

number::number(const char *s)
{
	string s2(s);
	number *tmp = new number(s2);
	*this = *tmp;
}

number::number(int num)
{
	char buf[10];
	sprintf(buf, "%d", num);
	string s(buf);
	number *tmp = new number(s);
	*this = *tmp;
}

number::number(const number &rhs)
{
	*this = rhs;
}

const number &number::operator=(const number &rhs)
{
	data = new string(*rhs.data);
	return *this;
}

number::~number()
{
	delete data;
}

void number::simple(void)
{
	//erase heading zeros
	while( data->find_first_of('0', 0) == 0 )
	{
		data->erase(0, 1);
	}

}
void number::enlarge(void)
{
	data->insert(0, (4-data->length())%4, '0');
}

const number &number::operator*(const number &rhs) const
{
	//enlarge string data to the length of a multiple of 4
	number num2 = rhs;
	number num1 = rhs;
	num1.enlarge();
	num2.enlarge();
	int len1 = num1.data->length();
	int len2 = num2.data->length();

	ulong d1, d2, tmp;
	ulong rL, rH, ad;
	ushort *r = new ushort[len1 + len2];

	//initialize r
	for(int i = 0; i < len1+len2;++i)
	{
		r[i] = 0;
	}

	//calculate
	for(int i = 0; i < len1 / 4; ++i)
	{
		d1 = atoi(num1.data->substr(len1-4-i*4,4).c_str());

		for(int j = 0; j < len2 / 4; ++j)
		{
			d2 = atoi(num2.data->substr(len2-4-j*4,4).c_str());

			tmp = d1 * d2;
			rL = tmp % 10000;
			rH = (ulong)(tmp / 10000);

			tmp = r[i+j] + rL;
			r[i+j] = tmp % 10000;
			ad = (ulong)(tmp / 10000);

			tmp = r[i+j+1] + rH + ad;
			ad = (ulong) (tmp / 10000);
			r[i+j+1] = tmp % 10000;

			int offset = 1;
			while(ad)
			{
				offset++;
				tmp = r[i+j+offset]+ad;
				r[i+j+offset] = tmp % 10000;
				ad = (ushort)(tmp / 10000);
			}
		}
	}

	//save result
	number *num = new number();
	num->data = new string();
	for(int i = 0; i < (len1+len2)/4;++i)
	{
		int cnt = 0;
		for(int j = 1000;j >= 1;j = j / 10)
		{
			if(r[(len1+len2)/4-1-i] >= j)
				break;
			else
			{
				cnt ++;
				num->data->append("0");
			}			
		}
		cnt = 4 - cnt;
		if(cnt != 0)
		{
			char *buf = new char[cnt];
			sprintf(buf, "%d", r[(len1+len2)/4-1-i]);
			num->data->append(buf);
		}
		
	}
	num->simple();
	return *num;
}

const number& number::operator+(const number &rhs) const
{
	number num2 = rhs;
	number num1 = *this;
	
	//preprocess
	int maxInteger;
	if(num1.data->length() > num2.data->length())
	{
		string tmp(num1.data->length()-num2.data->length(), '0');
		tmp += *num2.data;
		*num2.data = tmp;
		maxInteger = num1.data->length();
	}
	else
	{
		string tmp(num2.data->length()-num1.data->length(), '0');
		tmp += *num1.data;
		*num1.data = tmp;
		maxInteger = num2.data->length();
	}

	int len = maxInteger + 1;
	ushort *r = new ushort[len];

	//initialize r
	for(int i = 0; i < len;++i)
	{
		r[i] = 0;
	}

	//calculate
	int tmp, ad = 0;
	int d1, d2;
	for(int i = 0; i < len-1; ++i)
	{
		d1 = atoi(num1.data->substr(len-2-i, 1).c_str());
		d2 = atoi(num2.data->substr(len-2-i, 1).c_str());
		tmp = d1 + d2 + ad;
		if(tmp >= 10)
		{
			tmp = tmp % 10;
			ad = 1;
		}
		else
			ad = 0;
		r[i] = tmp;
	}
	r[len-1] = ad;

	//save result
	number *num = new number();
	num->data = new string();
	for(int i = 0;i < len;++i)
	{
		char *buf = new char[1];
		sprintf(buf, "%d", r[len-1-i]);
		num->data->append(buf);
	}
	num->simple();
	return *num;
}

const number& number::operator++()
{
	*this = *this + 1;
	return *this;
}

const number& number::operator+=(number &num2)
{
	*this = *this + num2;
	return *this;
}

bool number::operator > (const number &num2) const
{
	int r = compare(num2);
	if(r == 1)
		return true;
	return false;
}

bool number::operator < (const number &num2) const
{
	int r = compare(num2);
	if( r == -1)
		return true;
	return false;
}
bool number::operator <= (const number &num2) const
{
	int r = compare(num2);
	if( r == -1 || r == 0)
		return true;
	return false;
}
bool number::operator >= (const number &num2) const
{
	int r = compare(num2);
	if( r == 1 || r== 0)
		return true;
	return false;
}



bool number::operator == (const number &num2) const
{
	int r = compare(num2);
	if( r == 0)
		return true;
	return false;
}

bool number::operator != (const number &num2) const
{
	int r = compare(num2);
	if( r != 0)
		return true;
	return false;
}

int number::compare(const number &num2) const
{
	int abs;
	abs = data->length() - num2.data->length();
	if(abs == 0)
	{
		unsigned int minLen = data->length();
		if(minLen > num2.data->length())
			minLen = num2.data->length();
		for(unsigned int i = 0; i < minLen;++i)
		{
			if(i > num2.data->length() - 1)
			{
				abs = 1;
				break;
			}
			if(i > data->length() - 1)
			{
				abs = -1;
				break;
			}
			abs = (int)(data->at(i)) - (int)(num2.data->at(i));
			if(abs != 0)
				break;
		}
	}

	if(abs >=1)
		abs = 1;
	if(abs <= -1)
		abs = -1;
	return abs;
}

ostream &operator << (ostream &out, number &rhs)
{
	rhs.simple();
	out << *rhs.data;
	return out;
}

istream & operator>>(istream &in, number &rhs)
{
	string a;
	in >> a;
	rhs.data->assign(a);
	return in;
}

void number::display(void)
{
	simple();
	cout << *data;
}

bool number::isPalindrome(void) const //ignore base point, negative 
{
	int i = 0, j = data->size()-1;
	while(i < j)
	{
		if(data->at(i++) != data->at(j--))
			return false;
	}
	return true;
}

