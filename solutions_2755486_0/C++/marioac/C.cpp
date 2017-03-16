//#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int A[1000];
int dummy[1000];
map<int,vector<int> > tribemap; 
int ddi[10], dpi[10], dsi[10];
//map from tribe to curwest,cureast, curstrength
vector<pair<int, int > > daytribe;


ifstream cin("C-small-attempt0.in");
ofstream cout("C-small.out");
int main() {
int T;

cin >> T;
for (int tt=1; tt<=T; tt++) {
daytribe.clear(); tribemap.clear();
int N;
cin >> N; for (int i=0; i<1000; i++) { A[i] = 0; dummy[i] = 0; }
for (int i=0; i<N; i++) {
int di,ni,wi,ei,si; cin >> di >> ni >> wi >> ei >> si >> ddi[i] >> dpi[i] >> dsi[i];
vector<int> ztrb; 
ztrb.push_back(2*wi+500); ztrb.push_back(2*ei+500); ztrb.push_back(si);
tribemap[i] = ztrb;
for (int j=0; j<ni; j++) {
	daytribe.push_back(make_pair(di+ddi[i]*j,i));
}

}
sort(daytribe.begin(), daytribe.end());
int suc = 0;
for (int i=0; i<daytribe.size(); i++) {
	pair<int,int> ret = daytribe[i];
	int wi = tribemap[ret.second][0]; int ei = tribemap[ret.second][1]; int si = tribemap[ret.second][2];
	for (int j=wi; j<=ei; j++) if (A[j] < si) { suc++; for (int k=wi; k<=ei; k++) dummy[k] = max(dummy[k],si); break; }
	tribemap[ret.second][0] += 2*dpi[ret.second]; tribemap[ret.second][1] += 2*dpi[ret.second]; tribemap[ret.second][2] += dsi[ret.second];

	if (i!=daytribe.size()-1) {
		if (daytribe[i].first != daytribe[i+1].first) {
			//update A
			for (int i=0; i<1000; i++) A[i] = dummy[i];
		}
	}
}

cout<<"Case #" << tt <<": " << suc <<endl;
}

return 0;
}

