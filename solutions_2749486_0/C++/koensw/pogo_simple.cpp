#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>

unsigned long long T;
unsigned long long X, Y;

long long pos[201][201][101];
std::pair<int, int> nxt[201][201][101];

long long coff[4] = {-1, 0, 1, 0};
long long roff[4] = {0, 1, 0, -1};

char convert(long long x, long long y, long long d){
	int dx=x/d;
	int dy=y/d;
	if(dx == 0 && dy == -1) return 'W';
	else if(dx == 0 && dy == 1) return 'E';
	else if(dx == 1 && dy == 0) return 'N';
	else if(dx == -1 && dy == 0) return 'S';
	return '?';
}

long long dfs(long long x, long long y, long long d){
	if(d >= 100) return INT_MAX-2;
	else if(x < 0 || y < 0 || x >= 201 || y>=201) return INT_MAX-2;
	else if(x==X && y==Y) return 0;
	else if(pos[x][y][d] != INT_MAX) return pos[x][y][d];

	pos[x][y][d] = INT_MAX-2;
	for(long long i=0; i<4; ++i){
		long long n = dfs(x+roff[i]*d, y+coff[i]*d, d+1)+1;
		if(n < pos[x][y][d]){
			pos[x][y][d] = n;
			nxt[x][y][d] = std::make_pair(x+roff[i]*d, y+coff[i]*d);
		}
	}
	return pos[x][y][d];
}

int main(){
	std::cin >> T;
	
	for(long long p=0; p<T; ++p){
		for(long long i=0; i<201; ++i){
			for(long long j=0; j<201; ++j){
				for(long long k=0; k<101; ++k){
					pos[i][j][k] = INT_MAX;
				}
			}
		}
	
		std::cin >> X >> Y;
		X+=100; Y+=100;
		std::swap(X, Y);
		
		long long add = 1;
		dfs(100, 100, 1);
		int x=100;
		int y=100;
		int d=1;
		//std::cout << pos[x][y][1] << std::endl;
		std::cout << "Case #" << (p+1) << ": ";
		while(!(x == X && y == Y)){
			int nx = nxt[x][y][d].first;
			int ny = nxt[x][y][d].second;
			//std::cout << x << " " << y << " -> " << nx << " " << ny << ": ";
			std::cout << convert(nx-x, ny-y, d);
			//std::cout << std::endl;
			x = nx;
			y = ny;
			++d;
		}
		std::cout << std::endl;
	}
}