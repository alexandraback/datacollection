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
		T *new_p;
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
};

//###################################################################

// 0 - **aa**, 1 - ***aa, 2 - aa***, 3 - aaaa, 4 - error_str

int GetStrType(string & s, char c){
	int k, st;

	if (s.length() == 1){
		if (s[0] == c)return 3;
		else return -1;
	}
	
	st = 0;
	for (k = 0; k < s.length(); k++){
		if (s[k] == c){
			if (st == 0)st = 1;
			else if (st == 2)return 4;
		}
		else if (st == 1)st = 2;
	}

	if ((s[0] == c) && (s[s.length() - 1] == c))return 3;
	if (s[0] == c)return 2;
	if (s[s.length() - 1] == c)return 1;
	if (st > 0)return 0;
	return -1;
}

__int64 Fact(int n){
	if (n == 0)return 1;
	return n*Fact(n - 1);
}

void main(){
	string f1, f2;
	zSimpleFile f;
	zStringArray res;
	int T, n;

	int ProblemType = 1;
	string ProblemC = "B";
	bool isPractice = false;

	if (ProblemType == 0)f1 = "Example.in";
	if (isPractice){
		if (ProblemType == 1)f1 = ProblemC + "-small-practice.in";
		if (ProblemType == 2)f1 = ProblemC + "-large-practice.in";
	}
	else{
		if (ProblemType == 1)f1 = ProblemC + "-small-attempt0.in";
		if (ProblemType == 2)f1 = ProblemC + "-large.in";
	}
	f2 = f1.substr(0, f1.length() - 2) + "out";

	f.GetFile(f1);
	f.SetDelimeter(' ');

	T = stoi(f.z[0]);
	for (n = 0; n < T; n++){
		int N, i;
		zStringArray z;
		
		N = stoi(f.z[2 * n + 1]);
		for (i = 0; i < N; i++)z.Add() = f.GetLex(2 * n + 2, i);
		
		int k, s = 0;
		__int64 r = 1;
		zIntArray zt;
		zt.SetLen(4); // 0 - **aa**, 1 - ***aa, 2 - aa***, 3 - aaaa
		char c;
		bool cor = true;
		
		for (c = 'a'; (c <= 'z') && cor; c++){
			for (i = 0; i < 4; i++)zt[i] = 0;
			for (i = 0; i < z.Len();){
				k = GetStrType(z[i], c);
				if (k == 4)cor = false;
				if ((0 <= k) && (k <= 3))zt[k]++;
				if (k == 3)z.Delete(i);
				else i++;
			}
			for (i = 1; i <= 2; i++)if (zt[i] > 1)cor = false;
			for (i = 1; i <= 3; i++)if ((zt[i] > 0) && (zt[0] > 0))cor = false;
			r *= Fact(zt[3]);
			
			if ((zt[1] == 0) && (zt[2] == 0) && (zt[3] > 0))s++;
			if ((zt[1] == 1) && (zt[2] == 1)){
				for (i = 0; i < z.Len(); i++){
					if (GetStrType(z[i], c) == 1)zt[1] = i;
					if (GetStrType(z[i], c) == 2)zt[2] = i;
				}
				z[zt[1]] += z[zt[2]];
				z.Delete(zt[2]);
			}
		}
		r *= Fact(z.Len() + s);

		res.Add() = "Case #" + to_string(n + 1) + ": ";
		if (!cor)res[-1] += "0";
		else res[-1] += to_string(r);
		cout << (n + 1) << endl;
	}
	
	f.SaveFile(f2, res);	
	cout << "OK ";
	getchar();
}