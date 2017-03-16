#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

//istream& fin = cin;
//ifstream fin ("C-sample.txt");
ifstream fin ("C-small-attempt0.in");
ofstream fout ("C-small-attempt0.out");
//ifstream fin ("C-large.in");
//ofstream fout ("C-large.out");
//ostream& fout = cout;

class Pair{
	public:
		long long a;
		int c;
};

long long DFS(deque<Pair> v1, deque<Pair> v2, long long rs){
	if(v1.empty() || v2.empty()){
		return rs;
	}
	while(v1.front().c==v2.front().c){
		if(v1.front().a<v2.front().a){
			rs+=v1.front().a;
			v2.front().a-=v1.front().a;
			v1.pop_front();
		}else if(v1.front().a>v2.front().a){
      rs+=v2.front().a;
      v1.front().a-=v2.front().a;
      v2.pop_front();
		}else{
			rs+=v1.front().a;
			v1.pop_front();
			v2.pop_front();
		}
		if(v1.empty() || v2.empty()){
			return rs;
		}
	}
	Pair tmp=v1.front();
	v1.pop_front();
	long long rs1 = DFS(v1,v2,rs);
	v1.push_front(tmp);
	v2.pop_front();
	long long rs2 = DFS(v1,v2,rs);
	return max(rs1,rs2);
}

int main(){
	int t,n,m;
	fin >> t;
	for(int i=1; i<=t; i++){
    fout << "Case #" << i << ": ";
		fin >> n >> m;
		deque<Pair> v1,v2;
		for(int j=0; j<n; j++){
			Pair p;
			fin >> p.a >> p.c;
			v1.push_back(p);
		}
		for(int j=0; j<m; j++){
			Pair p;
			fin >> p.a >> p.c;
			v2.push_back(p);
		}
		long long rs=DFS(v1,v2,0);
		fout << rs << endl;
	}
	system("pause");
}
