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
typedef set <int> SET;
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

inline string get_str()
{
    str = "";
    while ( !((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) )
        ptr++;
    while ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z'))
    {
        str += char(*ptr);
        ptr++;
    }
    return str;
}

struct tribe {
	int d;
	int n;
	int w;
	int e;
	int s;
	int dd;
	int dp;
	int ds;
}tribes[15];

multimap <int ,tribe> attack;
int wall[805];
bool end[805];

int getIndex(int p)
{
	p += 200;
	return p;
}

int getPoint(int p)
{
	p -= 200;
	return p;
}

int maxOf(long long i, long long j)
{
	if(i >j)
		return i;
	return j;
}

int main()
{
	fread(arr,sizeof(char),MAXA,stdin);
	ptr = arr;
	int t = get_int();
	int n;
	for(int tt = 1;tt<=t;tt++)
	{
		for(int i =0;i<805;i++)
		{
			wall[i] = 0;
			end[i] = false;
		}
		n = get_int();
		for(int i = 0;i<n;i++)
		{
			tribes[i].d = get_int();
			tribes[i].n = get_int();
			tribes[i].w = get_int();
			tribes[i].e = get_int();
			tribes[i].s = get_int();
			tribes[i].dd = get_int();
			tribes[i].dp = get_int();
			tribes[i].ds = get_int();
			attack.insert(pair< int, tribe>(tribes[i].d, tribes[i]));
		}
		tribe a;
		int day;
		bool suc = false;
		long long count = 0;
		int pday = -1;
		int mpday;
		mpday = 500000;
		bool sameDay;
		while(attack.size() > 0)
		{
			suc = false;
			a = attack.begin()->second;
			day = attack.begin()->first;
			attack.erase(attack.begin());

			if( day == pday )
				sameDay = true;
			else
			{
				mpday = 500000;
				sameDay = false;
			}
			for(int i = (2*getIndex(a.w))+1;i<= 2*getIndex(a.e); i++)
			{

				if(wall[i] < a.s || (sameDay && mpday < a.s))
				{
					if(wall[i] < mpday && !sameDay)
						mpday = wall[i];
					if(!suc)
					{
						count++;
						suc = true;
					}
					wall[i] = maxOf(a.s,wall[i]);
				}
			}
			
			a.n--;
			a.d += a.dd;
			a.e += a.dp;
			a.w += a.dp;
			a.s += a.ds;
			pday = day;
			if(a.n > 0)
				attack.insert(pair< int, tribe>(a.d, a));
		}
		
		cout << "Case #" << tt << ": " << count << endl;
	}
	return 0;
}