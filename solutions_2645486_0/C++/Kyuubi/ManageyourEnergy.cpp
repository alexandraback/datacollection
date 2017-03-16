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
long long e,r,n;
long long val[10005];
string str;
int maxAr[11];
long long toDodo;

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


class counter {
public:
	int arr[11];
	int size;
	int limit;
	long long counted;
	int all;
	int maxGain;
	bool done;
	counter(int s,int l,int r)
	{
		counted = 1;
		done = false;
		for(int xx =0;xx<10;xx++)
			arr[xx] = 0;
		size = s;
		limit = l;
		all = l + ((s-1)*r);
//		cout << "ALL :" << all << endl;
	}
	void inc(int pos){
		if(pos == size-1)
		{done = true;return;}
//		if(pos == size-1)
//			return;
		arr[pos]++;
		if(arr[pos] > limit)
		{
			arr[pos] = 0;
			inc(pos+1);
		}
	}
	void inc(){
		inc(0);
		counted++;
	}
	
	bool isPossible(int en, int reg){
		int check = 0,maxN = en;
		maxGain = 0;
		for(int xx =0;xx<size-1;xx++){
			check += arr[xx];
			maxGain += (arr[xx]*val[xx]);
			if(en-arr[xx] >=0)
			{
				en -= arr[xx];
				en += reg;
				if(en > maxN)
					en = maxN;
			}
			else
				return false;
		}
//		cout << " CHECK :" << check;
		arr[size-1] = all-check;
		if(arr[size-1] > maxN)
			return false;
		maxGain += (arr[size-1]*val[size-1]);
		return true;
	}
};

int main()
{
	clock_t tStart = clock();
	fread(arr,sizeof(char),MAXA,stdin);
	ptr = arr;
	t = get_int();
	long long maxGain,mMaxGain;
	for(int tt = 1;tt<=t;tt++){
		maxGain = 0;
		mMaxGain = 0;
		e = get_int();
		r = get_int();
		n = get_int();
		
		toDodo = e;
		for(int xx =0;xx<n;xx++)
			toDodo *= e;
		
		if(r>e)
			r = e;
		for(int xx =0;xx<n;xx++)
			val[xx] = get_int();
		counter perm(n,e,r);
		while(!perm.done){
			maxGain = 0;
			if(perm.isPossible(e,r))
			{
				if(perm.maxGain > mMaxGain)
				{
					mMaxGain = perm.maxGain;
					for(int xx =0;xx<n;xx++)
						maxAr[xx] = perm.arr[xx];
				}
			}
			perm.inc();
		}
//		for(int xx =0;xx<n;xx++)
//			cout << maxAr[xx] << " " ;
//		cout << endl;
		cout << "Case #" << tt << ": " << mMaxGain << endl;
	}
//	printf("\n%.4f\n",float(clock()-tStart)/CLOCKS_PER_SEC);
	return 0;
}