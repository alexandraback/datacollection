#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <complex>
#include <stack>
#include <cctype>
#include "assert.h"
#include <cstdlib>
#include <iostream>

#define PB push_back
#define MP make_pair
#define FR(i,n) for( long long i = 0; i < n; i ++ )
#define FOR(i,a,n) for(long long i = a; i < n; i ++)
#define FREACH(it,v) for( typeof(v.end()) it = v.begin(); it != v.end(); it ++ )
#define EPS 1e-7
using namespace std;
typedef long long ll;
typedef long double ld;


int S[50], P[50];
const int MAX_SM=6;
bool vis[1<<MAX_SM];
bool pos[1<<MAX_SM];
bool next_pos[(1<<MAX_SM)];


bool overlap(int i, int j, ld t) {
	
	ld front_i=ld(P[i])+5.0+t*ld(S[i]);
	ld back_j=ld(P[j])+t*ld(S[j]);
	ld front_j=ld(P[j])+5.0+t*ld(S[j]);
	ld back_i=ld(P[i])+t*ld(S[i]);
//	cout << front_i << " " << back_j << " " << front_j << " " << back_i << endl;
//	cout << "returning overlap between " << i << " and " << j << " is " << !(back_j < front_i || back_i < front_j) << endl;
	return( !(front_j < back_i + EPS|| front_i < back_j + EPS));
}

bool touching(int i, int j, ld t) {
	ld front_i=ld(P[i])+5.0+t*ld(S[i]);
	ld back_j=ld(P[j])+t*ld(S[j]);
	ld front_j=ld(P[j])+5.0+t*ld(S[j]);
	ld back_i=ld(P[i])+t*ld(S[i]);
	//cout << front_i << " " << back_j << " " << front_j << " " << back_i << endl;
	//cout << "returning touching between " << i << " and " << j << " is " << ( abs(back_j - front_i) < EPS || abs(back_i - front_j) < EPS) << " " << fabs(back_j - front_i) << " " << fabs(back_i - front_j) <<  endl;

	return( (fabs(back_j - front_i) < EPS) || (fabs(back_i - front_j) < EPS));
}


int main() {
	int T;
	scanf("%d",&T);
	FR(i,T) {
		cout << "Case #" << i+1 << ": ";
		vector<ld> lookat;
		
		memset(pos,0,sizeof(pos));
		memset(next_pos,0,sizeof(pos));
		
		int N;
		scanf("%d",&N);
		int init=0;
		FR(i,N) {
			char c;
			cin >> c;
			if(c=='L') init|=(1<<i);
			scanf("%d %d",&S[i],&P[i]);
		}
		
		ld t;
		FR(i,N) {
			FOR(j,i+1,N) {
				if(S[i]>S[j]) {
					t=(ld(P[i])+5.0-ld(P[j]))/(ld(S[j])-ld(S[i]));
					if(t>EPS) lookat.PB(t);
					t=(ld(P[i])-ld(P[j])-5.0)/(ld(S[j])-ld(S[i]));
					if(t>EPS) lookat.PB(t);
				}
				if(S[j]>S[i]) {
					t=(ld(P[j])+5.0-ld(P[i]))/(ld(S[i])-ld(S[j]));
					if(t>EPS) lookat.PB(t);
					t=(ld(P[j])-ld(P[i])-5.0)/(ld(S[i])-ld(S[j]));
					if(t>EPS) lookat.PB(t);
				}				
			}
		}
		lookat.PB(0.0);
		sort(lookat.begin(),lookat.end());
		next_pos[init]=1;
		FR(i,lookat.size()) {
			if(i>0&&lookat[i]<lookat[i-1]+EPS) continue;
			// skip similar times
			int tt=i;
			queue<int> poss;
			FR(i,(1<<N)) {
				if(next_pos[i]) {
					poss.push(i);
				}				
			}
			memset(vis,0,sizeof(vis));
			memset(next_pos,0,sizeof(next_pos));
			
			bool advanced=false;
			while(!poss.empty()) {
				int a = poss.front();
				poss.pop();
				if(vis[a]) continue;
				vis[a]=true;
		//		cout << "checking configuration " << a << endl;
				FR(i,N) {
					bool left_i=(a&(1<<i));
					FOR(j,i+1,N) {
						bool left_j=(a&(1<<j));						
						if(left_i==left_j&&overlap(i,j,lookat[tt])) {
						//	cout << "overlap detected between " << i << " " << j << endl;
							goto NXT;
						}
						
					}
				}
								
				// do one lane change, if possible
				FR(i,N) {
					bool left_i=(a&(1<<i));
					FR(j,N) {
						if(i==j) continue;
						bool left_j=(a&(1<<j));						
						if(left_i!=left_j&&overlap(i,j,lookat[tt])) goto NXTCAR;
					}
					if(left_i) {
						poss.push(a-(1<<i));								
					} else {
						poss.push(a|(1<<i));								
					}
				NXTCAR:;
				}
				
				FR(i,N) {
					bool left_i=(a&(1<<i));
					FOR(j,i+1,N) {
						bool left_j=(a&(1<<j));						
						if(left_i==left_j&&touching(i,j,lookat[tt])) {
							if((S[i]<S[j]&&P[i]>P[j])||(S[i]>S[j]&&P[i]<P[j])) {
						//		cout << "touching detected between " << i << " " << j << endl;
								goto NXT;
							}
						}
					}
				}
				advanced=true;
				next_pos[a]=1;				
			NXT:;
			}

			if(!advanced) {
				cout.setf(ios::fixed);
				cout.precision(10);
				cout << lookat[i] << endl;
				goto FCC;
			}
			
		}
		
		cout << "Possible" << endl;
	FCC:;
	}
	
	
	
}

