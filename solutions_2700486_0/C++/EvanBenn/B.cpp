#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long int ll;
typedef long double ld;

#define pb push_back
#define for0(a,b) for(int a = 0; a < b; a++)


using namespace std;

ld c(int n, int y)
{
	if (n < y) return 0.0;
	ld den = 1.0;
	ld num = 1.0; 
	for (int i =  1  ; i <= y   ; i = i+1)
	    den =    den * i;
	for (int j = n-y+1; j<=n; j=j+1)	
	    num = num * j;
	return(num/den);
	
}

int main()
{
	int T;
	cin >> T;
	for0(t,T)
	{
		//cerr << t << endl;
		ll N, X, Y;
		cin >> N >> X >> Y;
		X = abs(X);
		Y= abs(Y);
		int L = 1;
		while (L*(2*L-1) < N)
			L++;
		int L2 = (X+Y)/2 + 1;
		
		
		//cout << L << " " << L2 << endl;
		if (L2 < L)
		{
			cout << "Case #" << t +1 << ": " << "1.0" << endl;
		}
		else if (L2 > L)
		{
			cout << "Case #" << t +1 << ": " << "0.0" << endl;
		}
		else
		{
			N -= (L-1)*(2*(L-1)-1);
			
			if ((L-1)*2 + Y < N)
				cout << "Case #" << t +1 << ": " << "1.0" << endl;
			else if (Y + 1 > N || Y == L)
				cout << "Case #" << t +1 << ": " << "0.0" << endl;
			else
			{
				//cout << N << L << L2 << endl;
				ld p = 0.0;
				for(int k = Y+1; k < 2*L; k++)
					p += c(N,k);
				p *= pow(0.5,N);
				cout << "Case #" << t +1 << ": " << p << endl;
			}			
		}
		
	}
}

