#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define LL long long
#define U unsigned

string s1,s2;

pair<bool, LL> canBeEqual() {
	LL res = 0;
	FOR(i,0,s1.size()) {
		if ((s1[i] == '?') && (s2[i] == '?')) {
			res *= 10;
			continue;
		}
		if (s1[i] == '?')
		{
			res = res * 10 + (s2[i] - '0');
			continue;
		}
		if (s2[i] == '?')
		{
			res = res * 10 + (s1[i] - '0');
			continue;
		}
		if (s1[i] == s2[i]) {
			res = res * 10 + (s2[i] - '0');
			continue;
		}
		return mp(false,0ll);
	}
	return mp(true, res);
}

vector<int> range1,range2;

vector<int> genVec(string &s, int p) {
	vector<int> res;
	if (s[p] == '?')
	FOR(i,0,10)
		res.push_back(i);
	else
		res.push_back(s[p] - '0');
	return res;
}

pair<LL, pair<LL, LL>> genAns(LL val1, LL val2, int start) {
	LL res1 = val1;
	LL res2 = val2;
	FOR(i,start,s1.size()) {
		bool ok = (res1>res2);
		if (s1[i] == '?') {
			if (ok)
				res1*=10;
			else
				res1 = res1*10+9;
		} else {
			res1 = res1*10+(s1[i] - '0');
		}
		if (s2[i] == '?') {
			if (!ok)
				res2*=10;
			else
				res2 = res2*10+9;
		} else {
			res2 = res2*10+(s2[i] - '0');
		}
	}
	return mp(ABS(res1-res2),mp(res1,res2));
}

string genString(LL ans) {
	stringstream tmp;
	tmp<<ans;
	string res;
	tmp>>res;
	while (res.size()<s1.size())
		res = "0"+res;
	return res;
}

int main()
{
#ifdef Fcdkbear
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        double beg = clock();
#else
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
#endif

        int tests;
        scanf("%d",&tests);
        FOR(testNumber, 1, tests+1) {
        	cin>>s1>>s2;
        	cout<<"Case #"<<testNumber<<": ";
        	pair<bool, LL> temp = canBeEqual();
        	if (temp.first) {
        		cout<<genString(temp.second)<<" "<<genString(temp.second)<<endl;
        		continue;
        	}
        	pair<LL, pair<LL,LL> > res = mp(2000000000000000000ll, mp(0,0));
        	LL pre = 0;
        	FOR(i,0,s1.size()) {
        		range1 = genVec(s1,i);
        		range2 = genVec(s2,i);
        		FOR(j,0,range1.size()) {
        			FOR(k,0,range2.size()) {
        				if (range1[j] == range2[k])
        					continue;
        				pair<LL, pair<LL,LL> > temp = genAns(pre*10+range1[j],pre*10+range2[k],i+1);
        				res = min(res,temp);
        			}
        		}
        		if ((s1[i] != '?') && (s2[i] != '?') && (s1[i] != s2[i]))
        			break;
        		if ((s1[i] == '?') && (s2[i] == '?')) {
        			pre*=10;
        			continue;
        		}
        		if (s1[i] == '?')
        		{
        			pre = pre*10+(s2[i]-'0');
        			continue;
        		}
        		pre = pre*10+(s1[i]-'0');
        	}
        	cout<<genString(res.second.first)<<" "<<genString(res.second.second)<<endl;
        }

#ifdef Fcdkbear
        double end = clock();
        fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
        return 0;
}
