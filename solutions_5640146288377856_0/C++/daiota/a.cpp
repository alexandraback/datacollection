/*
 * a.cpp
 *
 *  Created on: 2015/05/10
 *      Author: DO
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef pair<int,int> P;
typedef long long ll;

int main(void){

	int T;
	cin >> T;
	REP(t,T){

		int R,C,W;
		cin >> R >> C >> W;
		int ans=(C/W)*R+W-1;

		cout << "Case #" << t+1 << ": ";
		if(C%W==0) cout << ans << endl;
		else cout << ans+1 << endl;

	}

	return 0;
}



