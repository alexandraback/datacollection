#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

char* sum (char* a, char * b);
char* mult(char* a, char* b);
bool isless(char* a, char* b);

bool isPalindrome(char* a);
void Test(int caseNum);
void GenPolindrom(int digitNum);

char A[200], B[200];
int result;

int main()
{
	int num;

	fin >> num;
	fin.getline(A, 10);
	for (int i = 0; i < num; i++)
	{
		fin.getline(A, 200,' ');
		fin.getline(B, 200);
		result = 0;
		Test(i+1);
	}

	return 0;
}

void Check(char *a)
{
	char* b = mult(a, a);
	if (isPalindrome(b))
	{
		if (isless(b, A))
			return;
		if (isless(B, b))
			return;

		result ++;
		//cout << a << endl;
	}
}


void Construct(char * a, bool odd)
{
	int alen = strlen(a);
	int add = 0;
	if (odd) add++;
	char* palindrome = new char[alen * 2 + 1 + add];
	for (int i=0; i < alen; i++)
	{
		palindrome[i] = a[i];
		palindrome[alen * 2 + add - i - 1] = a[i];
	}

	palindrome[alen*2 + add] = 0;
	if (odd)
	{
		palindrome[alen] = '0';
		Check(palindrome);
		palindrome[alen] = '1';
		Check(palindrome);
		palindrome[alen] = '2';
		Check(palindrome);
	}else{
		Check(palindrome);
	}

	delete [] palindrome;
}


void GenPolindromLine(int digitNum, bool odd)
{
	if (digitNum == 0)
	{
		Check("1");
		Check("2");
		Check("3");

		return;
	}

	char *a = new char[digitNum+1];
	int i,r,j;
	for (i = 0; i < digitNum; i++)
	{
		a[i] = '0';
	}
	a[i] = 0;

	a[0] = '2';
	Construct(a, odd);
	
	a[0] = '1';

	Construct(a, odd);
	for (i = 1; i < digitNum; i++)
	{
		a[i] = '1';
		Construct(a, odd);
		for (r = i+1; r < digitNum;r++)
		{
			a[r] = '1';
			Construct(a, odd);
			for(j = r+1; j < digitNum; j++)
			{
				a[j] = '1';
				Construct(a, odd);
				a[j] = '0';
			}
			a[r] = '0';
		}
		a[i] = '0';
	}

	delete[] a;
}

void GenPolindrom(int digitNum)
{
	if (digitNum == 0) return;
	if (digitNum % 2 == 0)
	{
		GenPolindromLine(digitNum / 2, false);
	} else {
		GenPolindromLine(digitNum / 2, true);
	}
}


void Test(int caseNum)
{
	

	//if (isless(B, A))
	//{
	//	fout << "Case #" << caseNum << ": 0" << endl;
	//}
	int aLen = strlen(A);
	int bLen = strlen(B);
	int aLenHalf = aLen /2 ;
	int bLenHalf = bLen /2 +1;
	int i, r;

	for (int i = aLenHalf; i <= bLenHalf; i++)
	{
		GenPolindrom(i);
	}

	fout << "Case #" << caseNum << ": " << result << endl;
}

bool isless(char* a, char* b)
{
	int aLen = strlen(a);
	int bLen = strlen(b);
	if (aLen < bLen)
		return true;
	if (aLen > bLen)
		return false;

	for (int i = 0; i < aLen; i++)
	{
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;
	}
	return false;
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

bool isPalindrome(char * a)
{
	int len = strlen(a);
	int half = len * 0.5;
	for (int i = 0; i < half; i++)
	{
		if (a[i] != a[len - i - 1])
			return false;
	}

	return true;
}

char* sum (char* a, char * b)
{
	int i,r;
	int aLen, bLen;

	aLen = strlen(a);
	bLen = strlen(b);

	int maxLen = max(aLen, bLen);

	char* c = new char[maxLen + 2];

	char x,y;
	int add = 0;
	for (i = 0; i < maxLen; i++)
	{
		x = 0; y = 0;
		if (i < aLen)
			x = a[i] - '0';
		if (i < bLen)
			y = b[i] - '0';

		c[i] = x + y + add + '0';
		add = 0;
		if (c[i] > '9')
		{
			add = 1;
			c[i] = c[i] - 10;
		}
	}
	if (add == 1)
	{
		c[i] = '1';
		i++;
	}
	c[i] = 0;
	

	return c;
}

char* mult(char* a, char* b)
{
	int i,r;
	int aLen, bLen;

	aLen = strlen(a);
	bLen = strlen(b);

	char *c = new char[aLen+bLen+2];
	char *s;
	int maxLen = max(aLen, bLen);
	c[0] = '0';
	c[1] = 0;
	int x, y;
	int add;
	for (i = 0; i < bLen; i++)
	{
		char *t = new char[i+aLen+2];
		for (r = 0; r < i;r ++)
			t[r] = '0';
		x = b[i] - '0';
		add = 0;
		for (r = 0; r < aLen; r++)
		{
			y = a[r] - '0';
			t[i+r] = x * y + add;
			add = 0;
			while (t[i+r] > 9)
			{
				t[i+r] = t[i+r] - 10;
				add++;
			}
			t[i+r] += '0';
		}
		if (add > 0)
		{
			t[i+r] = add + '0';
			r++;
		}
		t[i+r] = 0;


		s = sum (c, t);
		delete[] c;
		delete[] t;
		c = s;
	}

	return c;
}
