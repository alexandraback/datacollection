#include <fstream>
#include <iostream>
using namespace std;

int times[4][4] = {
		{1, 2, 3, 4},
		{2, -1, 4, -3},
		{3, -4, -1, 2},
		{4, 3, -2, -1}
};
char toChar[5] = {'0', '1', 'i', 'j', 'k'};
char s[10001];
int pos = 0;
ofstream out("out");

int time(int t, int v)
{
	int tmp = 1;
	bool neg = t * v < 0;
	tmp = times[abs(t) - 1][abs(v) - 1];
	tmp = neg ? -tmp : tmp;
	//out << tmp << ' ' << abs(t) - 1 << ' ' << abs(v) - 1 << endl;
	return tmp;
}

int number(char c)
{
	switch(c){
	case 'i':
		return 2;
	case 'j':
		return 3;
	case 'k':
		return 4;
	}
}

void fd(char c, bool &fc, long long &pc, int l){
	int turn = 4;
	int tmp = 1;
	while (turn > 0 && (!fc))
	{
		long long pp = pos % l;
		//out << pp << ' ' << tmp << ' ' << pos << endl;
		tmp = time(tmp, s[pp]);
		if (tmp == number(c))
		{
			fc = true;
			pc = pos;
		}
		pos++;
		if (pp == l - 1)
			turn--;
	}
}

int main(){
	ifstream in("C-large.in");
	int t;
	in >> t;
	//out << t << endl;
	for (int z = 1 ; z <= t ; z++)
	{
		long long x;
		int l;
		in >> l >> x;
		pos = 0;
		//out << l << ' ' << x << endl;
		for (int i = 0 ; i < l ; i++)
		{
			s[i] = 1;
			char tmp;
			in >> tmp;
			s[i] = number(tmp);
			//out << number(tmp) << ' ';
		}
		//out << endl;
		long long PMax = l * x;
		bool fa = false, fb = false, fc = false;
		long long pa = 0, pb = 0, pc = 0;
		fd('i', fa, pa, l);
		//out << "A " << fa << ' ' << pa << endl;
		fd('j', fb, pb, l);
		//out << "B " << fb << ' ' << pb << endl;
		fd('k', fc, pc, l);
		//out << "C " << fc << ' ' << pc << endl;
		int tmp = 1;
		while (pos % l != 0)
		{
			long long pp = pos % l;
			tmp = time(tmp, s[pp]);
			pos++;
		}
		int r = 1;
		for (int i = 0 ; i < l ; i++)
		{
			r = time(r, s[i]);
		}
		long long resX = ((PMax - pc - 1) / l) % 4;
		int remain = 1;
		//out << "R " << r << ' ' << resX << endl;
		for (int i = 0 ; i < resX ; i++)
		{
			remain = time(remain, r);
		}
		//out << "R " << remain << ' ' << tmp << endl;
		remain = time(remain, tmp);
		bool test = (remain == 1 && fa && fb && fc && pc < PMax);
		if (test)
			out << "Case #" << z << ": YES" << endl;
		else
			out << "Case #" << z << ": NO" << endl;
	}
	in.close();
	out.close();
	return 0;
}
