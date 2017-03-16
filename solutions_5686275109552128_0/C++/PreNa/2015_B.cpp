#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int getmax(vector<int> p){
	int length = p.size();
	int max = 0;
	for (int i = 1; i < length; i++){
		if (p[i] > p[max])
			max = i;
	}
	return max;
}

vector<int> getmax2(vector<int> p, int max){
	p.push_back(p[max] / 2);
	p[max] = (p[max] + 1) / 2;
	return p;
}

int main(){
	ifstream fin;
	fin.open("B-small-attempt2.in");
	ofstream fout;
	fout.open("B-small-attempt2.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int d;
		fin >> d;
		int tmp;

		vector<int> p;

		int m = -1;
		for (int i = 0; i < d; i++){
			fin >> tmp;
			p.push_back(tmp);
			if (tmp > m)
				m = tmp;
		}

		int maxval = INT_MAX;

		for (int i = 0; i < m; i++){
			int max = getmax(p);
			
			if (maxval > p[max] + i){
				maxval = p[max] + i;
			}
			p = getmax2(p, max);
		}

		fout << "Case #" << T << ": ";
		fout << maxval;
		fout << endl;
	}

}