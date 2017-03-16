/*
 * c.cpp
 *
 *  Created on: 2015/05/05
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

int pre[110];
int v[50];

int main(void){

	int T;
	cin >> T;
	REP(t,T){

		int C,D,V;
		cin >> C >> D >> V;
		int i,j;
		for(i=1;i<=D;i++) cin >> pre[i];

		for(i=1;i<(1<<D);i++){
			int a=0;
			for(j=0;j<D;j++){
				if(i&(i<<j)){
					a+=pre[j+1];
				}
			}

			v[a]=1;

		}

		int ans=0;
		for(i=1;i<=D;i++){
			if(v[i]==0) ans++;
		}


		cout << "Case #" << t+1 << ": ";
		cout << ans << endl;

	}

	return 0;
}



