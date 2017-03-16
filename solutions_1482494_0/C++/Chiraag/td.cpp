#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int star[1000];
bool comparefn (pair<int, int> i, pair<int, int> j) { return (i.second<j.second); }

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int N;
		cin >> N;
//		cout << "Case #" << t+1 << " N " << N << endl;
		int a[1000], b[1000];
		for(int i=0;i<1000;i++){
			star[i] = 0;
		}

		for(int n=0;n<N;n++){
			cin >> a[n] >> b[n];
		}

		int L=0;
		int rstars = 0;

		bool tb = false;
		do{
			bool done = false;

			bool alldone = true;
			for(int n=0; n<N; n++){
				if(star[n] != 2){
					alldone = false;
				}
			}
			if(alldone){
				break;
			}

			for(int i=0; i<N;i++){
				//Do 2star first & Try to get 2star
				if((b[i] <= rstars) && (star[i] == 0)){
					star[i] = 2;
					rstars += 2;
					done = true;
					L += 1;
//					cout << "0->2: " << i << endl;
					break;
				}
			}
			if(done) continue;
			for(int i=0; i<N;i++){
				//Do 2star first & get atleast 1star
				if((b[i] <= rstars) && (star[i] == 1)){
					star[i] = 2;
					rstars += 1;
					done = true;
					L += 1;
//					cout << "1->2: " << i << endl;
					break;
				}
			}
			if(done) continue;
			vector< pair<int, int> > candidates;
			for(int i=0; i<N;i++){
				//Do 1star as last resort & get atleast 1star
				if((a[i] <= rstars) && (star[i] == 0)){
					pair<int, int> addp = make_pair(i,b[i]);
					candidates.push_back(addp);
				}
			}
			int numCand = candidates.size();
			if(numCand > 0){
				sort (candidates.begin(), candidates.end(), comparefn);
//				for (vector<pair<int, int> >::iterator it=candidates.begin(); it!=candidates.end(); ++it)
//				    cout << " " << it->first << "(" << it->second << ")";
//				cout << endl;
				star[candidates[numCand-1].first] = 1;
				rstars += 1;
				done = true;
				L += 1;
//				cout << "0->1: " << candidates[numCand-1].first << endl;
			}
			if(done) continue;
			else tb = true;
		}while(!tb);

		bool rtb = false;
		for(int n=0; n<N; n++){
			if(star[n] != 2){
				rtb = true;
				break;
			}
		}
		if(rtb)
			cout << "Case #" << t+1 << ": Too Bad" << endl;
		else
			cout << "Case #" << t+1 << ": " << L << endl;
	}

	return 0;
}
