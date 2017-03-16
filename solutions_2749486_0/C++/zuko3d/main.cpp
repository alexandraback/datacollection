#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

class pp{
public:
	string path;
	pair<int, int> xy;
};

string solve(int x, int y){
	string ret;
	map<pair<int,int>, int> were;
	vector<pp> paths, todo;
	pp tpp;
	pair<int,int> dest;

	dest = pair<int,int>(x,y);
	were.clear();
	ret = "";
	paths.clear();
	todo.clear();

	tpp.path = "";
	tpp.xy = pair<int,int>(0,0);
	paths.push_back(tpp);
	int jmp;
	jmp = 0;
	while(1){
		jmp++;
		REP(i,paths.size()){
			tpp = paths[i];
			tpp.path+='N';
			tpp.xy.second+=jmp;
			if(were.find(tpp.xy)==were.end()){
				if(tpp.xy == dest)return tpp.path;
				were[tpp.xy] = 1;
				todo.push_back(tpp);
			}

			tpp = paths[i];
			tpp.path+='E';
			tpp.xy.first+=jmp;
			if(were.find(tpp.xy)==were.end()){
				if(tpp.xy == dest)return tpp.path;
				were[tpp.xy] = 1;
				todo.push_back(tpp);
			}

			tpp = paths[i];
			tpp.path+='S';
			tpp.xy.second-=jmp;
			if(were.find(tpp.xy)==were.end()){
				if(tpp.xy == dest)return tpp.path;
				were[tpp.xy] = 1;
				todo.push_back(tpp);
			}

			tpp = paths[i];
			tpp.path+='W';
			tpp.xy.first-=jmp;
			if(were.find(tpp.xy)==were.end()){
				if(tpp.xy == dest)return tpp.path;
				were[tpp.xy] = 1;
				todo.push_back(tpp);
			}
		}
		paths = todo;
		todo.clear();
	}



	return ret;
}

int main(void){
	int T;
	string ret;
	ifstream fin("B-small-attempt0.in");
	ofstream fout("out.txt");
	int x,y;


	fin >> T;
	REP(w, T){
		fin >> x >> y;
		ret = solve(x,y);

		cout << "Case #" << w+1 << ": " << ret << endl;
		fout << "Case #" << w+1 << ": " << ret << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
