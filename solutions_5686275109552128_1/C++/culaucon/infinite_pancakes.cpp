#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int a[1010];

int main() {
	freopen("infinite_pancakes.in","r",stdin);
	freopen("infinite_pancakes.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		int d;
		cin>>d;
		for (int i=0;i<d;i++) cin>>a[i];
		sort(a,a+d);
		int ret=a[d-1];
		for (int i=1;i<=a[d-1];i++) {
			int c=0;
			for (int j=0;j<d;j++)
				if (a[j]>i) c+=(a[j]-1)/i;
			ret=min(ret,i+c);
		}
		cout<<"Case #"<<nt++<<": "<<ret<<endl;
	}
}
