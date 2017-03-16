#include <fstream>
#include <iostream>

using namespace std;

int A, B, C;
ifstream input;
ofstream output;

void fast()
{
	for (int i=0; i<7; i++)
	{
		for (int j=0; j<8; j++) cout << (i & j) << ' ';
		cout<< endl;
	}
}

long long zn(int a, int b, int c, int digit)
{
	//if (c==0) return (a+b+1);

	if (digit==1)
	{
		if (c==0) return (a+b+1);
		return (a+1) * (b+1);
	}

	int x = a & digit; int na = a - x;
	int y = b & digit; int nb = b - y;
	int z = c & digit; int nc = c - z;
	if (z==0) 
	{
		if (x==0 && y==0) return zn(na, nb, nc, digit>>1);
		if (x!=0 && y!=0) return zn(digit-1, digit-1, nc, digit>>1) + zn(na, digit-1, nc, digit>>1) + zn(digit-1, nb, nc, digit>>1);
		if (x!=0 && y==0) return zn(na, nb, nc, digit>>1) + zn(digit-1, nb, nc, digit>>1);
		return zn(na, nb, nc, digit>>1) + zn(na, digit-1, nc, digit>>1);
	}
	if (x==0 || y==0) return (a+1) * (long long)(b+1);
	return zn(na,nb,nc,digit>>1) + (na+1) * (long long) digit + (nb+1) * (long long)digit + (long long)digit * digit;
}

void singleCase(int Case)
{
	output << "Case #" << Case << ": ";
	A--; B--; C--;
	output << zn(A, B, C, 1 << 30) << endl;
}

int main()
{
	//fast();
	int T;
	input.open("B.in");
	output.open("B.out");
	input >> T;
	for (int i=0; i<T; i++)
	{
		input >> A >> B >> C;
		singleCase(i+1);
	}
	return 0;
}