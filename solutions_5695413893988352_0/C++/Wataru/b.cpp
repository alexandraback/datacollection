#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;

string a, b;

int n;

void Load()
{
	cin >> a >> b;
	n = a.length();
}

long long dp[20][3]; //0 <, 1 =, 2 >
int was[20][3];
int la[20][3];
int lb[20][3];
int prf[20][3];
long long dpa[20][3];
long long dpb[20][3];

long long MAXX = 100000000000;

long long f(int l, int fl) {
//	cerr << "f " << l << ' ' << fl << "\n";
	if (l == 0) {
		if (fl == 1) return 0;
//		cerr << "Botva\n";
		if (fl == 0) return +MAXX;
		if (fl == 2) return -MAXX;
	}
	if (was[l][fl] != 0) return dp[l][fl];

	int c1, c2;
	int c1m, c2m;
	if (a[l-1] == '?') {
		c1 = 0; c1m = 9;
	}  else { 
		c1 = c1m = (int)(a[l-1] - '0'); 
	}

	if (b[l-1] == '?') {
		c2 = 0; c2m = 9;
	}  else { 
		c2 = c2m = (int)(b[l-1] - '0'); 
	}
	long long cur;
    long long ca, cb;	
	long long res = -MAXX;
	long long ra = 0;
	long long rb = 0;
	bool st = false;
	
    int c2i = c2;

	for (c1 = c1; c1 <= c1m; c1++) {
		for (c2 = c2i; c2 <= c2m; c2++) {
			if (fl == 0) {
				cur = f(l-1, 0);
				if (cur < 0) {
					cur = 10*cur + c1 - c2;
					ca = dpa[l-1][0]*10 + c1;
					cb = dpb[l-1][0]*10 + c2;
					if (!st || res < cur || (res == cur && (ca < ra || (ca == ra && cb < rb)))) {
						res = cur;
						st = true;
						ra = ca;
						rb = cb;
						la[l][fl] = c1;
						lb[l][fl] = c2;
						prf[l][fl] = 0;
					}
				}
				if (c1 < c2) {
					cur = f(l-1, 1);
					ca = dpa[l-1][1]*10 + c1;
					cb = dpb[l-1][1]*10 + c2;
					if (cur == 0) {
						cur = c1-c2;
						if (!st || res < cur || (res == cur && (ca < ra || (ca == ra && cb < rb)))) {
							st = true;						
							res = cur;
							la[l][fl] = c1;
							lb[l][fl] = c2;
							ra = ca;
							rb = cb;					
							prf[l][fl] = 1;
						}
					}				
				}
			} else if (fl == 1 && c1 == c2) {
				cur = f(l-1, 1);
				ca = dpa[l-1][1]*10 + c1;
				cb = dpb[l-1][1]*10 + c2;
                if (cur == 0 && (!st || (res == cur && (ca < ra || (ca == ra && cb < rb))))) {
					res = 0;
					la[l][fl] = c1;
					lb[l][fl] = c1;
					ra = ca;
					rb = cb;				
					prf[l][fl] = 1;
					st = true;
				}
			} else if (fl == 2) {
				cur = f(l-1, 2);
				ca = dpa[l-1][2]*10 + c1;
				cb = dpb[l-1][2]*10 + c2;
				if (cur > 0) { 
					cur = 10*cur + c1 - c2;
					if (!st || res > cur || (res == cur && (ca < ra || (ca == ra && cb < rb)))) {
						res = cur;
						st = true;
						la[l][fl] = c1;
						lb[l][fl] = c2;
						ra = ca;
						rb = cb;
						prf[l][fl] = 2;
					}
				}
				if (c1 > c2) {
					cur = f(l-1, 1);
					ca = dpa[l-1][1]*10 + c1;
					cb = dpb[l-1][1]*10 + c2;
					if (cur == 0) {
						cur = c1-c2;
						if (!st || res > cur || (res == cur && (ca < ra || (ca == ra && cb < rb)))) {
							st = true;						
							res = cur;
							la[l][fl] = c1;
							lb[l][fl] = c2;
							ra = ca;
							rb = cb;
							prf[l][fl] = 1;
						}
					}				
				}
			}
		}
	}
	if (!st) {
		la[l][fl] = -1;
		lb[l][fl] = -1;			
		prf[l][fl] = 1;
	    dpa[l][fl] = dpb[l][fl] = -1;
		if (fl == 1) {
			res = MAXX;
		} else if (fl == 0) {
			res = MAXX;
		} else if (fl == 2) {
			res = -MAXX;
		}
	}
	dp[l][fl] = res;
	dpa[l][fl] = ra;
	dpb[l][fl] = rb;
	was[l][fl] = 1;
	return res;
}


string a1, a2;

void Restore(int l, int fl) {
	if (l == 0) return;
	while (l > 0) {
		a1[l-1] = la[l][fl]+'0';
		a2[l-1] = lb[l][fl]+'0';
		fl = prf[l][fl];
		l--;
	}
}


long long Atoi(string s) {
    long long ans = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        ans = 10 * ans + ((int)(s[i]) - (int)'0');
    }
    return ans;
}


long long aa1, aa2;
long long cdif = -1;

void Gen(int l, long long i1, long long i2) {
	if (l == n) {
		long long df = abs(i2 - i1);
		if (cdif < 0 || (cdif > df || (cdif == df && (i1 < aa1 || (i1 == aa1 && i2 < aa2))))) {
			cdif = df;
			aa1 = i1;
			aa2 = i2;
		}
		return;
	}
	int c1, c2;
	int c1m, c2m;
	if (a[l] == '?') {
		c1 = 0; c1m = 9;
	}  else { 
		c1 = c1m = (int)(a[l] - '0'); 
	}

	if (b[l] == '?') {
		c2 = 0; c2m = 9;
	}  else { 
		c2 = c2m = (int)(b[l] - '0'); 
	}
    int c2i = c2;
	for (c1 = c1; c1 <= c1m; c1++) {
		for (c2 = c2i; c2 <= c2m; c2++) {
			Gen(l+1, 10*i1 + c1, 10*i2+c2);
		}
	}

}

void Dumb(long long ans1, long long ans2) {
//	return;
	cdif = -1;
	Gen(0, 0, 0);
	if (aa1 != ans1 || aa2 != ans2) {
		cerr << "!!!!!\n" << a << ' ' << b << "\n";
		cerr << "want: " <<aa1 << ' ' << aa2 << "\n";
		cerr << "got: " << ans1 << ' ' << ans2 << "\n";
	}
}

 
string pad(int n, long long i1) {
	ostringstream os;
	os << i1;
	string s = os.str();
	int i = n - (int)s.length();
	while (i > 0) {
		s = '0'+s;
		i--;
	}
	return s;
}

void Solve()
{
	memset(was, 0, sizeof(was));
	long long ans1 = f(n, 0);
	long long ans2 = f(n, 1);
	long long ans3 = f(n, 2);
	a1.resize(n);
	a2.resize(n);
	if (ans2 == 0) {
		Restore(n, 1);
//		cerr << ans2 << "\n";
		ans1= ans2;
	} else if (ans1 < 0 && (ans3 < 0 || abs(ans1) < abs(ans3))) {
		Restore(n, 0);
//		cerr << ans1 << "\n";
	} else if (ans3 > 0 && (ans1 > 0 || abs(ans1) > abs(ans3))) {
		Restore(n, 2);
//		cerr << ans3 << "\n";
		ans1 = ans3;
	} else {
		//cerr << "Botva1\n";
        long long i1, i2, i3, i4;
        Restore(n, 0);
        i1 = Atoi(a1); i2 = Atoi(a2);
        if (i1 - i2 != ans1) {
            	cerr << "botva in sum1\n";
        }
        Restore(n, 2);
        i3 = Atoi(a1); i4 = Atoi(a2);
        if (i3 - i4 != ans3) {
            	cerr << "botva in sum1\n";
        }
        if (i3 < i1 || (i3 == i1 && i4 < i2)) {
            i1 = i3;
            i2 = i4;
        }
        cout << pad(n, i1) << ' ' << pad(n, i2) << "\n";
        Dumb(i1, i2);
        return;
	}
	long long i1, i2;
    i1 = Atoi(a1); i2 = Atoi(a2);	
    if (i1 - i2 != ans1) {
    	cerr << "botva in sum\n";
    }
	cout << a1 << ' ' << a2 << "\n";
	Dumb(i1, i2);
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
