#include <iostream>
#include <string>
#include <string>
#include <fstream>

using namespace std;

int mat[1001][1001];

void fillmat()
{
	for (size_t i = 1; i < 1001; i++)
	{
		for (size_t j = 0; j <= i; j++)
			mat[j][i] = 0;
		for (size_t j = i + 1; j < 1001; j++)
		{
			mat[j][i] = 2001;
			for (size_t k = 1; k < j / 2 + 1; k++)
				if (mat[k][i] + mat[j - k][i] + 1 < mat[j][i])
					mat[j][i] = mat[k][i] + mat[j - k][i] + 1;
		}

	}
}

int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/B-large.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output4.txt");

	ifile >> T;

	fillmat();

	for (size_t i = 0; i < T; i++)
	{
		int d;
		int p[3001];

		ifile >> d;

		for (size_t j = 0; j < d; j++)
			ifile >> p[j];

		int ans = 2000;

/*		for (size_t j = 0; j < 1001; j++)
		{
			int maxind = 0;
			for (size_t k = 1; k < d; k++)
				if (p[maxind] < p[k])
					maxind = k;

			if (j + p[maxind] < ans)
				ans = j + p[maxind];

			p[d] = p[maxind] / 2;
			p[maxind] = p[maxind] % 2 + p[maxind] / 2;
			d++;

		}*/

		for (size_t j = 1; j < 1002; j++)
		{
			int cur_ans = 0;
			for (size_t k = 0; k < d; k++)
				cur_ans += mat[p[k]][j];

			if (cur_ans+j < ans)
				ans = cur_ans+j;
		}

		ofile << "Case #" << i + 1 << ": "<< ans << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}

/*
int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/D-small-attempt0.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output3.txt");

	ifile >> T;

	for (size_t i = 0; i < T; i++)
	{
		int x, r, c, min, max;

		ifile >> x >> r >> c;

		min = r < c ? r : c;
		max = r > c ? r : c;

		if (min*max % x != 0)
			ofile << "Case #" << i + 1 << ": RICHARD" << endl;
		else
		{
			if (min == 1)
			{
				if (x <= 2)
					ofile << "Case #" << i + 1 << ": GABRIEL" << endl;
				else
					ofile << "Case #" << i + 1 << ": RICHARD" << endl;
			} else
			if (min == 2)
			{
				if (x <= 3)
					ofile << "Case #" << i + 1 << ": GABRIEL" << endl;
				else
					ofile << "Case #" << i + 1 << ": RICHARD" << endl;
			} else
				ofile << "Case #" << i + 1 << ": GABRIEL" << endl;
		}
	}

	ifile.close();
	ofile.close();

	return 0;
}


int mat[16] = {0, 1, 2, 3, 
			   1, 0, 3, 2,
			   2, 3, 0, 1,
			   3, 2, 1, 0};

int signmat[16] = { 1, 1, 1, 1,
					1,-1, 1,-1,
					1,-1,-1, 1,
					1, 1,-1,-1 };

int divsign[16] = { 1,-1,-1,-1,
					1, 1, 1,-1,
					1,-1, 1, 1,
					1, 1,-1, 1 };

int mul[200001];
int muls[200001];
int l;
int rsize = 0;

int icc[10001];

void mnog(int a, int as, int b, int bs, int& c, int& cs)
{
	c = mat[4 * a + b];
	cs = signmat[4 * a + b] * as*bs;
}

void div(int a, int as, int b, int bs, int& c, int& cs)
{
	c = mat[4 * a + b];
	cs = divsign[4 * a + b]*as*bs;
}

void compmul()
{
	mul[0] = 0;
	muls[0] = 1;
	for (size_t i = 1; i <= rsize+1; i++)
		mnog(mul[i-1], muls[i-1], icc[(i-1)%l], 1, mul[i], muls[i]);
}

void mulmnog(int be, int en, int &c, int& cs)
{
	div(mul[en + 1], muls[en + 1], mul[be], muls[be], c, cs);
}

int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/C-small-attempt2.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output2.txt");

	ifile >> T;

	for (size_t i = 0; i < T; i++)
	{
		long long x;
		ifile >> l >> x;

		string cc;
		ifile >> cc;

		for (size_t j = 0; j < l; j++)
		{
			if (cc.at(j) == 'i') icc[j] = 1;
			if (cc.at(j) == 'j') icc[j] = 2;
			if (cc.at(j) == 'k') icc[j] = 3;
		}

		if (x < 16)
			rsize = l*x;
		else
			rsize = (8+x%4) * l;

		if (rsize < 3)
		{
			ofile << "Case #" << i + 1 << ": NO" << endl;
			continue;
		}

		compmul();

		bool tt = false;
		for (size_t i1 = 0; (i1 < rsize - 2 && i1 <= 4*l+2); i1++)
		{
			int c, cs;
			mulmnog(0, i1, c, cs);
			if (c == 1 && cs == 1)
				for (size_t i2 = i1 + 1; (i2 < rsize - 1 && i2-i1<= 5*l+2); i2++)
				if (!tt)
				{
					mulmnog(i1+1, i2, c, cs);
					if (c == 2 && cs == 1)
					{
						mulmnog(i2+1, rsize-1, c, cs);
						if (c == 3 && cs == 1)
						{
//							cout << i+1 << " " <<  i1 << " " << i2 << endl;
							tt = true;
							break;
						}
					}
				}
			if (tt)
				break;
		}

		if (tt)
			ofile << "Case #" << i + 1 << ": YES" << endl;
		else
			ofile << "Case #" << i + 1 << ": NO" << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}



int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/A-large.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output1.txt");

	ifile >> T;

	for (size_t i = 0; i < T; i++)
	{
		int ss;
		ifile >> ss;

		string cc;
		ifile >> cc;

		int cur_stand = int(cc.at(0) - '0');
		int ans = 0;
		for (size_t j = 1; j <= ss; j++)
		{
			if (int(cc.at(j) - '0') > 0 && cur_stand < j)
			{
				ans += j - cur_stand;
				cur_stand += j - cur_stand;
			}

			cur_stand += int(cc.at(j) - '0');
		}

		ofile << "Case #" << i+1 << ": " << ans << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}

*/