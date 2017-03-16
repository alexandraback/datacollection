#include <fstream>
#include <string>
using namespace std;
typedef long long int64;


enum QUTERNION
{
	Q_1 = 0,
	Q_I,
	Q_J,
	Q_K,
	Q_MINUS_1,
	Q_MINUS_I,
	Q_MINUS_J,
	Q_MINUS_K
};


QUTERNION multiply(const QUTERNION &a, const QUTERNION &b)
{
	static const QUTERNION MINUS[8]  = {Q_MINUS_1, Q_MINUS_I, Q_MINUS_J, Q_MINUS_K, Q_1, Q_I, Q_J, Q_K};
	static const QUTERNION MULT[][4] = { {Q_1,          Q_I,          Q_J,    Q_K      },
								         {Q_I,    Q_MINUS_1,          Q_K,    Q_MINUS_J},
	                                     {Q_J,    Q_MINUS_K,    Q_MINUS_1,    Q_I      },
	                                     {Q_K,          Q_J,    Q_MINUS_I,    Q_MINUS_1} };
	int			sign = 1;
	QUTERNION	x, y, z;

	x = a;
	if (x > 3)
	{
		x		= MINUS[x];
		sign   *= -1;
	}

	y = b;
	if (y > 3) 
	{
		y	    = MINUS[y];
		sign   *= -1;
	}

	z = MULT[x][y];
	if (sign != 1) z = MINUS[z];

	return z;
}


string solve(string &s, int64 K)
{
	QUTERNION		p, totalP;
	string			ss;
	int64			KK;
	int				index1, index2;

	p = Q_1;
	for (int i = 0; i < s.size(); i++)
		p = multiply(p, (QUTERNION)(s[i] - 'i' + 1));

	totalP = Q_1;
	for (int i = 0; i < K % 4; i++)
		totalP = multiply(totalP, p);

	if (totalP != Q_MINUS_1) return "NO";

	ss = s;
	KK = K;
	if (p != Q_MINUS_1)
	{
		ss += s;
		KK /= 2;
	}

    if (KK >= 5)
	{
		ss	= ss + ss + ss + ss + ss;
		KK -= 4;
	}
	else if (KK == 3)
	{
		ss  = ss + ss + ss;
		KK -= 2; 
	}

	p = Q_1;
	for (index1 = 0; index1 < ss.size(); index1++)
	{
		p = multiply(p, (QUTERNION)(ss[index1] - 'i' + 1));
		if (p == Q_I) break;
	}
	if (index1 == ss.size()) return "NO";

	p = Q_1;
	for (index2 = ss.size() - 1; index2 >= 0; index2--)
	{
		p = multiply((QUTERNION)(ss[index2] - 'i' + 1), p);
		if (p == Q_K) break;
	}
	if (index2 < 0) return "NO";

	return (index1 < index2) ? "YES" : "NO";
}


int main()
{
	ifstream		f("in.txt");
	ofstream		g("out.txt");
	int				testCount;
	int				N;
	int64			K;
	string			s;

	f >> testCount;
	for (int test = 1; test <= testCount; test++)
	{
		f >> N >> K >> s;
		g << "Case #" << test << ": " << solve(s, K) << endl;
	}

	return 0;
}