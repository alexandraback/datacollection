#include <iostream>
#include <string>
#include <vector>

using namespace std;

// x = -i, y = -j, z = -k, a = 1, b = -1
char calc(char& a, char& b)
{
	if (a == 'a') return b;
	else if (a == 'b')
	{
		switch (b)
		{
			case 'a': return 'b';
			case 'b': return 'a';
			case 'i': return 'x';
			case 'j': return 'y';
			case 'k': return 'z';
			case 'x': return 'i';
			case 'y': return 'j';
			case 'z': return 'k';
		}
	}
	else if (a == 'i')
	{
		switch (b)
		{
			case 'a': return 'i';
			case 'b': return 'x';
			case 'i': return 'b';
			case 'j': return 'k';
			case 'k': return 'y';
			case 'x': return 'a';
			case 'y': return 'z';
			case 'z': return 'j';
		}
	}
	else if (a == 'j')
	{
		switch (b)
		{
			case 'a': return 'j';
			case 'b': return 'y';
			case 'i': return 'z';
			case 'j': return 'b';
			case 'k': return 'i';
			case 'x': return 'k';
			case 'y': return 'a';
			case 'z': return 'x';
		}
	}
	else if (a == 'k')
	{
		switch (b)
		{
			case 'a': return 'k';
			case 'b': return 'z';
			case 'i': return 'j';
			case 'j': return 'x';
			case 'k': return 'b';
			case 'x': return 'y';
			case 'y': return 'i';
			case 'z': return 'a';
		}
	}
	else if (a == 'x')
	{
		switch (b)
		{
			case 'a': return 'x';
			case 'b': return 'i';
			case 'i': return 'a';
			case 'j': return 'z';
			case 'k': return 'j';
			case 'x': return 'b';
			case 'y': return 'k';
			case 'z': return 'y';
		}
	}
	else if (a == 'y')
	{
		switch (b)
		{
			case 'a': return 'y';
			case 'b': return 'j';
			case 'i': return 'k';
			case 'j': return 'a';
			case 'k': return 'x';
			case 'x': return 'z';
			case 'y': return 'b';
			case 'z': return 'i';
		}
	}
	else if (a == 'z')
	{
		switch (b)
		{
			case 'a': return 'z';
			case 'b': return 'k';
			case 'i': return 'y';
			case 'j': return 'i';
			case 'k': return 'a';
			case 'x': return 'j';
			case 'y': return 'x';
			case 'z': return 'b';
		}
	}
	return 'a';
}

bool mCalc(string in)
{
	if (in.size() < 3) return false;
	bool fI = false, fJ = false, fK = false;// found i, j, k
	bool proc;
	size_t i = 1;
	char temp = in[0];
	while (i < in.size())
	{
		// cout << temp << endl;
		proc = true;
		if (temp == 'i' && fI == false)
		{
			fI = true;
			temp = in[i];
			i++;
			proc = false;
		}
		if (temp == 'j' && fJ == false && fI == true)
		{
			fJ = true;
			temp = in[i];
			i++;
			proc = false;
		}
		if (temp == 'k' && fK == false && fI == true && fJ == true)
		{
			fK = true;
			if (i >= in.size())
			{
				return true;
			}
			temp = in[i];
			i++;
			proc = false;
		}
		if (proc)
		{	
			temp = calc(temp, in[i]);
			i++;
		}
		
		if (temp == 'i' && fI == false)
		{
			fI = true;
			temp = in[i];
			i++;
		}
		if (temp == 'j' && fJ == false && fI == true)
		{
			fJ = true;
			temp = in[i];
			i++;
		}
		if (temp == 'k' && fK == false && fI == true && fJ == true)
		{
			fK = true;
			if (i + 1 >= in.size()) return true;
			temp = in[i];
			i++;
		}
	}
	return fI && fJ && fK && temp == 'a';
}

int main()
{
	int totalcase = 0;
	cin >> totalcase;

	bool output[totalcase];
	for (int i = 0; i < totalcase; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		string str = "", finStr = "";
		cin >> str;
		for (int i = 0; i < b; i++)
		{
			finStr += str;
		}
		output[i] = mCalc(finStr);
	}

	for (int i = 0; i < totalcase; i++)
	{
		if (output[i] == true) cout << "Case #" << (i + 1) << ": " << "YES" << endl;
		else cout << "Case #" << (i + 1) << ": " << "NO" << endl;
	}
	return 0;
}
