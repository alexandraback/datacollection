#include<iostream>
#include<string>
#include<fstream>
#include <queue> 
using namespace std;
char multiply(char a,char b,bool& neg)
{
	vector< vector<char> >map
	{{ '1', 'i', 'j', 'k' },
	{ 'i', '1', 'k', 'j' },
	{ 'j', 'k', '1', 'i' },
	{ 'k', 'j', 'i', '1' }};
	vector< vector<bool> >map1
	{{ 0, 0, 0, 0 },
	{ 0, 1, 0, 1 },
	{ 0, 1, 1, 0 },
	{ 0, 0, 1, 1}};
	int indexa = 0,indexb=0;
	switch (a)
	{
	case '1':indexa = 0; break;
	case 'i':indexa = 1; break;
	case 'j':indexa = 2; break;
	case 'k':indexa = 3; break;
	default:break;
	}
	switch (b)
	{
	case '1':indexb = 0; break;
	case 'i':indexb = 1; break;
	case 'j':indexb = 2; break;
	case 'k':indexb = 3; break;
	default:break;
	}
	neg = neg^map1[indexa][indexb];
	return map[indexa][indexb];

}
int main()
{
	int t, smax = 0;
	vector<vector<int>>({});
	ifstream infile("large.in");
	ofstream outfile("large.out1");

	infile >> t;
	//cin >> t;
	for (int index = 0; index < t; index++)
	{
		int l, x;
		string str;
		infile >> l >> x;
		infile >> str;
		int formI=-1;
		int formJ=-1;
		char last='1';
		bool lastneg=false;
		while (x-4 > 4){ x -= 4; }
		for (int i = 0; i < l*x; i++)
		{
			char r = multiply(last,str[i%l], lastneg);
			last = r;
			if (r == 'i'&&lastneg == false){ formI = i; break; }
		}
		last = '1';
		lastneg = false;
		
		for (int i = l*x-1; i >formI; i--)
		{
			char r = multiply(str[i%l],last, lastneg);
			last = r;
			if (r == 'k'&&lastneg == false){ formJ = i; break; }
		}

		bool flag = false;
		if (formI == -1 || formJ == -1){ flag = false; }
		else
		{
			last = '1';
			lastneg = false;
			for (int k = formI+1; k <= formJ-1; k++)
			{
				char r = multiply(last, str[k%l], lastneg);
				last = r;
				
			}
			if (last == 'j'&&lastneg == false){ flag = true;}

		}
	
		if (flag)outfile << "Case #" << index + 1 << ": " << "YES" << endl;
		else outfile << "Case #" << index + 1 << ": " << "NO" << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}