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

int x, y;
string ret;
int main(){
	int t;
	cin >> t;
	for(int tc=1;tc<=t;tc++){
		cin >> x >> y;
		ret="";
		int tx=0, ty=0, cnt=1;
		while(x!=tx){
			if(tx+cnt<=x){
				tx+=cnt;
				ret=ret+"E";
			}
			else if(tx-cnt>=x){
				tx-=cnt;
				ret=ret+"W";
			}
			else{
				tx+=cnt;
				ret=ret+"E";
			}
			cnt++;
		}
		while(y!=ty){
			if(ty+cnt<=y){
				ty+=cnt;
				ret=ret+"N";
			}
			else if(ty-cnt>=y){
				ty-=cnt;
				ret=ret+"S";
			}
			else{
				ty+=cnt;
				ret=ret+"N";
			}
			cnt++;
		}
		cout << "Case #" << tc << ": " << ret << endl;
	}

	return 0;
}

