#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

   long long n,t, k, res, proj=0, kolsogl=0;

int  main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int i=1; i<=t; i++)
	{
		int X, Y;
		string s;
		cin >> X >> Y;
		cout << "Case #" << i << ": ";
		if (X>0)
		{
			for (int j=0; j<X; j++)
			{
				cout << "WE";
			}
		}
		else
		{
			for (int j=0; j>X; j--)
			{
				cout << "EW";
			}
		}
		if (Y>0)
		{
			for (int j=0; j<Y; j++)
			{
				cout << "SN";
			}
		}
		else
		{
			for (int j=0; j>Y; j--)
			{
				cout << "NS";
			}
		}



		cout << "\n";
	}



	

 //  int kol234;
 //  cin >> kol234;
}



//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);






/*
   long long n,t, k, res, proj=0, kolsogl=0;

int  main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int i=1; i<=t; i++)
	{
		res=0;
		proj=0;
		kolsogl=0;
		string s;
		cin >> s;
		cin >> n;
		long long len=s.size();
		for (long long j=0; j<len; j++)
		{
			if (s[j]!='a' && s[j]!='u' && s[j]!='e' && s[j]!='i' && s[j]!='o')
			{
				kolsogl++;
			}
			else
			{
				kolsogl=0;
			}
			if (kolsogl==n)
			{
				kolsogl--;
				res+=(j-n-proj+2)*(len-j);
				proj=j-n+2;
			}

		}




		cout << "Case #" << i << ": " << res << "\n";
	}



	

 //  int kol234;
 //  cin >> kol234;
}
 */