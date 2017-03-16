#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

#define MAXA 50000000
#define MOD 1000000007

using namespace std;

typedef map <int, int> MAP;
typedef multiset <int> SET;
typedef map <int, SET> MAPs;
typedef set <SET> sSET;
typedef vector <int> LIST;
typedef map <int, LIST> MAPl;

MAP		::iterator it_m;
SET		::iterator it_s;
MAPs	::iterator it_ms;
sSET	::iterator it_ss;
LIST	::iterator it_l;
MAPl	::iterator it_ml;

MAP		::reverse_iterator rit_m;
SET		::reverse_iterator rit_s;
MAPs	::reverse_iterator rit_ms;
sSET	::reverse_iterator rit_ss;
LIST	::reverse_iterator rit_l;
MAPl	::reverse_iterator rit_ml;

char arr[MAXA],*ptr;
long long ret;
string str;

long long t,a,n;

inline long long get_int()
{
	bool isNeg = false;
	ret =0;
	while ( !((*ptr >= '0' && *ptr <= '9')|| *ptr == '-'))
		ptr++;
	while ((*ptr >= '0' && *ptr <= '9')|| *ptr == '-') {
		if(*ptr == '-')
			isNeg = true;
		else
			ret = ret*10 + (*ptr - '0');
		ptr++;
	}
	if(isNeg)
		ret = -ret;
	return ret;
}

inline long long power (long long x,long long n)
{
	if (n==0)
		return 1;
	long long p;
	if (n%2 == 0)
	{
		p = power(x,n/2);
		return ((p*p)%MOD);
	}
	else if (n%2 == 1)
	{
		p = power(x,n/2);
		p = (((p*p)%MOD)*x)%MOD;
		return p;
	}
}
int na,eatenCount;
SET motes;
void eat(){
	for(;motes.size() > 0 && na > *motes.begin();)
	{
		it_s = motes.begin();
		na += (*it_s);
		motes.erase(it_s);
		eatenCount++;
	}
}


int main()
{
	cin >> t;
	int start,m,effort;
	long long minTillNow;
	for(int tt = 1;tt<= t;tt++)
	{
		motes.clear();
		effort = 0;
		eatenCount = 0;
		cin >> a;
		cin >> n;
//		cout << " A IS " << a << " n = " << n << endl;
		
		for(int xx =0;xx<n;xx++)
		{
			cin >> m;
			motes.insert(m);
		}
		if(a == 1)
		{cout << "Case #" << tt << ": " << n << endl; continue;}
		na = a;
		eat();
		if(eatenCount == n)
		{cout << "Case #" << tt << ": " << 0<< endl; continue;}
		
		minTillNow = -1;
		while(eatenCount < n)
		{
			start = na-1;
			m = 1;
//			cout << " NA : " << na << " A: " << a << " START :" << start << endl;
			while((start * (power(2,m) - 1))+na <= *motes.begin() && motes.size() > 0)
				m++;
			na = (start * (power(2,m) - 1))+na;
			if(minTillNow == -1)
				minTillNow = n-eatenCount;
			
			if(m < n - eatenCount)
			{
				if(minTillNow < effort + m)
				{effort = minTillNow;break;}
				if(minTillNow > effort + n-eatenCount)
					minTillNow = effort + n-eatenCount;
				effort += m;
				eat();
				
			}
			else{
				if(minTillNow < effort + (n - eatenCount))
				{effort = minTillNow;break;}
				effort += (n - eatenCount);
				break;
			}
		}
		cout << "Case #" << tt << ": " << effort << endl;
	}
	return 0;
}