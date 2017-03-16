#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

void solve(int t) {
  //string str;
  //getline (cin,str);

  int N;
  cin >> N;
  vector<vector<int> > p;
  for (int i=0;i<N;i++) {
	int M;
	cin >> M;
	p.push_back(vector<int>());
	for (int j=0;j<M;j++) {
	  int k;
	  cin >> k;
	  p[i].push_back(k-1);
	}
	sort(p[i].begin(),p[i].end());
  }
  //cout << "input complete " << t << endl;
  bool change=true;
  while (change) {
	change=false;
	for (int i=0;i<N;i++) {
	  int k=p[i].size();
	  vector<int> result;
	  vector<int> stay;
	  for (int j=0;j<p[i].size();j++) {
		vector<int> copy(result.begin(),result.end());
		if (p[p[i][j]].empty()) {
		  stay.push_back(p[i][j]);
		}
		else {
		  result.insert(result.end(),p[p[i][j]].begin(),p[p[i][j]].end());
		  merge(copy.begin(),copy.end(),p[p[i][j]].begin(),p[p[i][j]].end(),result.begin());
		}
	  }
	  p[i].resize(result.size()+stay.size());
	  merge(result.begin(),result.end(),stay.begin(),stay.end(),p[i].begin());
	  //cout << i << "'s parents are: ";
	  //for (int j=0;j<p[i].size();j++) cout << p[i][j] << " ";
	  //cout << endl;
	  if (!result.empty()) {
		change=true;
		//sort(p[i].begin(),p[i].end());
		if (unique(p[i].begin(),p[i].end())!=p[i].end()) {
		  // diamond inheritance
		  printf("Case #%d: Yes\n",t);
		  return;
		}
	  }
	}
  }
  printf("Case #%d: No\n",t);
}

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
