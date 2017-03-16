#include <iostream>
#include <fstream>
#include <cstdlib>
#include<string>
#include<vector>
#include<cmath>
#include <sstream>
#include <bitset>

using namespace std;



#define lp(i,n) for(i=0; i<n ; i++)
#define lp1(i,n) for(i=0; i<n ; i++)
#define lpI(i,a,b) for(i = a; )

#define lp(i,n) for (i=0; i<n; i++)
#define lp1(i,n) for (i=1; i<=n; i++)
#define lpi(i,a,b) for (i=a; i<=b; i++)
#define lpr(i,n) for (i=(n)-1; i>=0; i--)
#define lpr1(i,n) for (i=n; i>0; i--)
#define lpri(i,a,b) for (i=b; i>=a; i--)
#define lop(i, n)  for(int i=0; i<n ; i++)
#define lop1(i, n)  for(int i=1; i<n ; i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define ull unsigned long long 


char ctemp;
ull temp = 0;

string stemp;

string word = "";


void docase()
{

	cin >> stemp;
	{
		word = stemp[0];
		for (int a = 1; a < stemp.length(); a++)
		{
			if (word[0] > stemp[a])
			{
				word = word + stemp[a];
			}
			else
			{
			
				word = stemp[a] + word;
			}
		}

		

	}
	
	cout << word << endl;
	
}

















































int main()
{
	int cases = 0;
	freopen("a.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> cases;
	

	for (int i = 0; i < cases; i++)
	{
				
		cout << "Case #" << i + 1 << ": ";
		docase();
	}





	return 0;
}
