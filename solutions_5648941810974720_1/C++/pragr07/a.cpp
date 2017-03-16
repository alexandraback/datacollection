#include <bits/stdc++.h>
using namespace std;

int min4(int a,int b, int c, int d)
{
	return min(min(min(a, b), c), d);
}

int min3(int a,int b, int c)
{
	return min(min(a, b), c);
}

int min5(int a,int b, int c, int d, int e)
{
	return min(min(min(min(a, b), c), d), e);
}

int main()
{
	int t, i, j, alpha[30], Count[11], req, a;
	string s;

	cin>>t;
	a=1;
	while(t--)
	{
		cin>>s;
		memset(alpha, 0, 4*30);
		memset(Count, 0, 4*11);
		for(i=0; i<s.length(); i++)
		{
			alpha[s[i]-'A'] = alpha[s[i]-'A'] + 1;
		}

		//0 

		req = min4(alpha[25],alpha[4],alpha['R'-'A'],alpha['O'-'A']);
		Count[0] = req;
		alpha['Z'-'A'] = alpha['Z'-'A'] - req;
		alpha['E'-'A'] = alpha['E'-'A'] - req;
		alpha['R'-'A'] = alpha['R'-'A'] - req;
		alpha['O'-'A'] = alpha['O'-'A'] - req;

		//2
		req = min3(alpha['T'-'A'],alpha['W'-'A'],alpha['O'-'A']);
		Count[2] = req;
		alpha['T'-'A'] = alpha['T'-'A'] - req;
		alpha['W'-'A'] = alpha['W'-'A'] - req;
		alpha['O'-'A'] = alpha['O'-'A'] - req;

		//4
		req = min4(alpha['F'-'A'],alpha['O'-'A'],alpha['U'-'A'],alpha['R'-'A']);
		Count[4] = req;
		alpha['F'-'A'] = alpha['F'-'A'] - req;
		alpha['U'-'A'] = alpha['U'-'A'] - req;
		alpha['R'-'A'] = alpha['R'-'A'] - req;
		alpha['O'-'A'] = alpha['O'-'A'] - req;

		//6
		req = min3(alpha['S'-'A'],alpha['I'-'A'],alpha['X'-'A']);
		Count[6] = req;
		alpha['S'-'A'] = alpha['S'-'A'] - req;
		alpha['I'-'A'] = alpha['I'-'A'] - req;
		alpha['X'-'A'] = alpha['X'-'A'] - req;

		//8
		req = min5(alpha['E'-'A'],alpha['I'-'A'],alpha['G'-'A'],alpha['H'-'A'], alpha['T'-'A']);
		Count[8] = req;
		alpha['G'-'A'] = alpha['G'-'A'] - req;
		alpha['E'-'A'] = alpha['E'-'A'] - req;
		alpha['I'-'A'] = alpha['I'-'A'] - req;
		alpha['H'-'A'] = alpha['H'-'A'] - req;
		alpha['T'-'A'] = alpha['T'-'A'] - req;
		
		//7
		req = min4(alpha['S'-'A'],alpha['V'-'A'],alpha['N'-'A'],(alpha['E'-'A']/2));
		Count[7] = req;
		alpha['S'-'A'] = alpha['S'-'A'] - req;
		alpha['E'-'A'] = alpha['E'-'A'] - 2*req;
		alpha['V'-'A'] = alpha['V'-'A'] - req;
		alpha['N'-'A'] = alpha['N'-'A'] - req;

		//5
		req = min4(alpha['F'-'A'],alpha['I'-'A'],alpha['V'-'A'],alpha['E'-'A']);
		Count[5] = req;
		alpha['F'-'A'] = alpha['F'-'A'] - req;
		alpha['E'-'A'] = alpha['E'-'A'] - req;
		alpha['I'-'A'] = alpha['I'-'A'] - req;
		alpha['V'-'A'] = alpha['V'-'A'] - req;

		//1
		req = min3(alpha['O'-'A'],alpha['N'-'A'],alpha['E'-'A']);
		Count[1] = req;
		alpha['N'-'A'] = alpha['N'-'A'] - req;
		alpha['E'-'A'] = alpha['E'-'A'] - req;
		alpha['O'-'A'] = alpha['O'-'A'] - req;
	
		//3
		req = min4(alpha['T'-'A'],alpha['H'-'A'],alpha['R'-'A'],(alpha['E'-'A']/2));
		Count[3] = req;
		alpha['T'-'A'] = alpha['T'-'A'] - req;
		alpha['E'-'A'] = alpha['E'-'A'] - 2*req;
		alpha['R'-'A'] = alpha['R'-'A'] - req;
		alpha['H'-'A'] = alpha['H'-'A'] - req;
		
		//9
		req = min3(alpha['I'-'A'],alpha['E'-'A'],(alpha['N'-'A']/2));
		Count[9] = req;
		alpha['N'-'A'] = alpha['N'-'A'] - 2*req;
		alpha['I'-'A'] = alpha['I'-'A'] - req;
		alpha['E'-'A'] = alpha['E'-'A'] - req;
		
		cout<<"Case #"<<a<<": ";
		for(i=0; i<=9; i++)
		{
			for(j=0; j<Count[i]; j++)
				cout<<i;
		}
		cout<<endl;
		a++;

	}
	return 0;
}