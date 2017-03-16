#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<vector>
#include<cctype>
#include<iomanip>
#include<cmath>
#include<fstream>

# define F(i, n) 	for( int i = 0; i < (n); i++)
# define Fi(i, m, n) 	for( int i = (m); i < (n); i++)
# define Fr(i, n) 	for( int i = (n); i > 0; i-- )
# define Fri(i, m, n)	for( int i = (m); i > n; i-- )
# define P 		printf
# define Pd(x) 		printf("%d" , x )
# define PN 		printf("\n")
# define S 		scanf
# define Sd(x) 		scanf("%d",&x)
# define PB 		push_back
# define SZ(x) 		((int)((x).size()))
# define VI		vector<int>
# define SI		set<int>

typedef long long ll;

ll mod = (ll)1000000007;

using namespace std;


int main()
{
	
	int test;
	ifstream in("in.txt");
	ofstream out("out.txt");
	
	in >> test;
	Fi(i,1,test+1)
	{
		int n, s, p, ti;
		in >> n >> s >> p;
		int tcount = 0;
		F(j, n)
		{
			in >> ti;
			int minno = ti/3;
			int maxno = minno;
			int dif = ti - minno*3;
			bool possible = true;
			if( dif == 1) possible = false;
			if( dif == 0 && minno == 0) possible = false;
			if(dif) maxno ++;
			if(maxno >= p)tcount ++;
			else
			if(possible)
			if(maxno >= p-1 && s > 0)
			{
				tcount ++;
				s--;
			}
		}
		out << "Case #" << i << ": " << tcount << endl;
	}
	in.close();
	out.close();
	return 0;
}
