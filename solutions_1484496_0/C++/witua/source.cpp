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

int n, tt;
int A[MAX];
int T[MAX];
vector <int> R1;
vector <int> R2;

void F(int pos, int s0, int s1)
{
	if (!R1.empty())
		return;

	if (pos == n)
	{
		if (s0 == s1 && s0 != 0)
		{
			FOR (i,0,n)
				if (T[i] == 0)
					R1.PB(A[i]);
				else
				if (T[i] == 1)
					R2.PB(A[i]);
			return;			
 		}
	}
	else
	{
		T[pos] = 2;
		F(pos+1, s0, s1);
		T[pos] = 0;
		F(pos+1, s0 + A[pos], s1);
		T[pos] = 1;
		F(pos+1, s0, s1 + A[pos]);
	}
}

int main()
{
	freopen("C:\\Users\\Віталік\\Desktop\\GCJ 2012\\Round 1B\\A-large.in", "r", stdin);
	freopen("C:\\Users\\Віталік\\Desktop\\GCJ 2012\\Round 1B\\A-large.out", "w", stdout);

	cin >> tt;	
	FOR (t,0,tt)
	{
		R1.clear();
		R2.clear();
		cin >> n;
		FOR (i,0,n)
			cin >> A[i];
		sort(A, A+n);

		F(0, 0, 0);

		cout << "Case #" << t+1 << ":" << endl;
		if (R1.empty())
			cout << "Impossible" << endl;
		else
		{
			FOR (i,0,R1.size())
			{
				if (i != 0)
					cout << ' ';
				cout << R1[i];
			}
			cout << endl;
			FOR (i,0,R2.size())
			{
				if (i != 0)
					cout << ' ';
				cout << R2[i];
			}
			cout << endl;
		}
	}
	return 0;
} 