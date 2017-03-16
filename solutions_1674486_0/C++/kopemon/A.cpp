#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <list>
#include <queue>

#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef pair<int,int> point;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//for debug
template<class T> ostream &operator<<(ostream &os, vector<T> v){if(v.empty()){ os << "[]"; return os;} os << "["; for(unsigned int i = 0; i < v.size() - 1; i++) os << v[i] << ", "; os << v[v.size() - 1] << "]"; return os; }
template<class T> ostream &operator<<(ostream &os, list<T> l){if(l.empty()){os << "[]"; return os;} os << "["; while(l.size() != 1){ os << l.front() << ", "; l.pop_front(); } os << l.front(); os << "]"; return os; }
template<class T> ostream &operator<<(ostream &os, set<T> s){if(s.empty()){ os << "[]"; return os;} os << "["; while(s.size() != 1){ T o = *s.begin();os << o << ", "; s.erase(o); } os << *s.begin(); os << "]"; return os; }



bool edge[1000][1000];

int main(){
	int T;
	ifstream in;

	//string ifile = "A-small-test.in";
	string ifile = "A-small-attempt0.in";
	//string ifile = "A-large.in";

	in.open(ifile.c_str());
	string ofile = ifile.substr(0,ifile.find('.')) + ".out";
	ofstream fout;
	fout.open(ofile.c_str());

	in >> T;
	for(int t = 0; t < T; t++){
		int N;
		in >> N;
		bool answer = false;
		map<int,bool> marked;

		stack<int> cross;

		memset(edge,0,1000*1000);

		for(int i = 0; i < N;i++){
			int m;
			in >> m;
			for(int j = 0; j < m; j++){
				int x;
				in >> x;
				edge[i][x-1] = true;
			}
		}

		for(int j = 0; j < N; j++){
			int sum = 0;
			for(int i = 0; i < N; i++){
				if(edge[i][j])
					sum++;
			}
			if(sum >= 2)
				cross.push(j);
		}

		while(!cross.empty()){
			int start = cross.top();
			cross.pop();
			stack<int> s;
			s.push(start);

			map<int,bool> visited;

			while(!s.empty()){
				int node = s.top();
				s.pop();
				if(visited[node]){
					answer = true;
					goto end;
				}else{
					visited[node] = true;
				}
				for(int i = 0; i < N; i++){
					if(edge[i][node]){
						s.push(i);
					}
				}
			}
		}
		end:

		cout << "Case #" << (t + 1) << ": " << (answer ? "Yes" : "No") << endl;
		fout << "Case #" << (t + 1) << ": " << (answer ? "Yes" : "No") << endl;

	}

}
