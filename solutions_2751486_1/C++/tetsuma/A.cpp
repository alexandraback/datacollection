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
		int m=s.length(), bef=0, cnt=0;
		long long ret=0;
		for(int i=0;i<m;i++){
			if(s[i]!='a'&&s[i]!='i'&&s[i]!='u'&&s[i]!='e'&&s[i]!='o')cnt++;
			else cnt=0;
			if(cnt>=n){
				long long tail=m-i;
				long long head=i-n+2-bef;
				ret+=head*tail;
				bef=i-n+2;
			}
		}
		cout << "Case #" << tc << ": " << ret << endl;
	}

	return 0;
}

