#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >>t;

	for (int k = 1 ; k <= t ; k ++){
		int n, m;
		cin >>n >>m;
		long long lim_n[n], type_n[n], lim_m[m], type_m[m];

		for (int i = 0 ; i < n ; i ++)
			cin >>lim_n[i] >>type_n[i];

		for (int i = 0 ; i < m ; i ++)
			cin >>lim_m[i] >>type_m[i];

		set< pair<long long, pair<long long, pair<long long, pair<long long, long long> > > > > unique_set;

		queue<long long> post_n;
		queue<long long> val_n;
		queue<long long> post_m;
		queue<long long> val_m;
		queue<long long> score;
		long long maks = -1;

		post_n.push(0);
		val_n.push(0);
		post_m.push(0);
		val_m.push(0);
		score.push(0);
		unique_set.insert(make_pair(0, make_pair(0, make_pair(0, make_pair(0, 0)))));

		while(!score.empty()){
			long long currPostN = post_n.front(); post_n.pop();
			long long currValN = val_n.front(); val_n.pop();
			long long currPostM = post_m.front(); post_m.pop();
			long long currValM = val_m.front(); val_m.pop();
			long long currScore = score.front(); score.pop();
			//cout <<currPostN <<" " <<currValN <<" " <<currPostM <<" " <<currValM <<" " <<currScore <<endl;

			if (currScore > maks)
				maks = currScore;

			if (currPostN == n-1 && lim_n[currPostN]==currValN) continue;

			//buang n
			if (currPostN+1 < n){
				if ( unique_set.count( make_pair(currPostN+1, make_pair(0, make_pair(currPostM, make_pair(currValM, currScore)))) ) == 0){
					post_n.push(currPostN+1);
					val_n.push(0);
					post_m.push(currPostM);
					val_m.push(currValM);
					score.push(currScore);
					unique_set.insert(make_pair(currPostN+1, make_pair(0, make_pair(currPostM, make_pair(currValM, currScore)))));
				}
			}

			//buang m
			if (currPostM+1 < m){
				if ( unique_set.count( make_pair(currPostN, make_pair(currValN, make_pair(currPostM+1, make_pair(0, currScore)))) ) == 0){
					post_n.push(currPostN);
					val_n.push(currValN);
					post_m.push(currPostM+1);
					val_m.push(0);
					score.push(currScore);
					unique_set.insert(make_pair(currPostN, make_pair(currValN, make_pair(currPostM+1, make_pair(0, currScore)))));
				}
			}

			//makan sebanyak-banyaknya kalo bisa
			if (type_m[currPostM] == type_n[currPostN]){
				int sisaM = lim_m[currPostM] - currValM;
				int sisaN = lim_n[currPostN] - currValN;
				if (sisaM > 0 && sisaN > 0){
					int makan = min(sisaM, sisaN);
					if ( unique_set.count( make_pair(currPostN, make_pair(currValN+makan, make_pair(currPostM, make_pair(currValM+makan, currScore+makan)))) ) == 0 ){
						post_n.push(currPostN);
						val_n.push(currValN + makan);
						post_m.push(currPostM);
						val_m.push(currValM + makan);
						score.push(currScore + makan);
						unique_set.insert(make_pair(currPostN, make_pair(currValN+makan, make_pair(currPostM, make_pair(currValM+makan, currScore+makan)))));
					}
				}
			}
		}

		cout <<"Case #" <<k <<": " <<maks <<endl;
	}

	return 0;
}
