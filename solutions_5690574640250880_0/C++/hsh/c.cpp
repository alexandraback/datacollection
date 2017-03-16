#include <iostream>
#include <vector>

void fillTop(const int r, const int c, const int m, const int limit, int &cnt, std::vector<std::vector<char> > &mat){
	if(r==1)
		for(int i = 2; cnt > 0 && i < c; i++, cnt--)
			mat[0][i] = '.';
	else if(r > 1)
		for(int i = 2; cnt > limit && i < c; i++, cnt-=2)
			mat[0][i] = mat[1][i] = '.';
}

void fillLeft(const int r, const int c, const int m, const int limit, int &cnt, std::vector<std::vector<char> > &mat){
	if(c==1)
		for(int i = 2; cnt > 0 && i < r; i++, cnt--)
			mat[i][0] = '.';
	else if(c > 1)
		for(int i = 2; cnt > limit && i < r; i++, cnt-=2)
			mat[i][0] = mat[i][1] = '.';
}

bool find(const int r, const int c, const int m, std::vector<std::vector<char> > &mat){
	mat.resize(r);
	for(int i = 0; i < r; i++)
		mat[i].assign(c, '*');
	mat[0][0] = 'c';
	int cnt = r * c - 1 - m;
	if (cnt == 0) return true;

	if(r > 1){
		mat[1][0] = '.';
		cnt--;
	}
	if(c > 1){
		mat[0][1] = '.';
		cnt--;
	}
	if(r > 1 && c > 1){
		mat[1][1] = '.';
		cnt--;
	}
	if(cnt < 0) return false;
	if((cnt == 1 || cnt == 3) && r > 1 && c > 1) return false;

	if(r > c){
		fillTop(r, c, m, 3, cnt, mat);
		fillLeft(r, c, m, 1, cnt, mat);
	}else{
		fillLeft(r, c, m, 3, cnt, mat);
		fillTop(r, c, m, 1, cnt, mat);
	}

	for(int i = 2; cnt > 0 && i < r; i++)
		for(int j = 2; cnt > 0 && j < c; j++){
			cnt--;
			mat[i][j] = '.';
		}

	return cnt == 0;
}

void func(const int cas){
	int r,c,m;
	std::cin >> r >> c >> m;
	std::vector<std::vector<char> > mat;

	std::cout << "Case #" << cas << ":" << std::endl;
	if(find(r, c, m, mat))
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++)
				std::cout << mat[i][j];
			std::cout << std::endl;
		}
	else std::cout << "Impossible" << std::endl;
}

int main(){
	int T;
	std::cin >> T;
	for(int cas = 1; cas <= T; cas++)
		func(cas);
	return 0;
}