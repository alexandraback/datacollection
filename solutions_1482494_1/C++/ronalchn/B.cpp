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
  int N;
  cin >> N;
  vector<int> complete;
  int stars=0;
  multimap<int,int> s1;
  multimap<int,pair<int,int> > add;
  multimap<int,pair<int,int> > s2;
  for (int i=0;i<N;i++) {
	int a, b;
	cin >> a >> b;
	complete.push_back(0);
	s1.insert(make_pair(b,i));
	add.insert(make_pair(a,make_pair(b-a,i)));
	//s2.insert(make_pair(a-b,make_pair(a,i)));
  }
  //for (map<int,int>::iterator it = s1.begin();it!=s1.end();it++) {
  //  cout << it->second << " needs " << it->first << " stars" << endl;
  //}
  map<int,int>::iterator it1 = s1.begin();
  map<int,pair<int,int> >::iterator itadd = add.begin();
  map<int,pair<int,int> >::iterator it2; // = s2.begin();
  int games = 0;
  while (true) {
	while (it1->first <= stars) {
	  if (complete[it1->second]!=2) {
		stars+=2-complete[it1->second];
		complete[it1->second]=2;
		games++;
		//cout << "Do lvl 2 of " << it1->second << " " << games << endl;
	  }
	  it1++;
	  if (stars == 2*N) break;
	}
	while (itadd != add.end() && itadd->first <= stars) { // add 1st lvls which can now be done
	  s2.insert(make_pair(-itadd->second.first,make_pair(itadd->first,itadd->second.second)));
	  itadd++;
	}
	if (stars == 2*N) break;
	while (true) {
	  if (s2.empty()) {
		printf("Case #%d: Too Bad\n",t);
		return;
	  }
	  it2 = s2.begin();
	  if (complete[it2->second.second] == 0) {
		stars++;
		games++;
		complete[it2->second.second]=1;
		//cout << "Do lvl 1 of " << it2->second.second << " " << games << endl;
		s2.erase(it2);
		break;
	  }
	  else s2.erase(it2);
	}
	if (stars == 2*N) break;
  }
  //(0)5)
  // 0(1)
  // 1(1)
  // 4 7)
  // 5 6)
  //getline (cin,str);

  printf("Case #%d: %d\n",t,games);
}

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
