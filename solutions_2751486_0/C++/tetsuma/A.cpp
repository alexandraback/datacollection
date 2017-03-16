#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
#define INF (1<<29)

int main(){
	int t, n;
	string s;
	cin >> t;
	for(int tc=1;tc<=t;tc++){
		cin >> s >> n;
		int m=s.length(), ret=0;
		for(int i=0;i<m;i++){
			int cnt=0, tmp=0;
			string x="";
			for(int j=i;j<m;j++){
				x+=s[j];
				if(s[j]!='a'&&s[j]!='i'&&s[j]!='u'&&s[j]!='e'&&s[j]!='o')cnt++;
				else cnt=0;
				tmp=max(tmp,cnt);
				if(tmp>=n)ret++;
			}
		}
		cout << "Case #" << tc << ": " << ret << endl;
	}

	return 0;
}

