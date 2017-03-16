#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
#define x first 
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;

int mas[200];
int sum;
int k;
map<int,vector<int>> a;

int main()
{
	freopen("my.in","rt",stdin);
	freopen("my.out","wt",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;i++) {
		cin>>k;
		for (int j=0;j<k;j++) {
			cin>>mas[j];
		}
		bool f=false;
		cout<<"Case #"<<i+1<<":"<<endl;
		for (int j=1;j<(1<<k);j++) {
			int sum=0;
			vector<int> subs;
			for (int t=0;t<k;t++) {
				if (j&(1<<t)) {
					sum+=mas[t];
					subs.push_back(mas[t]);
				}
			}
			if ((a[sum]).size()!=0) {
				for (int u=0;u<(a[sum]).size();u++) {
					cout<<(a[sum])[u];
					if (u!=(a[sum]).size()-1) {
						cout<<" ";
					}
				}
				cout<<endl;
				for (int u=0;u<subs.size();u++) {
					cout<<subs[u];
					if (u!=subs.size()-1) {
						cout<<" ";
					}
				}
				if (i!=t-1)
					cout<<endl;
				f=true;
				break;
			}
			else
				a[sum]=subs;
		}
		if (!f) {
			cout<<"Impossible"<<endl;
		}
	}
    return 0;
}