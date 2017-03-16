#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define repeat(t) for (int asdfg=0; asdfg < (t); asdfg++)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int w,n;
int a[110];

bool solve(int x) {
	int cnt;
	if (w==1) return false;
	for (int k=0; k<=x; k++) {
		cnt=k;
		for (int s=w,i=0; i<n-k && cnt <= x; i++) {
			while (s<=a[i] && s!=1) {
				cnt++;
				s+=s-1;
			}
			s+=a[i];
		}
		if (cnt <= x) return true;
	}
	return false;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("a2.out","w",stdout);

	int cas;
	cin >> cas;
	for (int T=1; T<=cas; T++) {
		cin >> w >> n;
		for (int  i=0; i<n; i++) cin>>a[i];
		sort(a,a+n);
		int l=0,r=n,mid,ans=n;
		while (l<=r) {
			mid=(l+r)/2;
			if (solve(mid)) {
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
			// printf("%d %d\n",l,r);
		}
		cout << "Case #" << T << ": " << ans << endl;
	}
	return 0;
}
