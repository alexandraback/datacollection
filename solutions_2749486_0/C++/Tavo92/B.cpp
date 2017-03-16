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
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define forn(a, n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a, all) for(typeof((all).begin()) a = (all).begin(); a != (all).end(); ++a)

#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define dforsn(a,s,n) for(int a = (n)-1; a>=(s); --a)
#define dforall(a, all) for(typeof((all).rbegin()) a = (all).rbegin(); a != (all).rend(); ++a)

#define contains(mask, bit) ((mask & (1LL<<bit)) != 0LL)

typedef long long tint;

const int DX[4] = {0,0,1,-1};
const int DY[4] = {1,-1,0,0};
const string dir = "NSEW";

int T, xf, yf;

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);

	cin >> T;
	
	forn(p,T){
		cin >> xf >> yf;
		string ret;
		map<pair<int,int>, string> q, qn;
		q[make_pair(0,0)] = "";
		
		/*for(int jump = 1; ; ++jump){
			bool fin = false;
			forall(i,q){
				pair<int,int> pii = i->first;
				if(pii.first == xf && pii.second == xf){
					printf("Case #%i: ", p+1); cout << i->second << endl;
					fin = true;
					break;
				}
				
				forn(k,4){
					int x = pii.first+DX[k]*jump, y = pii.second+DY[k]*jump;
					pair<int,int> pr = make_pair(x,y);
					qn[pr] = i->second+dir[k];
				}
			}
			
			if(fin) break;
			q = qn;
			qn.clear();
		}
	}*/
	
	for(int jump = 1; ; jump+=4){
			string ret;
			bool fin = false;
			forall(i,q){
				pair<int,int> pii = i->first;
				vector<int> dk; dk.push_back(0); dk.push_back(1); dk.push_back(2); dk.push_back(3);
				do{
					int x = pii.first, y = pii.second;
					string sxy = i->second;
					forn(k, 4){
						x += DX[dk[k]]*(jump+k);
						y += DY[dk[k]]*(jump+k);
						sxy += dir[dk[k]];
						if(x == xf && y == yf){
							
							if(!fin || ret.size() > sxy.size())
								ret = sxy;
							fin = true;
						}
					}
					qn[make_pair(x,y)] = sxy;
				}while(next_permutation(dk.begin(), dk.end()));
			}
			
			if(fin){
				printf("Case #%i: ", p+1); cout << ret << endl;
				break;
			}
			q = qn;
			qn.clear();
		}
	}
	
	return 0;
}
