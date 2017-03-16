#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;



int J, P, S, K;
struct node {
	int x, y, z;
};


int flag;

int b[3] = { 1,100,10000};

vector<vector<int>> anss;
void sss(vector<int>& index, ofstream& fout, vector<node>& a) {
	map<int, int> mm;
	for (int i = 0; i < index.size(); i++) {
		node& t = a[index[i]];
		mm[b[0] * (t.x+1) + b[1] * (1+t.y)] ++;
		mm[b[0] * (t.x+1) + b[2] * (1+t.z)] ++;
		mm[b[1] * (t.y+1) + b[2] * (1+t.z)] ++;
	}
	for (auto k : mm) {
		if (k.second > K) return;
	}
	flag = 1;

	anss.push_back(index);
}


bool pddfs(int dep, vector<int>& index, vector<node>& a) {
	map<int, int> mm;
	for (int i = 0; i < dep; i++) {
		node& t = a[index[i]];
		mm[b[0] * (t.x + 1) + b[1] * (1 + t.y)] ++;
		mm[b[0] * (t.x + 1) + b[2] * (1 + t.z)] ++;
		mm[b[1] * (t.y + 1) + b[2] * (1 + t.z)] ++;
	}
	for (auto k : mm) {
		if (k.second > K) return 0;
	}
	return 1;
}

void dfs(int num, vector<node>& a, ofstream& fout, vector<int>& index, int dep) {
	if (flag) return;
	if (!pddfs(dep, index, a)) return;
	if (dep == num) {
		sss(index, fout,a);
		return;
	}

	int st = 0;
	if (dep > 0) st = index[dep - 1] + 1;
	for (int i = st; i < a.size(); i++) {
		index[dep] = i;
		dfs(num, a, fout, index, dep + 1);
	}
}

bool pd(int num, vector<node>& a, ofstream& fout) {
	flag = 0;
	vector<int> index;
	index.resize(num);
	dfs(num, a, fout, index, 0);
	return flag;
}

void solve(ifstream& fin, ofstream& fout) {
	anss.clear();
	fin >> J >> P >> S >> K;
	vector<node> a;
	for (int i = 0; i < J; i++) {
		for (int j = 0; j < P; j++) {
			for (int k = 0; k < S; k++) {
				node tmp;
				tmp.x = i, tmp.y = j, tmp.z = k;
				a.push_back(tmp);
			}
		}
	}


	int ans = 1;
	for (ans = 1; ans <= a.size(); ans++) {
		if (!pd(ans, a, fout)) {
			break;
		}
	}
	if (ans ==1)
		fout << 0 << endl; else {
		vector<int> index = anss.back();
		fout << index.size() << endl;
		for (int i = 0; i < index.size(); i++) {
		node& t = a[index[i]];
		fout << t.x+1 << " "<< t.y+1 << " " << t.z+1 << endl;
		}
		
	}
}

int main(int argc, char *argv[])
{
	const char* inn;
	if (argc < 2) {
		inn = "c.in";
	}
	else {
		inn = argv[1];
	}
	string in = inn;
	string out = in.replace(in.find(".in"), in.length(), ".out");
	ifstream fin(inn);
	ofstream fout(out);

	int t;
	fin >> t;

	for (int cs = 1; cs <= t; cs++) {
		cout << "Case #" << cs << endl;
		fout << "Case #" << cs << ": ";
		solve(fin, fout);
	}
	fout.close();

	return 0;
}
