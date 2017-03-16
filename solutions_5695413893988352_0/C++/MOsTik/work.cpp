#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;
#ifdef Nameless
#define FILES freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else
#define FILES //freopen("input.txt","r",stdin); freopen("output.txt","r",stdin);
#endif

typedef long long Long;
typedef long double Double;

#define left awefawef


const int Q = '?'-'0';
int n;
int a[21],b[21];
int x[21],y[21];
int X[21],Y[21];
Long diff;
Long step[21];
Long res;

void rec(int v) {
	if (v==n) {
		if (abs(diff)<res){
			res = abs(diff);
			for (int i = 0 ;i < n; ++i) {
				X[i] = x[i];
				Y[i] = y[i];
			}
		}
		else if (abs(diff)==res) {
			int q = 0;
			for (int i = 0; i < n; ++i) {
				if (X[i]>x[i]) {
					q = 1;
					break;
				}
				if (X[i]<x[i]) {
					q = -1;
					break;
				}
			}

			if (q==0) {
				for (int i = 0; i < n; ++i) {
					if (Y[i]>y[i]) {
						q = 1;
						break;
					}
					if (Y[i]<y[i]) {
						q = -1;
						break;
					}
				}
			}

			if (q==1) {
				for (int i = 0 ;i < n; ++i) {
					X[i] = x[i];
					Y[i] = y[i];
				}
			}

		}
		return;
	}
	if (a[v] == Q && b[v] == Q) {
		x[v] = 0;
		y[v] = 0;
		rec(v+1);

		Long bestDiff = 9000000000000000000ll;
/*
		for (int i = 0;i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				x[v] = i;
				y[v] = j;
				diff += (x[v]-y[v])*step[n-v];
				if (abs(diff)<bestDiff) {
					bestDiff = abs(diff);
				}
				diff -= (x[v]-y[v])*step[n-v];
			}
		}**/

		for (int i = 0;i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				x[v] = i;
				y[v] = j;
				diff += (x[v]-y[v])*step[n-v];
				//if (abs(diff)==bestDiff || v==0)
					rec(v+1);
				diff -= (x[v]-y[v])*step[n-v];
			}
		}

		return;
	}
	if (a[v] != Q && b[v] != Q) {
		x[v] = a[v];
		y[v] = b[v];

		diff += (x[v]-y[v])*step[n-v];
		//cout << diff << x[v] << " " << y[v] << endl;
		rec(v+1);
		diff -= (x[v]-y[v])*step[n-v];
		return;
	}
	if (a[v] == Q) {
		int L = 0;
		int R = 9;
		for (int j = L; j <= R; ++j) {
			x[v] = j;
			y[v] = b[v];
			diff += (x[v]-y[v])*step[n-v];
			rec(v+1);
			diff -= (x[v]-y[v])*step[n-v];
		}
	}
	else {
		int L = 0;
		int R = 9;
		for (int j = L; j <= R; ++j) {
			x[v] = a[v];
			y[v] = j;
			diff += (x[v]-y[v])*step[n-v];
			rec(v+1);
			diff -= (x[v]-y[v])*step[n-v];
		}
	}
}

void solve(int test = 0)
{
	cout << "Case #" << test+1  << ": ";
	res = 9000000000000100000l;
	//cout << res << endl;
	string A,B;
	cin >> A >> B;
	n = A.length();
	for (int i = 0;i < n; ++i) {
		a[i] = A[i]-'0';
		b[i] = B[i]-'0';
	}
	rec(0);

	//cout << res << endl;
	for (int i = 0; i < n; ++i) {
		cout << X[i];
	}
	cout << " " ;
	for (int i = 0; i < n; ++i) {
		cout << Y[i];
	}
	cout << endl;

}

int main(){
    FILES;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
//    solve();
    int test;
    cin >> test;
    step[0] = 1;
    for (int i = 1;i  <= 18; ++i)
    	step[i] = step[i-1]*10ll;

    for (int i = 0; i < test; ++i) {
        solve(i);
    }
    return 0;
}
