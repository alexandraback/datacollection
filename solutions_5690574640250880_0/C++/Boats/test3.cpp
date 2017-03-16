#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

ifstream input("in.in");
ofstream output("ans.out");

struct team {
	int v,a,b;
	int from;
};

int r, c, m;
bool f;
char map[50][50];
int num;

int search(int a, int b) {
	if (f) return 0;
	if (num > r*c - m) return 0;

	if (num == r*c - m) {
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				output << map[i][j];
			}
			output << "\n";
		}
		f = true;
		return 0;
	}

	int x[9], y[9];
	
	int count = 0;
 	for (int i=-1; i<=1; i++) {
		for (int j=-1; j<=1; j++) {
			if (a+i>=0 && a+i<r && b+j>=0 && b+j<c && map[a+i][b+j]=='*') {
				x[count] = a + i;
				y[count] = b + j;
 				count++;
 				map[a+i][b+j] = '.';
 			}
 		}
	}

	if (count != 0) {
		num += count;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (map[i][j] == '.' && (!(a==i && b==j)))
					search(i, j);
			}
		}

		for (int i=0; i<count; i++) {
			map[x[i]][y[i]] = '*';
		}
		num -= count;
	}


	return 0;
}

int main() {
	int t;
	input >> t;
	for (int tt=0; tt<t; tt++) {
		input >> r >> c >> m;
		output << "Case #" << tt+1 << ":\n";
		if (r*c-m==0) {
			output << "Impossible\n";
			continue;
		}
		if (r==1 || c==1) {
			int flag = 0;
			for (int i=0; i<r; i++) {
				for (int j=0; j<c; j++) {
					if (flag==0) output << "c";
					else if (flag<r*c-m) output << ".";
					else output << "*";
					flag++;
				}
				output << "\n";
			}
			continue;
		}

		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++)
				map[i][j] = '*';
		map[0][0] = 'c';
		f = false;
		num = 1;
		search(0, 0);
		if (!f) 
			output << "Impossible\n";
	}
}