
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (long long i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (long long i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (long long i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
	for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back
#define MP make_pair

typedef long long LL;

int main() {
	long long t;
	cin >> t;
	REP(tc,1,t) {
		long long A,N;
		cin >> A >> N;
		vector<long long> V;
		FOR(i,0,N) {
			long long tmp;
			cin >> tmp;
			V.PB(tmp);
		}
		sort(V.begin(),V.end());
		long long st=A;
		long long mv=0;
		long long i=0;
		for (;i<N;i++) {
			if (V[i]<st) st+=V[i];
			else break;
		}
		//now start from i
		long long anot=100000000;
		if (i==N) cout << "Case #" << tc << ": " << mv << endl;
		else {
			for (;i<N;i++) {
				if (V[i]<st) st+=V[i];
				else {
					anot=min(anot,mv+N-i);
					long long cnt=0;
					long long pl=st;
					if (pl!=1) {
						while (pl<=V[i]) {
							pl+=(pl-1);
							cnt++;
						}
					}
					if (N-i>cnt && cnt!=0) {
						//add numbers
						st=pl;
						mv+=cnt;
						//i+=(N-i);
						st+=V[i];
					}
					else {
						mv+=(N-i);
						//erase the numbers
					}
				}
			}
			cout << "Case #" << tc << ": " << min(anot,mv) << endl;
		}
	}
	return 0;
}
