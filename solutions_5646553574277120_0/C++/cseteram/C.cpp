#include<iostream>
#include<vector>

using namespace std;

void find_all_linear_combi(int i, vector<int> &Di, vector<bool> &Vi, int C, int sum) {
	if(sum>=Vi.size()) return;
	else if(i==Di.size()) {
		Vi[sum] = true;
		return;
	}
	
	for(int k=0 ; k<=C ; k++) {
		find_all_linear_combi(i+1, Di, Vi, C, sum+Di[i]*k);
	}
}

void find_allcombi(vector<int> &Di_r, int i, int k, vector<vector<int>> &Di3, vector<int> tmp) {
	if(i==Di_r.size() && k==0) {
		Di3.push_back(tmp);
		return;
	}
	else if(i==Di_r.size() && k>0) return;

	find_allcombi(Di_r,i+1,k,Di3,tmp);

	if(k>0) {
		tmp.push_back(Di_r[i]);
		find_allcombi(Di_r,i+1,k-1,Di3,tmp);
	}
}

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	cin>>T;

	for(int t=1 ; t<=T ; t++) {
		int C,D,V;
		cin>>C>>D>>V;

		vector<int> Di(D), Di_remain;
		for(int i=0 ; i<D ; i++) cin>>Di[i];
		for(int i=1 ; i<=V ; i++) {
			bool contains=false;
			for(int j=0 ; j<Di.size() ; j++) {
				if(i==Di[j]) { contains=true; break; }
			}

			if(contains) continue;
			else Di_remain.push_back(i);
		}

		vector<bool> Vi(V+1,false);
		int ans=0;

		while(true) {
			vector<vector<int>> Di3;
			vector<int> tmp;

			find_allcombi(Di_remain,0,ans,Di3,tmp);

			bool chk=true;
			for(int i=0 ; i<Di3.size() ; i++) {
				for(int ii=1 ; ii<=V ; ii++) Vi[ii]=false;

				vector<int> Di2(Di.begin(), Di.end());
				for(int j=0 ; j<Di3[i].size() ; j++) Di2.push_back(Di3[i][j]);

				find_all_linear_combi(0,Di2,Vi,C,0);

				chk = true;
				for(int k=1 ; k<=V ; k++) chk = chk & Vi[k];

				if(chk) break;
			}

			if(chk) break;

			ans++;
		}
		
		cout<<"Case #"<<t<<": ";
		cout<<ans<<"\n";
	}


	return 0;
}