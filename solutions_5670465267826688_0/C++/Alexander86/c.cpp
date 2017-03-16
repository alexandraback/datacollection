
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int getId(string n){
	if(n.size() == 2){
		return -getId(n.substr(1));
	}
	if(n == "1")return 2;
	if(n == "i")return 3;
	if(n == "j")return 5;
	assert(n == "k");
	return 7;
}
int getId(char c){
	string tmp = "";
	tmp += c;
	return getId(tmp);
}
string getString(int id){
	if(id < 0){
		string tmp = getString(abs(id));
		string tmp2 = "-" + tmp;
		return tmp2;
	}
	if(id == 2)return "1";
	if(id == 3)return "i";
	if(id == 5)return "j";
	assert(id == 7);
	return "k";
}

string results[4][4] = {
	{"1", "i", "j", "k"},
	{"i", "-1", "k", "-j"},
	{"j", "-k", "-1", "i"},
	{"k", "j", "-i", "-1"}};

string literals[4] = {"1", "i", "j", "k"};
string todo[3] = {"i", "j", "k"};
map<pair<int, int>, int> mult;

int myPow(int id, int p){
	if(p == 0)return getId("1");
	int square = mult[mp(id, id)];
	int rek = myPow(square, p / 2);
	if(p&1)return mult[mp(id, rek)];
	else return rek;
}
bool check(){
	int L, X;
	cin >> L >> X;
	string in;
	cin >> in;
	int nX = 0, nL = 0;
	FOR(td, 0, 3){
		set<int> found;
		int cur = getId("1");
		int aim = getId(todo[td]);
		while(true){
			if(nL == L){
				if(found.find(cur) != found.end())return false;
				found.insert(cur);
				nL = 0;
				nX++;
				if(nX > X)return false;
			}
			if(cur == aim)break;
			int nextId = getId(in[nL++]);
			cur = mult[mp(cur, nextId)];
		}
	}
	if(nL == 0 && nX == X)return true;
	int cur = getId("1");
	while(nL < L){
		int nextId = getId(in[nL++]);
		cur = mult[mp(cur, nextId)];
	}
	nL = 0;
	nX++;
	if(nX > X)return false;
	int mulIn = getId("1");
	FOR(i,0,L)mulIn = mult[mp(mulIn, getId(in[i]))];
	mulIn = myPow(mulIn, X - nX);
	cur = mult[mp(cur, mulIn)];
	return cur == getId("1");
}

int main() {
	FOR(i1,0,4)FOR(i2,0,4){
		int id1 = getId(literals[i1]);
		int id2 = getId(literals[i2]);
		int resid = getId(results[i1][i2]);
		mult[mp(id1,id2)]=resid;
		mult[mp(-id1,id2)]=-resid;
		mult[mp(id1,-id2)]=-resid;
		mult[mp(-id1,-id2)]=resid;
	}
	int TC;
	cin >> TC;
	FOR(tc, 1, TC + 1){
		cout << "Case #" << tc << ": ";
		if(check()){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
