#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > triple;

void gen(){
	freopen("testcase.txt", "w", stdout);
	exit(0);
}

int n, m, p, k;
int aa[3][3][2], bb[3][3][2], cc[3][3][2];

map<pair<int, triple>, vector<triple> > mp;

vector<triple> get(pair<int, triple> pr){
	if(mp.find(pr) == mp.end()){
		vector<pair<int, pair<int, int> > > arr;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				for(int q=0; q<p; q++){
					arr.push_back(make_pair(i, make_pair(j, q)));
				}
			}
		}

		for(int ii=0; ii<3; ii++){
			for(int jj=0; jj<3; jj++){
				aa[ii][jj][0] = bb[ii][jj][0] = cc[ii][jj][0] = 0;
				aa[ii][jj][1] = bb[ii][jj][1] = cc[ii][jj][1] = -1;
			}
		}

		int size = arr.size();

		int mx = 0;
		vector<pair<int, pair<int, int> > > res;

		for(int i=1; i<(1 << size); i++){
			int count = 0;
			bool fl = true;
			for(int j=0; j<size; j++){
				if(i & (1 << j)){
					count++;
					int a = arr[j].first, b = arr[j].second.first, c = arr[j].second.second;
					if(aa[a][b][1] == i){
						aa[a][b][0]++;
						if(aa[a][b][0] > k){
							fl = false;
							break;
						}
					}
					else{
						aa[a][b][0] = 1;
						aa[a][b][1] = i;
					}

					if(bb[a][c][1] == i){
						bb[a][c][0]++;
						if(bb[a][c][0] > k){
							fl = false;
							break;
						}
					}
					else{
						bb[a][c][0] = 1;
						bb[a][c][1] = i;
					}

					if(cc[b][c][1] == i){
						cc[b][c][0]++;
						if(cc[b][c][0] > k){
							fl = false;
							break;
						}
					}
					else{
						cc[b][c][0] = 1;
						cc[b][c][1] = i;
					}
				}
			}

			if(!fl)
				continue;

			if(count > mx){
				mx = count;
				vector<pair<int, pair<int, int> > > buf;
				for(int j=0; j<size; j++){
					if(i & (1 << j)){
						buf.push_back(arr[j]);
					}
				}
				res = buf;
			}
		}

		mp[pr] = res;
	}
	return mp[pr];
}

int main(){

#ifdef _CONSOLE
	freopen("C-small-attempt1.in", "r", stdin);
	//freopen("testcase.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int countTest;
	cin>>countTest;	
	for(int test = 1; test <= countTest; test++){
		
		cin>>n>>m>>p>>k;

		k = min(3, k);

		vector<triple> res = get(make_pair(k, make_pair(n, make_pair(m, p))));

		printf("Case #%d: %d\n", test, res.size());
		for(int i=0; i<res.size(); i++){
			cout<<(res[i].first + 1)<<" "<<(res[i].second.first + 1)<<" "<<(res[i].second.second + 1)<<"\n";
		}
		cerr<<test<<"\n";
	}
	
	return 0;
}

