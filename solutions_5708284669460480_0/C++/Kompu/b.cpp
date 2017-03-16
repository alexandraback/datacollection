#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

vector<string> AllWords(string key, int s)
{
	VI choice(s, 0);
	vector<string> ret;
	bool loop = true;
	while(loop)
	{
		string str;
		str.resize(s);
		REP(x, s)
		{
			str[x] = key[choice[x]];
		}
		ret.push_back(str);
		REP(x, s)
		{
			choice[x]++;
			if(choice[x] < SIZE(key)) break;
			else
			{
				choice[x] = 0;
				if(x == s - 1) loop = false; 
			}
		}
	}
	return ret;
}

int KMP(string& str, string& wzo)
{
    #define KMPH(z) while(k > 0 && wzo[k] != z[q]) k = p[k]; \
    if(wzo[k] == z[q]) k++;
    int k = 0, q, m, ret = 0;
    VI p(SIZE(wzo) + 1);
    p[1] = 0;
    for(q = 1; wzo[q]; q++)
    {
        KMPH(wzo);
        p[q + 1] = k;
    }
    m = q;
    k = 0;
    for(q = 0; str[q]; q++)
    {
        KMPH(str);
        if(m == k)
        {
            ret++;
            k = p[k];
        }
    }
    return ret;
}

int main()
{
	int t;
	cin >> t;
	FOR(o, 1, t)
	{
		int k, l, s, maxi = 0;
		double sum = 0;
		string key, target;
		cin >> k >> l >> s;
		cin >> key >> target;

		auto ret = AllWords(key, s);
		for(auto it : ret)
		{
			int r = KMP(it, target);
			maxi = max(maxi, r);
			sum += r;
		}
		cout.precision(10);
		cout << "Case #" << o << ": " << maxi - (sum / SIZE(ret)) << endl;
	}
	return 0;
}