#include<iostream>
#include<fstream>
using namespace std;
int n, m, remain, k;
int flag;
char ans[51][51];
bool isok;
void write(int x, int y, int ch){
	if (flag == 0){
		ans[x][y] = ch;
	}
	else ans[y][x] = ch;
}
bool solve1(){
	for (int i = 1; i <= remain; i++)
		ans[1][i] = '.';
	return true;
}
bool solve2(){
	if (remain % 2 == 0){
		if (remain == 2)
			return false;
		for (int i = 1; i <= remain/2; i++){
			ans[1][i] = '.';
			ans[2][i] = '.';
 		}
		return true;
	}
	else{
		if (remain == 1){
			ans[1][1] = '.';
			return true;
		}
		return false;
	}
}
bool solve3(){
	if (remain == 1){
		ans[1][1] = '.';
		return true;
	}
	else if (remain == 2){
		return false;
	}
	else if (remain == 3){
		return false;
	}
	else if (remain == 4){
		ans[1][1] = '.';
		ans[1][2] = '.';
		ans[2][1] = '.';
		ans[2][2] = '.';
		return true;
	}
	else if (remain == 5){
		return false;
	}
	else if (remain == 6){
		ans[1][1] = '.';
		ans[1][2] = '.';
		ans[2][1] = '.';
		ans[2][2] = '.';
		ans[3][1] = '.';
		ans[3][2] = '.';
		return true;
	}
	else if (remain == 7){
		return false;
	}
	else{
		if (remain % 3 == 0){
			for (int i = 1; i <= remain/3; i++){
				ans[1][i] = '.';
				ans[2][i] = '.';
				ans[3][i] = '.';
			}
		}
		else if (remain % 3 == 2){
			for (int i = 1; i <= remain/3; i++){
				ans[1][i] = '.';
				ans[2][i] = '.';
				ans[3][i] = '.';
			}
			ans[1][remain/3+1] = '.';
			ans[2][remain/3+1] = '.';
		}
		else {
			for (int i = 1; i <= remain/3-1; i++){
				ans[1][i] = '.';
				ans[2][i] = '.';
				ans[3][i] = '.';
			}
			ans[1][remain/3+1] = '.';
			ans[2][remain/3+1] = '.';
			ans[1][remain/3] = '.';
			ans[2][remain/3] = '.';
		}
		return true;
	}
}

bool solvek(){
	if (remain <= 3*m)
		return solve3();
	else {
		if (remain % m != 1){
			for (int i = 1; i <= remain/m; i++)
				for (int j = 1; j <= m; j++)
					ans[i][j] = '.';
			for (int j = 1; j <= remain%m; j++)
				ans[remain/m+1][j] = '.';
		}
		else {
			for (int i = 1; i <= remain/m; i++)
				for (int j = 1; j <= m; j++)
					ans[i][j] = '.';
			ans[remain/m+1][1] = '.';
			ans[remain/m+1][2] = '.';
			ans[remain/m][m] = '*';
		}
		return true;
	}
}
int main(){
	ifstream fin("3.in");
	ofstream fout("3.out");
	int testSum;
	fin >> testSum;
	for (int test = 1; test <= testSum; test++){
		fout << "Case #" << test << ":" << endl;
		fin >> n >> m >> k;
		if (n < m){
			flag = 0;
		}
		else {
			flag = 1;
			int tmp = n;
			n = m;
			m = tmp;
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				ans[i][j] = '*';
		remain = n*m - k;
		cout << n << ' ' << m << ' ' << remain << endl;

		if (n == 1){
			isok = solve1();
		}
		else if (n == 2){
			isok = solve2();
		}
		else if (n == 3){
			isok = solve3();
		}
		else{
			isok = solvek();
		}
		if (isok){
			ans[1][1] = 'c';
			if (flag == 0){
				for (int i = 1; i<=n; i++){
					for (int j = 1; j<=m; j++)
						fout << ans[i][j];
					fout << endl;
				}
			}
			if (flag == 1){
				for (int j = 1; j<=m; j++){
					for (int i = 1; i<=n; i++)
						fout << ans[i][j];
					fout << endl;
				}
			}
		}
		else {
			fout << "Impossible" << endl;
		}
	}

}
