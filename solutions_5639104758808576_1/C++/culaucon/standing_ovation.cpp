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

int main() {
	freopen("standing_ovation.in","r",stdin);
	freopen("standing_ovation.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		int smax;
		string s;
		cin>>smax>>s;
		int k=s[0]-'0', ret=0;
		for (int i=1;i<=smax;i++) {
			if (i>k) {
				int tmp=i-k;
				k+=tmp;
				ret+=tmp;
			}
			k+=s[i]-'0';
		}
		cout<<"Case #"<<nt++<<": "<<ret<<endl;
	}
}
