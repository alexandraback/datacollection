#include <iostream>
#include <fstream>
using namespace std;

int data[200], d;

int compare(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}

int backtrack(bool a[200], int now, int find){
	if (now == d){
		int sum = 0;
		for (int i = 0; i < d; i++){
			if (a[i]){
				sum += data[i];
			}
		}
		if (sum == find){
			return 1;
		}
		else{
			return 0;
		}
	}

	int ret;
	a[now] = 0;
	ret = backtrack(a, now + 1, find);
	if (ret == 1){
		return 1;
	}
	a[now] = 1;
	ret = backtrack(a, now + 1, find);
	if (ret == 1){
		return 1;
	}
	return 0;
}

int main(){
	ifstream fin;
	fin.open("C-small-attempt1.in");
	ofstream fout;
	fout.open("C-small-attempt1.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int c, v;
		fin >> c >> d >> v;
		int save;
		save = d;
		for (int i = 0; i < d; i++){
			fin >> data[i];
		}
		qsort(data, d, sizeof(int), compare);
		for (int i = 1; i <= v; i++){
			bool a[200] = { 0, };
			if (backtrack(a, 0, i) == 0){
				data[d] = i;
				d++;
			}
		}

		fout << "Case #" << T << ": ";
		fout << d - save;
		fout << endl;
	}

}