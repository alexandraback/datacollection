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

bool can(int index, double p) {
	double sc=mas[index]+sum*p;
	double allParts=p;
	for (int i=0;i<k;i++) {
		if (index==i) continue;
		if (mas[i]>sc+1E-11) continue;
		allParts+=(sc-mas[i]+1E-11)/sum;
	}
	if (allParts>1)
		return true;
	return false;
}

int main()
{
	freopen("my.in","rt",stdin);
	freopen("my.out","wt",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;i++) {
		cin>>k;
		sum=0;
		for (int j=0;j<k;j++) {
			cin>>mas[j];
		}

		for (int j=0;j<k;j++)
			sum+=mas[j];
		printf("Case #%d: ",i+1);
		for (int j=0;j<k;j++) {
			double l=0,r=1;
			while (r-l>1E-10) {
				double m=(r+l)/2;
				if (can(j,m))
					r=m;
				else l=m;
			}
			printf("%.6lf",l*100);
			if (j!=k-1) cout<<" ";
		}
		cout<<endl;
	}
    return 0;
}