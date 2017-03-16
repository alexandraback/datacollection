#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000;
int blocks; double mass[2][N]; bool used[N];

int find_block(const double & told){
	int left = 0, right = blocks;
	while (left < right){
		int mid = (left + right) / 2;
		if (mass[1][mid] < told) left = mid + 1;
		else right = mid;
	}
	for (; left < blocks && used[left]; ++left);
	if (left == blocks)
		for (left = 0; used[left]; ++left);
	return left;
}

int play_war(){
	int cnt = 0, loc;
	for (int x = 0; x < blocks; ++x) used[x] = false;
	for (int x = 0; x < blocks; ++x){
		used[loc = find_block(mass[0][x])] = true;
		if (mass[0][x] > mass[1][loc]) ++cnt;
	}
	return cnt;
}

int play_deceit(){
	int cnt = 0;
	for (int x = 0; x < blocks; ++x){
		if (mass[0][x] > mass[1][cnt]) ++cnt;
	}
	return cnt;
}

int main(){
	FILE * fin, * fout;
	freopen_s(&fin, "D-small-attempt0.in", "r", stdin);
	freopen_s(&fout, "war.out", "w", stdout);
	int run;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> blocks;
		for (int y = 0; y < 2; ++y)
			for (int x = 0; x < blocks; ++x)
				cin >> mass[y][x];
		sort(mass[0], mass[0]+blocks);
		sort(mass[1], mass[1]+blocks);
		cout << "Case #" << a << ": " << play_deceit() << " " << play_war() << endl;
	}
	return 0;
}
