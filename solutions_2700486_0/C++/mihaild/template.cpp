/*
 * Template for code jam - different includes and templates
 * Real task code is in the end
 * Mikhail Dektyarow <mihail.dektyarow@gmail.com>, 2009
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <sstream>
#include <numeric>
#include <stack>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

/*
 * DEFINES
 */
#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

/*
 * Types
 */
typedef pair<int,int> ipair;
typedef long long int int64;
typedef unsigned long long uint64;

/*
 * Different useful templates
 */
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<class T1, class T2>inline istream& operator>> (istream& s, pair<T1, T2> &p) {	return s >> p.first >> p.second;}
template<class T1, class T2>inline ostream& operator<< (ostream& s, const pair<T1, T2>p) {	return s << "(" << p.first << " " << p.second << ")";}
template<class T1>inline ostream& operator<< (ostream& s, const vector<T1> container) {
	for (typename vector<T1>::const_iterator i = container.begin(); i != container.end(); i++) s << *i << " ";
	return s;
}
template<class T1>inline istream& operator>> (istream&s, vector<T1> &container) {
	for (typename vector<T1>::iterator i = container.begin(); i != container.end(); i++) s >> *i;
	return s;
}
/*
 * Euclide's algorithm
 */
template<class T> inline T euclide(T a,T b,T &x,T &y)
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
/*
 * Factorizing a number
 */
template<class T> inline vector<pair<T,int> > factorize(T n)
{vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n)
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
//Searching prime numbers
//Using Sieve of Atkin (http://en.wikipedia.org/wiki/Sieve_of_Atkin)
vector<int> gen_primes(int limit) {
	int sqr_lim;
	int x2, y2;
	int n;
	vector<bool> is_prime(limit+1, false);
	sqr_lim = (int)sqrt((long double)limit);
	is_prime[2] = true;
	is_prime[3] = true;
	x2 = 0;
	for (int i = 1; i <= sqr_lim; i++) {
		x2 += 2 * i - 1;
		y2 = 0;
		for (int j = 1; j <= sqr_lim; j++) {
			y2 += 2 * j - 1;
			n = 4 * x2 + y2;
			if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
				is_prime[n] = !is_prime[n];
			n -= x2;
			if ((n <= limit) && (n % 12 == 7))
				is_prime[n] = !is_prime[n];
			n -= 2 * y2;
			if ((i > j) && (n <= limit) && (n % 12 == 11))
				is_prime[n] = !is_prime[n];
		}
	}
	for (int i = 5; i <= sqr_lim; i++) {
		if (is_prime[i]) {
			n = i * i;
			for (int j = n; j <= limit; j += n) {
				is_prime[j] = false;
			}
		}
	}
	int primes_count = 0;
	for (int i = 2; i < limit; i++) primes_count += is_prime[i];
	vector<int> primes;
	primes.reserve(primes_count);
	for (int i=2; i < limit; i++) if (is_prime[i]) primes.push_back(i);
	return primes;
}
//Translating string to different types
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}//NOTES:toString(
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
int64 toInt64(string s){int64 r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt64(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(

/*
 * Real code
 */

double calc_prob(int stones, int min_ok) {
    double p = 1.0;
    for (int i = 1; i <= stones; ++i) {
        p *= i;
        p /= 2.0;
        if (i <= min_ok) {
            p /= i;
        }
        else {
            p /= i - min_ok;
        }
    }
    return p;
}

int main(void) {
    cout.setf(ios::fixed);
    cout.precision(7);
	int __number_of_cases;
	cin >> __number_of_cases;
	REP(__number_of_case, __number_of_cases) {
        int N, x, y;
        cin >> N >> x >> y;
        if (x < 0) {
            x = -x;
        }
        if (y < 0) {
            y = -y;
        }
        int layer = 0; //currently builded
        int need = 0;
        double prob = 0.0;
        while (N >= need + layer * 4 + 1 && 2*layer <= x + y) {
            need += layer * 4 + 1;
            ++layer;
        }
        //cout << "need " << need << "; layer " << layer << '\n';
        if (2*layer > x + y) {//entire pyramid
            prob = 1.0;
        }
        else {
            if (2*layer < x + y) { //not enough
                prob = 0.0;
            }
            else {
                if (2*layer == y) {//top place
                    prob = 0.0;
                }
                else {
                    int max_side = layer * 2;
                    int stones = N - need;
                    int min_ok = y + 1;
                    //cout << "max sied: " << max_side << "; stones: " << stones << "; min ok: " << min_ok << "\n";
                    if (min_ok > stones) {
                        prob = 0.0;
                    }
                    else {
                        if (min_ok + max_side <= stones) {
                            prob = 1.0;
                        }
                        else {
                            double conf_prob = 0.0;
                            for (int i = 0; i <= max_side && i <= stones; ++i) {
                                if (stones - i <= max_side) {
                                    double p = calc_prob(stones, i);
                                    if (i >= min_ok) {
                                        prob += p;
                                    }
                                    conf_prob += p;
                                }
                            }
                            //cout << "conf prob: " << conf_prob << '\n';
                            prob += (1.0 - conf_prob) / 2.0;
                        }
                    }
                    //cout << "max side " << max_side << "; stones: " << stones << "; min ok: " << min_ok << '\n';
                }
            }
        }
        cout << "Case #" << __number_of_case+1 << ": " << prob << '\n';
        //int t = 0;
        //int a = 1;
        /*while (N >= t+a && t < (x+y)) {
            t += a;
            a += 4;
        }
        if (t == x + y) {
            cout << "Case #" << __number_of_case+1 << ": 1.0";
        }
        else {
            if (t + a < x + y) {
                cout << "Case #" << __number_of_case+1 << ": 0.0";
            }
            else {
                int max_side = (a - 1) / 4;
                int est = N - t;
                //if (y == max_side || y > est) {
                    //cout << "Case #" << __number_of_case+1 << ": 0.0";
                //}
                //else {
                    cout << N - t << " coins, need " << y << ", max " << max_side;
                //}
            }
        }*/
	}
}
