#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

void Open()
{
	freopen("P3.in", "r", stdin);
	freopen("P3.out", "w", stdout);
}

void Close()
{
	fclose(stdin);
	fclose(stdout);
}

int comp(string &a, string &b)
{
	if (a.length() < b.length()) return -1;
	if (a.length() > b.length()) return 1;
	for (int k = a.length() - 1; k > - 1; k--)
	{
		if (a[k] < b[k]) return -1;
		if (a[k] > b[k]) return 1;
	}
	return 0;
}

string plusLargeNum(string &a, string &b)
{
	string sum, other;
	if (comp(a, b) == 1)
		sum = a, other = b;
	else
		sum = b, other = a;
	int carry = 0;
	for (int k = 0; k < sum.length(); k++)
	{
		int da = sum[k] - 48;
		int db;
		if (k < other.length())
			db = other[k] - 48 + carry;
		else
		{
			if (carry == 0) break;
			db = carry;
		}
		int ds = da + db;
		if (ds > 9) ds -= 10, carry = 1;
		else carry = 0;
		sum[k] = ds + 48;
	}
	if (carry > 0)
		sum.append("1");
	return sum;
}

string MultiplySingle(string &a, int b)
{
	string result;
	result = a;
	int carry = 0;
	for (int k = 0; k < result.length(); k++)
	{
		int da = result[k] - 48;
		int db = b;
		int ds = da * db + carry;
		carry = ds / 10;
		ds = ds - carry * 10;
		result[k] = ds + 48;
	}
	if (carry > 0)
	{
		char tmp[2];
		tmp[0] = 48 + carry;
		tmp[1] = '\0';
		result.append(tmp);
	}
	return result;
}

string sqrLargeNum(string &num)
{
	string sum;
	for (int k = 0; k < num.length(); k++)
	{
		string tmp =  string(k, '0') + MultiplySingle(num, num[k] - 48);
		sum = plusLargeNum(tmp, sum);
	}
	return sum;
}

string sqrtLargeNum(string &num)
{
	string root;
	bool lengthFix = false;
	for (int k = num.length() - 1; k > - 1; k--)
	{
		if (lengthFix)
		{
			for (int d = 0; d < 10; d++)
			{
				root[k] = d + 48;
				string tmp = sqrLargeNum(root);
				int compresult = comp(tmp, num);
				if (compresult == 1) break;
				if (compresult == 0) return root;
			}
			root[k] = root[k] - 1;
		}
		else
		{
			string tmproot = string(k + 1, '0');
			for (int d = 1; d < 10; d++)
			{
				tmproot[k] = d + 48;
				string tmp = sqrLargeNum(tmproot);
				int compresult = comp(tmp, num);
				if (compresult == 1) break;
				if (compresult == 0) return tmproot;
			}
			if (tmproot[k] == '1') continue;
			root = tmproot;
			root[k] = root[k] - 1;
			lengthFix = true;
		}
	}
	return root;
}

int Count(int left, int lastDigit, string current, string &rootA, string &rootB)
{
	int resCount = 0;
	if (current.length() > 0)
		if (comp(current, rootA) != -1 && comp(current, rootB) != 1) 
			resCount = 1;

	if (current.length() == 0)
	{
		for (int k = rootA.length(); k <= rootB.length(); k++)
		{
			int multiply = 2;
			if (k == 1) multiply = 1;
			string ncurrent = string(k, '0');
			for (int d = 1; multiply * d * d <= left; d++)
			{
				ncurrent[0] = ncurrent[k-1] = d + 48;
				resCount += Count(left - d * d * multiply, 0, ncurrent, rootA, rootB);
			}
		}
	}
	else
	{
		for (int k = lastDigit + 1; 2 * k < current.length(); k++)
		{
			int multiply = 2;
			if ((2 * k + 1) == current.length()) multiply = 1;
			string ncurrent = current;
			for (int d = 1; multiply * d * d <= left; d++)
			{
				ncurrent[k] = ncurrent[current.length() - 1 - k] = d + 48;
				resCount += Count(left - d * d * multiply, k, ncurrent, rootA, rootB);
			}
		}
	}
	return resCount;
}

void Run()
{
	int T;
	string A, B;
	scanf ("%d\n", &T);
	for (int k = 0; k < T; k++)
	{
		char tmpA[200], tmpB[200];
		scanf ("%s %s\n", tmpA, tmpB);
		A = string(tmpA);
		B = string(tmpB);
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		string rootA = sqrtLargeNum(A);
		string rootB = sqrtLargeNum(B);
		string tmp = sqrLargeNum(rootA);
		if (comp(tmp, A) == -1) 
			rootA = plusLargeNum(rootA, string("1"));
		int result = Count(9, 0, string(), rootA, rootB);
		printf ("Case \#%d: %d\n", k+1, result);
	}
}

bool Judge(int k)
{
	char tmp[200];
	itoa(k, tmp, 10);
	int b = 0, e = strlen(tmp) - 1;
	for (; b < e; b++, e--)
		if (tmp[b] != tmp[e]) return false;
	return true;
}

void Test()
{
	for (int k = 1; k <= 10000; k++)
	{
		if (Judge(k) && Judge(k*k))
			printf ("%d %d\n", k, k*k);
	}
}

int main()
{
	Open();
	Run();
	Close();
	return 0;
}