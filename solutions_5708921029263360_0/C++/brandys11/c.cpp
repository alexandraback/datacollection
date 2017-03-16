#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	int J, P, S, K;
	cin >> J >> P >> S >> K;

	set<ll> R;
	map<pair<int,int>, int> JP, JS, PS;

	for(int j=1; j <= J; j++) {
		for(int p=1; p <= P; p++) {
			for(int s=1; s <= S; s++) {
				JP[make_pair(j,p)] = 0;
				JS[make_pair(j,s)] = 0;
				PS[make_pair(p,s)] = 0;
			}
		}
	}
	int size = -1;
	while(size != R.size()) {
		size = R.size();

		for(int i=0; i < J * P * S; i++) {
			if(R.find(i) != R.end()) continue;
			int j = i%J + 1;
			int p = (i/J)%P + 1;
			int s = ((i/J)/P)%S + 1;

			if(JP[make_pair(j,p)] + 1 > K) continue;
			if(JS[make_pair(j,s)] + 1 > K) continue;
			if(PS[make_pair(p,s)] + 1 > K) continue;

			JP[make_pair(j,p)]++;
			JS[make_pair(j,s)]++;
			PS[make_pair(p,s)]++;

			R.insert(i); 
			break;
		}

		int is_new = false;
		for(int i=0; i < J * P * S; i++) {
			if(R.find(i) != R.end()) continue;
			int j1 = i%J + 1;
			int p1 = (i/J)%P + 1;
			int s1 = ((i/J)/P)%S + 1;

			JP[make_pair(j1,p1)]++;
			JS[make_pair(j1,s1)]++;
			PS[make_pair(p1,s1)]++;

			for(int ii=0; ii < J * P * S; ii++) {
				if(R.find(ii) != R.end()) continue;

				int j2 = ii%J + 1;
				int p2 = (ii/J)%P + 1;
				int s2 = ((ii/J)/P)%S + 1;

				JP[make_pair(j2,p2)]++;
				JS[make_pair(j2,s2)]++;
				PS[make_pair(p2,s2)]++;

				int nove = -1;
				for(int a: R) {
					int j3 = a%J + 1;
					int p3 = (a/J)%P + 1;
					int s3 = ((a/J)/P)%S + 1;

					JP[make_pair(j3,p3)]--;
					JS[make_pair(j3,s3)]--;
					PS[make_pair(p3,s3)]--;

					int is_ok = true;
					if(JP[make_pair(j1,p1)] > K) is_ok = false;
					if(JS[make_pair(j1,s1)] > K) is_ok = false;
					if(PS[make_pair(p1,s1)] > K) is_ok = false;

					if(JP[make_pair(j2,p2)] > K) is_ok = false;
					if(JS[make_pair(j2,s2)] > K) is_ok = false;
					if(PS[make_pair(p2,s2)] > K) is_ok = false;

					if(is_ok) {
						is_new = true;
						nove = a;
						break;
					} 
					JP[make_pair(j3,p3)]++;
					JS[make_pair(j3,s3)]++;
					PS[make_pair(p3,s3)]++;
				}
				if(is_new) { 
					R.erase(nove);
					R.insert(i);
					R.insert(ii);
					break; 
				}
				
				JP[make_pair(j2,p2)]--;
				JS[make_pair(j2,s2)]--;
				PS[make_pair(p2,s2)]--;
			}
			if(is_new) break;
			JP[make_pair(j1,p1)]--;
			JS[make_pair(j1,s1)]--;
			PS[make_pair(p1,s1)]--;
		}
	}

	cout << R.size() << endl;
	for(auto i: R) {
		int j = i%J + 1;
		int p = (i/J)%P + 1;
		int s = ((i/J)/P)%S + 1;
		cout << j << " " << p << " " << s << endl;
	}
}

int main(void) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}