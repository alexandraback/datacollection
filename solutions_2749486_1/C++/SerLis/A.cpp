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

   long long n,t, k, res , kol;

int  main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int i=1; i<=t; i++)
	{
		res=0;
		kol=0;
		long long X, Y;
		string s;
		cin >> X >> Y;
		cout << "Case #" << i << ": ";
		if ((abs(X)+abs(Y))%2==1)
		{
			while(kol<abs(X)+abs(Y) || res%4==0 || res%4==3)
			{
				res++;
				kol+=res;
			}

		}
		else
		{
			while(kol<abs(X)+abs(Y) || res%4==1 || res%4==2)
			{
				res++;
				kol+=res;
			}
		}
		while(abs(X)+abs(Y)>0)
		{
			if(X>0 && abs(X)>=abs(Y))
			{
				s='E'+s;
				X=X-res;
			}
			else
			{
			if(X<0 && abs(X)>=abs(Y))
			{
				s='W'+s;
				X=X+res;
			}
			else
			{
			if(Y>0 && abs(X)<abs(Y))
			{
				s='N'+s;
				Y=Y-res;
			}
			else
			{
			if(Y<0 && abs(X)<abs(Y))
			{
				s='S'+s;
				Y=Y+res;
			}
			}}}
			res--;
		}



		cout << s << "\n";
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