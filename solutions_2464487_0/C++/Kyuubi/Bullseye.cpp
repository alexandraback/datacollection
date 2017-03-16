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
int t;
long long r,tp;
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



int main()
{
	fread(arr,sizeof(char),MAXA,stdin);
	ptr = arr;
	t = get_int();
	long long count;
	long long paint;
	for(int tt =1;tt<=t;tt++)
	{
		r = get_int();
		tp = get_int();
		count = 0;
		paint = tp;
		long long i = 1;
		while (paint >=0) {
			paint = paint - (((r+i)*(r+i)) - ((r+i-1)*(r+i-1)));
			i=i+2;
			count++;
		}
		count--;
		cout << "Case #" << tt << ": " << count << endl;
	}
	return 0;
}