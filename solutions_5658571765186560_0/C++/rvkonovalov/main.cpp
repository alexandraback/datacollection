// Microsoft Visual Studio Express 2013 for Windows Desktop

#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

template <class T>
class zArray{
	friend class TestzArray;
protected:
	int n;
	T *p;
	void CriticalError(){
		//Application->MessageBox("Range Out","zArray Critical Error");
		cout << "zArray Critical Error: Range Out";
	}
	virtual int RealLen(int i){
		//return 10*((i-1)/10+1);  -> Old release
		if (i == 0)return 0;
		int RL = 1;
		i--;
		for (; i>0; i >>= 1)RL <<= 1;
		return RL;
	}
public:
	zArray(){
		n = 0;
	}
	~zArray(){
		Free();
	}
	int Len(){
		return n;
	}
	void Free(){
		if (n)delete[]p;
		n = 0;
	}
	void SetLen(int new_n){
		if (new_n<0)return;
		if (RealLen(n) == RealLen(new_n) && n != 0 && new_n != 0){
			n = new_n;
			return;
		}
		T *new_p = 0;
		int min = (n<new_n ? n : new_n);
		if (new_n)new_p = new T[RealLen(new_n)];
		for (int i = 0; i<min; i++)new_p[i] = p[i];
		if (n)delete[]p;
		n = new_n;
		p = new_p;
	}

	T & operator [](int i){
		if (i< -n || i >= n){//CriticalError();
			string s = "Range Out:  Array Size = "; s += to_string(n);
			s += "  Call operator [] with value = ";    s += to_string(i);
			//Application->MessageBox(s.c_str(),"zArray Critical Error");
			cout << "zArray Critical Error: " << s;
		}
		if (i >= 0)return p[i];
		else    return p[n - (-i)];
	}
	T & last(){
		if (n == 0)CriticalError();
		return p[n - 1];
	}
	T* GetP(){
		if (!n)return 0;
		return p;
	}

	T& Add(){
		SetLen(n + 1);
		return last();
	}
	void Add(T &t){
		SetLen(n + 1);
		p[n - 1] = t;
	}

	void Delete(int i){
		if (i<0 || i >= n)CriticalError();
		for (int k = i; k<n - 1; k++)p[k] = p[k + 1];
		SetLen(n - 1);
	}
	T& Insert(int i){
		if (i<0 || i>n)CriticalError();
		Add();
		for (int k = n - 1; k>i; k--)p[k] = p[k - 1];
		return p[i];
	}
	void Insert(int i, T &t){
		Insert(i) = t;
	}
	zArray & operator=(const zArray &a){
		if (this == &a)return *this;
		SetLen(a.n);
		for (int i = 0; i<n; i++)p[i] = a.p[i];
		return *this;
	}

	void Sort(){
		T *tmp = new T[n];
		T *m, *m1 = p, *m2 = tmp;
		int i1, i2, j, keylen;

		for (keylen = 1; keylen<2 * n; keylen *= 2){   // exampl: n=5
			for (j = 0; j<n; j += 2 * keylen){
				for (i1 = i2 = 0; i1<keylen && i2<keylen && j + keylen + i2<n;){
					if (m1[j + i1] <= m1[j + keylen + i2]){
						m2[j + i1 + i2] = m1[j + i1];        i1++;
					}
					else{
						m2[j + i1 + i2] = m1[j + keylen + i2]; i2++;
					}
				}
				for (; i1<keylen && j + i1<n; i1++)
					m2[j + i1 + i2] = m1[j + i1];
				for (; i2<keylen && j + keylen + i2<n; i2++)
					m2[j + i1 + i2] = m1[j + keylen + i2];
			}
			m = m1;
			m1 = m2;
			m2 = m;
		}
		delete[]tmp;
	}
	bool CheckSort(){
		int i;
		for (i = 1; i<n; i++)if (p[i - 1]>p[i]){
			//Application->MessageBox("Sort Algorithm Incorrectly",
			//                        "MemArray Critical Error");
			cout << "zArray Critical Error: MemArray Critical Error";
			return false;
		}
		return true;
	}

	int BinSearch(T &value){
		// 1. Если элемента с таким значением нет,
		// возвращает какой-нибудь элемент в любом случае
		// (больший или меньший value).
		// 2. Если несколько элементов со значением value,
		// то возвращает элемент с наименьшим номером.
		// 3. Method use only "bool operator <=(const T&)"
		// definition for type T
		if (n == 0)return -1;
		int i, min = 0, max = n - 1;
		while (true){
			if (min == max)return min;
			if (min + 1 == max){
				if (value <= p[min])return min;
				return max;
			}
			i = min + (max - min) / 2;
			if (value <= p[i])max = i;
			else           min = i;
		}
	}
};

typedef zArray <int> zIntArray;
typedef zArray <double> zDoubleArray;
typedef zArray <string> zStringArray;
typedef zArray <char> zCharArray;
typedef zArray <zIntArray> zInt2DArray;
typedef zArray <zDoubleArray> zDouble2DArray;
typedef zArray <zStringArray> zString2DArray;
typedef zArray <zCharArray> zChar2DArray;

class zSimpleFile{
	char Delimeter;
	int lex_line, lex_col, lex_pos;
public:
	zStringArray z;

	zSimpleFile(){
		Delimeter = '\t';
		lex_line = lex_col = lex_pos = -1;
	}

	void SetDelimeter(char d){
		Delimeter = d;
	}

	bool GetFile(string FileName){
		int i, n;
		char buf[10240];
		FILE * f;
		bool is_prev_char_0D = false;
		lex_line = lex_col = lex_pos = -1;

		z.Free();
		z.Add();
		f = fopen(FileName.c_str(), "rb");
		if (f == 0)return false;
		do{
			n = fread(buf, 1, 1024, f);
			for (i = 0; (i < n) && (i < 1024); i++){
				if ((buf[i] == '\x0A') && is_prev_char_0D){
					is_prev_char_0D = false;
					continue;
				}
				if ((buf[i] == '\x0D') || (buf[i] == '\x0A')){
					if (buf[i] == '\x0D')is_prev_char_0D = true;
					z.Add();
					continue;
				}
				z[-1] += buf[i];
			}
		} while (n == 1024);

		fclose(f);
		return true;
	}

	bool SaveFile(string FileName, zStringArray &zz){
		int i;
		string s;
		FILE * f;

		f = fopen(FileName.c_str(), "wb");
		if (f == 0)return false;

		for (i = 0; i < zz.Len(); i++){
			s = zz[i];
			if ((i + 1) < zz.Len())s += "\x0D\x0A";
			fwrite(s.c_str(), 1, s.length(), f);
		}
		fclose(f);
		return true;
	}

	string GetLex(int line, int col){ // line: 0 .. z.Len()-1
		string s;                     // col : 0 ..
		s = "";
		if ((line < 0) || (line >= z.Len()) || (col < 0))return s;
		if ((line != lex_line) || (col != lex_col)){
			lex_col = lex_pos = 0;
			lex_line = line;
		}
		for (; lex_pos < z[line].length(); lex_pos++){
			if (z[line][lex_pos] == Delimeter){
				lex_col++;
				if (lex_col > col){
					lex_pos++;
					break;
				}
			}
			else if (lex_col == col)s += z[line][lex_pos];
		}
		return s;
	}
	int     GetIntLex   (int line, int col){ return stoi (GetLex(line, col)); }
	__int64 GetInt64Lex (int line, int col){ return stoll(GetLex(line, col)); }
	double  GetDoubleLex(int line, int col){ return stod (GetLex(line, col)); }
};

//###################################################################

void swap(int & i1, int & i2){
	int i;
	i = i1; i1 = i2; i2 = i;
}

class tetris{
	void swap_c(char & c1, char & c2){
		char c;
		c = c1; c1 = c2; c2 = c;
	}
	void trans(){
		int i, j;
		for (i = 0; i < z.Len(); i++)for (j = 0; j < i; j++)swap_c(z[i][j], z[j][i]);
		swap(x, y);
	}
public:
	int x, y;
	zChar2DArray z;
	void init(int size){
		int i, j;
		z.Free();
		z.SetLen(size);
		for (i = 0; i < size; i++){
			z[i].SetLen(size);
			for (j = 0; j < size; j++)z[i][j] = '.';
		}
		x = y = 0;
	}
	void reflect(){
		int i, j;
		for (i = 0; i < x; i++)for (j = 0; j < (y / 2); j++)swap_c(z[i][j], z[i][y-1-j]);
	}
	void rotate90(){
		reflect();
		trans();
	}
	bool isEqual(tetris & t){
		int i, j, k;
		if (z.Len() != t.z.Len())return false;
		for (k = 0; k < 8; k++){
			if (k == 4)reflect();
			if ((x == t.x) && (y == t.y)){
				for (i = 0; i < x; i++){
					for (j = 0; j < y; j++)if (z[i][j] != t.z[i][j])break;
					if (j < y)break;
				}
				if (i == x)return true;
			}
			rotate90();
		}
		return false;
	}
	bool generate(tetris & t, int i, int j, int shift_type){
		int x_shift, y_shift, new_x, new_y, p, q;
		
		if (t.z[i][j] != '#')return false;
		x_shift = y_shift = 0;
		if (shift_type == 0)x_shift = -1;
		if (shift_type == 1)x_shift = 1;
		if (shift_type == 2)y_shift = -1;
		if (shift_type == 3)y_shift = 1;		
		i += x_shift;
		j += y_shift;

		if ((0 <= i) && (i < t.x) && (0 <= j) && (j < t.y))if (t.z[i][j] != '.')return false;
		new_x = t.x;
		if ((i < 0) || (i >= t.x))new_x++;
		new_y = t.y;
		if ((j < 0) || (j >= t.y))new_y++;
		init(max(new_x, new_y));
		x = new_x;
		y = new_y;

		x_shift = y_shift = 0;
		if (i < 0)x_shift = 1;
		if (j < 0)y_shift = 1;
		for (p = 0; p < t.x; p++)for (q = 0; q < t.y; q++)z[p + x_shift][q + y_shift] = t.z[p][q];
		z[i + x_shift][j + y_shift] = '#';
		return true;
	}
	int calc_S_dn(){
		int s = 0, i, j;
		for (i = 0; i < x; i++){
			for (j = 0; j < y; j++){
				if (z[i][j] == '#')break;
				s++;
			}
		}
		return s;
	}
	int calc_S_up(){
		int s = 0, i, j;
		for (i = 0; i < x; i++){
			for (j = y - 1; j >= 0; j--){
				if (z[i][j] == '#')break;
				s++;
			}
		}
		return s;
	}
	int calc_S_lf(){
		int s = 0, i, j;
		for (j = 0; j < y; j++){
			for (i = 0; i < x; i++){
				if (z[i][j] == '#')break;
				s++;
			}
		}
		return s;
	}
	int calc_S_rt(){
		int s = 0, i, j;
		for (j = 0; j < y; j++){
			for (i = x - 1; i >= 0; i--){
				if (z[i][j] == '#')break;
				s++;
			}
		}
		return s;
	}
};

typedef zArray<tetris> zTetrisArray;

void main(){
	string f1, f2;
	zSimpleFile f;
	zStringArray res;
	int T, n;

	int ProblemType = 1;
	string ProblemC = "D";
	bool isPractice = false;

	if (ProblemType == 0)f1 = "Example.in";
	if (isPractice){
		if (ProblemType == 1)f1 = ProblemC + "-small-practice.in";
		if (ProblemType == 2)f1 = ProblemC + "-large-practice.in";
	}
	else{
		if (ProblemType == 1)f1 = ProblemC + "-small-attempt1.in";
		if (ProblemType == 2)f1 = ProblemC + "-large.in";
	}
	f2 = f1.substr(0, f1.length() - 2) + "out";
	f.GetFile(f1);
	f.SetDelimeter(' ');

	tetris z1;
	zArray<zTetrisArray> zz;
	zz.SetLen(7);
	
	zz[3].Add();
	zz[3][0].init(3);
	zz[3][0].z[0][0] = '#';
	zz[3][0].z[1][0] = '#';
	zz[3][0].z[2][0] = '#';
	zz[3][0].x = 3;
	zz[3][0].y = 1;

	zz[3].Add();
	zz[3][1].init(2);
	zz[3][1].z[0][0] = '#';
	zz[3][1].z[1][0] = '#';
	zz[3][1].z[0][1] = '#';
	zz[3][1].x = 2;
	zz[3][1].y = 2;

	zz[6].Add();
	zz[6][0].init(3);
	zz[6][0].z[0][0] = '#';
	zz[6][0].z[1][0] = '#';
	zz[6][0].z[2][0] = '#';
	zz[6][0].z[0][1] = '#';
	zz[6][0].z[0][2] = '#';
	zz[6][0].z[1][2] = '#';
	zz[6][0].x = 3;
	zz[6][0].y = 3;

	int i, j, k, p, q, s;
	for (p = 4; p <= 6; p++){
		for (k = 0; k < zz[p - 1].Len(); k++){
			for (i = 0; i < zz[p - 1][k].x; i++){
				for (j = 0; j < zz[p - 1][k].y; j++){
					for (s = 0; s < 4; s++){
						if (!z1.generate(zz[p - 1][k], i, j, s))continue;
						for (q = 0; q < zz[p].Len(); q++)if (z1.isEqual(zz[p][q]))break;
						if (q == zz[p].Len())zz[p].Add() = z1;
					}
				}
			}
		}

		/*for (q = 0; q < zz[p].Len(); q++){
			for (i = 0; i < zz[p][q].x; i++){
				res.Add();
				for (j = 0; j < zz[p][q].y; j++){
					res[-1] += zz[p][q].z[i][j];
				}
			}
			res.Add() = to_string(zz[p][q].calc_S_dn()) + " " + to_string(zz[p][q].calc_S_up());
			res.Add();
		}

		res.Add() = "-----------";*/
	}

	
	T = stoi(f.z[0]);
	int row = 1;
	for (n = 0; n < T; n++){
		int X, R, C;
		bool isFill = true;
		X = f.GetIntLex(n + 1, 0);
		R = f.GetIntLex(n + 1, 1);
		C = f.GetIntLex(n + 1, 2);

		if (((R*C) % X) != 0)isFill = false;
		
		// #
		// ##   ###
		if (X == 3){
			if ((R < 2) || (C < 2))isFill = false;
			if ((R < 3) && (C < 3))isFill = false;
		}
		// #
		// ###   ####
		if (X == 4){			
			if ((R < 2) || (C < 2))isFill = false;
			if ((R < 4) && (C < 4))isFill = false;
		}
		// #
		// #
		// ###   #####
		if (X == 5){
			if ((R < 3) || (C < 3))isFill = false;
			if ((R < 5) && (C < 5))isFill = false;
		}
		// #
		// #
		// ####   ######
		if (X == 6){
			if ((R < 3) || (C < 3))isFill = false;
			if ((R < 6) && (C < 6))isFill = false;			
		}

		// ###
		// # #
		if (X >= 5)if ((R == 2) || (C == 2))isFill = false;

		// ###
		// # #
		// ##
		if (X >= 7)isFill = false;
		
		int p, w, s1, s2, i;
		bool b[2];
		if ((3 <= X) && (X <= 6)){
			for (p = 0; p < zz[X].Len(); p++){
				b[0] = b[1] = true;
				for (w = 0; w < 2; w++){
					if ((zz[X][p].x > R) || (zz[X][p].y > C))b[w] = false;

					if ((zz[X][p].x == R) && (zz[X][p].y <= C)){
						for (i = 0; i < (C - zz[X][p].y); i++){
							s1 = i*R + zz[X][p].calc_S_dn();
							s2 = (C - zz[X][p].y - i)*R + zz[X][p].calc_S_up();

							// ### 
							// # #
							// #
							if ((X == 6) && (p == 0))s2++;

							if (((s1 % X) == 0) && ((s2 % X) == 0))break;
						}
						if (i == (C - zz[X][p].y))b[w] = false;
					}
					if ((zz[X][p].x <= R) && (zz[X][p].y == C)){
						for (i = 0; i < (R - zz[X][p].x); i++){
							s1 = i*C + zz[X][p].calc_S_lf();
							s2 = (R - zz[X][p].x - i)*C + zz[X][p].calc_S_rt();

							if (((s1 % X) == 0) && ((s2 % X) == 0))break;
						}
						if (i == (R - zz[X][p].x))b[w] = false;
					}

					swap(R, C);
				}
				if ((!b[0]) && (!b[1])){
					isFill = false;
					break;
				}				
			}
		}

		res.Add() = "Case #" + to_string(n + 1) + ": ";
		if (isFill)res[-1] += "GABRIEL";
		else res[-1] += "RICHARD";
		std::cout << (n + 1) << endl;
	}
	
	f.SaveFile(f2, res);	
	std::cout << "OK ";
	getchar();
}