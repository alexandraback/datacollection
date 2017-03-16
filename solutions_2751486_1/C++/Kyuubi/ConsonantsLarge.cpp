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
int n;


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

long long dp[1000005];
int main()
{
	fread(arr,sizeof(char),MAXA,stdin);
	ptr = arr;
	int t = get_int();
	string name;
	long long tot;
	int count;
	int p;
	for(int tt = 1;tt<=t; tt++)
	{
		bool flag = false;
		name = get_str();
		n = get_int();
		tot = 0;
		count = 0;
		p = 0;
		for(int i = 0;i<name.length();i++)
		{
			if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
			{
				flag = true;
				count = 0;
				p = i;
				dp[i] = dp[i-1];
			}
			else
			{
				count++;
				if(flag)
				{
					p = i;
					flag = false;
				}
				
				if(count == n)
				{
					dp[i] = p+1;
				}
				else if (count >= n)
				{
					dp[i] = dp[i-1]+1;
				}
				else
					dp[i] = dp[i-1];
			}
		}
		
		for(int i = 0; i<name.length();i++){
			tot += dp[i];
		}
		cout << "Case #" << tt << ": " << tot << endl;
	}
	
	return 0;
}