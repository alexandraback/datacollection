#include <iostream>
using namespace std;

bool mine[50][50];
bool swapped=false;
int X,Y,M;

void write(int x, int y, bool v) {
	if(swapped) mine[x][y]=v;
	else mine[y][x]=v;
}

bool read(int x, int y) {
	if(swapped) return mine[x][y];
	else return mine[y][x];
}

void print() {
	if(swapped) {
		int tmp=X;
		X=Y;
		Y=tmp;
	}

	for(int x=0; x<X; x++) {
		for(int y=0; y<Y; y++) {
			if(x == 0 && y == 0)
				cout << 'c';
			else if(mine[y][x]) cout << '*';
				else cout << '.';
		}
		cout << endl;
	}
}

void run() {
	for(int i=0; i<50; i++)
		for(int j=0; j<50; j++)
			mine[i][j]=true;

	cin >> X >> Y >> M;

	swapped=false;
	if(X < Y) {
		int tmp=X;
		X=Y;
		Y=tmp;
		swapped=true;
	}

	int nM=X*Y-M;

	if(nM == 1) {
		write(0,0,false);
		print();
		return;
	}

	if(Y == 1) {
		for(int x=0; x<nM; x++)
			write(x,0,false);

		print();
		return;
	}

	if(nM == 2 || nM == 3 || nM == 5 || nM == 7) {
		cout << "Impossible" << endl;
		return;
	}

	if(Y == 2 && nM%2 != 0) {
		cout << "Impossible" << endl;
		return;
	}

	if(nM%2 == 0) {
		int minesLeft=nM;
		for(int x=0; x<nM/2 && x<X; x++) {
			write(x,0,false),write(x,1,false);
			minesLeft-=2;
		}
		
		if(minesLeft > 0) {
			for(int height=2; minesLeft > 0; height++) {
				for(int x=0; x<X-(X%2) && minesLeft > 0; x++) {
					write(x,height,false);
					minesLeft--;
				}
				if(minesLeft > 0) {
					if(height%2 == 1 && X%2 == 1) {
						write(X-1,height,false);
						write(X-1,height-1,false);
						minesLeft-=2;
					}
				}
			}
		}

		print();
		return;
	} else {
		int minesLeft=nM;
		for(int x=0; x<nM/2 && x<X; x++) {
			write(x,0,false),write(x,1,false);
			minesLeft-=2;
			if(minesLeft == 3) break;
		}
		
		for(int height=2; minesLeft > 0; height++) {
			if(minesLeft-X == 1) {
				for(int x=0; x<X-2; x++)
					write(x,height,false), minesLeft--;
				write(0,height+1,false);
				write(1,height+1,false);
				write(2,height+1,false);
				if(read(2,height)) {
					write(2,height+1,true);
					write(2,height,false);
				}
				minesLeft-=3;
			} else {
				for(int x=0; minesLeft > 0 && x<X; x++)
					write(x,height,false), minesLeft--;
			}
		}

		print();
		return;
	}

	cout << "Impossible" << endl;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cout << "Case #" << (i+1) << ":" << endl;
		run();
	}
	return 0;
}