#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> list;

void genall(vector<int> cur, vector<int> cursq, int i=0) {
	int i2=cur.size()-1-i;
	if(i2<i) return;
	if(cur[i]==3) return;
	for(int j=0; j<cur.size(); j++) cursq[j+i]+=2*cur[j];
	cursq[2*i]++;
	cur[i]++;
	if(i!=i2) {
		for(int j=0; j<cur.size(); j++) cursq[j+i2]+=2*cur[j];
		cursq[2*i2]++;
		cur[i2]++;
	}
	for(int j=0; j<cursq.size(); j++) if(cursq[j]>9) return;
	string s;
	for(int i=0; i<cursq.size(); i++) s += ('0'+cursq[i]);
	list.push_back(s);
	genall(cur, cursq, i);
	for(int j=i+1; j<cur.size(); j++) genall(cur, cursq, j);
}

bool cmp(const string& s1, const string& s2) {
	if(s1.size()<s2.size()) return true;
	if(s1.size()>s2.size()) return false;
	return s1<s2;
}

int main(void) {
	list.push_back("0");
	for(int len=1; len<=60; len++) {
		genall(vector<int>(len), vector<int>(2*len-1));
	}
	sort(list.begin(), list.end(), cmp);
	int T;
	cin >> T;
	for(int ts=1;ts<=T;ts++) {
		string A,B;
		cin >> A >> B;
		cout << "Case #" << ts << ": " << upper_bound(list.begin(),list.end(),B,cmp)-lower_bound(list.begin(),list.end(),A,cmp) << endl;
	}
}
