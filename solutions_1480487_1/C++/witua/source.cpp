#include <iostream>   
#include <sstream>   
#include <cstdio>   
#include <cstdlib>   
#include <cmath>   
#include <memory>   
#include <cctype>   
#include <string>   
#include <vector>   
#include <list>   
#include <queue>   
#include <deque>   
#include <stack>   
#include <map>   
#include <set>   
#include <algorithm>   
using namespace std;  
   
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))  
#define INF 1000000000  
#define PB push_back  
#define ALL(c) (c).begin(), (c).end()  
#define pi 2*acos(0.0)  
#define SQR(a) (a)*(a)  
#define MP make_pair  
#define MAX 256
   
typedef unsigned long long Int;  

int n, T;
int S[MAX];

int main()
{
	//freopen("C:\\Users\\Віталік\\Desktop\\GCJ 2012\\Round 1B\\.in", "r", stdin);
	//freopen("C:\\Users\\Віталік\\Desktop\\GCJ 2012\\Round 1B\\.out", "w", stdout);

	cin >> T;	
	FOR (t,0,T)
	{
		cin >> n;
		FOR (i,0,n)
			cin >> S[i];

		cout << "Case #" << t+1 << ": ";

		double sum = 0.0;
		FOR (i,0,n)
			sum += S[i];

		FOR (i,0,n)
		{
			if (i != 0)
				cout << ' ';
			double Min = 0, Max = 1.0;
			FOR (it,0,74)
			{
				double Mid = (Min + Max)/2.0;
				double sum2 = 0;
				FOR (j,0,n)
				{
					if (i == j)
						continue;
					double d = S[i] - S[j] + Mid*sum;
					d /= sum;
					sum2 += d;
				}
				if (sum2 + Mid <= 1 + 1E-12)
					Min = Mid;
				else
					Max = Mid;
			}
			printf("%0.9f", Min*100.0);
		}
		cout << endl;
	}
	return 0;
} 