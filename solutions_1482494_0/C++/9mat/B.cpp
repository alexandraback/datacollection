#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>

#define FOR(i,n) for(int i = 0, n_ = (n); i<n_; i++)

using namespace std;

typedef pair<int,int> PRI;

int mincount(int N, vector<PRI> a, vector<PRI> b){
	int count = 0, i = 0, j = 0, q = 0;
	int m = a.size(), n = b.size();
	vector<bool> mark(N,false);

	while(i<m){
		if(q >= a[i].first){
			if(mark[a[i].second]) q++; else q+=2;
			i++; count++;
		} else{
			if(j<n && q>=b[j].first){
				mark[b[j].second]=true;
				count++; q++;
			}
			else return -1;
		}
	}

	return count;
}

bool nextset(vector<bool> &g){
	int i=0;
	while(i<g.size() && g[i]) i++;
	if(i<g.size()){
		g[i]=true;
		FOR(j,i) g[j]=false;
		return true;
	}

	return false;
}

vector<PRI> pickset(const vector<bool> &g, const vector<PRI> &b){
	vector<PRI> bb;
	FOR(i,b.size()) if(g[i]) bb.push_back(b[i]);
	return bb;
}

int main(){
	int T;
	cin>>T;
	FOR(test,T){
		int N;
		cin>>N;
		vector<PRI> a(N), b(N);
		FOR(i,N){
			cin>>b[i].first>>a[i].first;
			a[i].second=b[i].second=i;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int min = -1;
		vector<bool> g(N,false);
		do{
			vector<PRI> bb = pickset(g,b);
			int count = mincount(N,a,b);
			if(min < 0 && count>=0) min = count;
			else if(min>=0 && count>=0 && count < min) min = count;
		} while(nextset(g));

		if(min<0) cout<<"Case #"<<test+1<<": "<<"Too Bad"<<endl;
		else cout<<"Case #"<<test+1<<": "<<min<<endl;
	}
	return 0;
}