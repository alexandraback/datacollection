#include <fstream>
#include <iostream>

using namespace std;

bool ifNegative(int input)
{
	return input>=5;
}

int addNegative(int input)
{
	if(input >= 5)
		return input - 4;
	else
		return input + 4;
}

int table[10][10];
int L, X;
int letters[10010];
//1->1, i->2,j->3,k->4;
//-1->5,-i->6,-j->7,-k->8.
void tableSetup()
{
	for(int i=1;i<=4;i++)
	{
		table[1][i] = i;
		table[i][1] = i;
	}
	table[2][2] = 5;
	table[3][3] = 5;
	table[4][4] = 5;
	table[2][3] = 4;
	table[2][4] = 7;
	table[3][2] = 8;
	table[3][4] = 2;
	table[4][2] = 3;
	table[4][3] = 6;
	for(int i=1;i<=8;i++)
	{
		bool a = ifNegative(i);
		for(int j=1;j<=8;j++)
		{
			bool b = ifNegative(j);
			if(a && b)
				table[i][j] = table[i-4][j-4];
			else if(a && !b)
				table[i][j] = addNegative(table[i-4][j]);
			else if(!a && b)
				table[i][j] = addNegative(table[i][j-4]);
		}
	}
}

int multiply(int a, int b)
{
	return table[a][b];
}

int getijk(int index)
{
	return letters[index % L];
}

int getProduct(int first, int last)
{
	if(first > last)
	{
		cout << "Error: getProduct" << endl;
		return -1;
	}
	int result = getijk(first);
	for(int i=first+1;i<=last;i++)
		result = table[result][getijk(i)];
	return result;
}

bool computeResult()
{
	int length = L * X;
	if(length < 3)
		return false;
	int tmp1 = 1, tmp2 = 1;
	for(int i=0;i<length-2;i++)
	{
		cout << "Index_i:   " << i << endl;
		tmp1 = table[tmp1][getijk(i)];
		if(tmp1 == 2)
		{
			tmp2 = 1;
			for(int j=i+1;j<length-1;j++)
			{
				tmp2 = table[tmp2][getijk(j)];
				if(tmp2 == 3)
				{
					if(getProduct(j+1, length-1) == 4)
						return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	ifstream istr("test");
	ofstream ostr("out");
	tableSetup();
	int T;
	istr >> T;
	for(int casenum=1;casenum<=T;casenum++)
	{
		ostr << "Case #" << casenum << ": ";
		istr >> L >> X;
		char ch;
		istr.get();
		for(int i=0;i<L;i++)
		{
			ch = istr.get();
			if(ch == 'i')
				letters[i] = 2;
			else if(ch == 'j')
				letters[i] = 3;
			else
				letters[i] = 4;
		}
		cout << endl;
		if(computeResult())
			ostr << "YES" << endl;
		else
			ostr << "NO" << endl;
	}
	/*tableSetup();
	L = 3;
	for(int i=0;i<L;i++)
	{
		char ch = istr.get();
			if(ch == 'i')
				letters[i] = 2;
			else if(ch == 'j')
				letters[i] = 3;
			else
				letters[i] = 4;
			//cout << letters[i];
	}
	cout << "yes";
	cout << getProduct(0,2) << endl;
	//cout << multiply(4, 3) << endl;*/
	return 0;
}