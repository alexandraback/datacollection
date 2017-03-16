#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define gp(ans) {cout << "Case #" << ((test)+1) << ": " << (ans) << endl;}

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;

int main () {
  int test, T;
	
  cin >> T;
  REP (test, T) {
		int n,i,j;
		vi a,b;
		int lv1[1001] = {0};
		int lv2[1001] = {0};
		cin >> n;
		REP(i,n){
			int t,u;
			cin >> t >> u;
			a.push_back(t);
			b.push_back(u);
		}
		int st =0;
		int res=0;
		while(true){
			int mv = -1;
			int mi = -1;
			int complete = false;
			REP(i,n){
				if(lv2[i]==0 && b[i]<=st){
					// complete with lv2
					if(lv1[i]==0) st+=2;
					else st+=1;
					lv2[i] = 1;
					lv1[i] = 1;
					complete = true;
					res++;
					break;
				}
				if(lv1[i]==0 && a[i]<=st){
					if (b[i] > mv) {
						mi = i;
						mv = b[i];
					}
				}
			}
			if (!complete) {
				// complete with lv1
				if (mi != -1) {
					st += 1;
					lv1[mi] = 1;
					complete = true;
					res++;
				}
			}
			if(!complete){
				break;
			}
		}
		bool ok = true;
		REP(i,n){
			if(lv2[i]==0){
				ok = false;
				break;
			}
		}
		if(ok) {
			gp(res);
		} else {
			gp("Too Bad");
		}
  }
  return 0;
}

