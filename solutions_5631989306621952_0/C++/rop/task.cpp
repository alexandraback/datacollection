#include <bits/stdc++.h>
using namespace std;
char c[1010];
vector<string>v;
void run(string s, int id){
	if(id == strlen(c)){
		v.push_back(s);
		return;
	}
	s.push_back(c[id]);
	run(s, id+1);
	s.pop_back();
	string ss;
	ss.push_back(c[id]);
	ss= ss+s;
	run(ss, id+1);
}
void solve(int tc){
  	scanf("%s", c);
  	v.clear();
  	string s;
  	run(s, 0);
  	sort(v.begin(), v.end());
  	printf("Case #%d: ", tc);
  	cout << v[v.size()-1] << endl;
}
int main(){
  int tc;
  scanf("%d", &tc);
  getchar();
  for(int i = 1; i <= tc; i++)solve(i);
}