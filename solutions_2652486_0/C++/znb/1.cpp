// solution for 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <cstdio>
#include <map>
#include <deque>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

// setiosflags(ios¡Ëscientific)
// setw()
// setfill('x')
// setioflags(ios::showpos)
// setiosflags(ios¡Ëright)

#define COUT_HEX(x) hex << x
#define COUT_F_PRE(n,f) setiosflags(ios::fixed)<<setprecision(n)<<f
#define ZERO(n) memset(n,0,sizeof(n))
#define M1SET(n) memset(n,-1,sizeof(n))
#define MIN(m,n) ((m<n)?m:n)
#define MAX(m,n) ((m>n)?m:n)

#define UL unsigned long long
#define UI unsigned int
#define LL long long

#define FOR(i,a,b)   for(LL(i) = (LL)(a);(i) < (LL)(b);(i)++)
#define FOREQ(i,a,b) for(LL(i) = (LL)(a);(i) <= (LL)(b);(i)++)
#define RFOR(i,a,b)  for(LL(i) = (a), _b(b);(i) >= _b; --(i))
//#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end();itr++)
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)	 ((int)(a).size())

#define MO 1000000007UL

#define MOD(i) (i = ((i >= MO) ? i%MO : i))



int R,N,M,K;
int pro[7];

int can[4*4*4];

int proc[4*4*4][3];

int f[] = {2,3,4,5};

void init()
{
	FOR(i,0,4)
	{
		FOR(j,0,4)
		{
			FOR(k,0,4)
			{
				proc[i*j*k][0] = f[i];
				proc[i*j*k][1] = f[j];
				proc[i*j*k][2] = f[k];
			}
		}
	}
}

bool solve(istream &in,ostream &out)
{
	LL T;
	in >> T;

	init();
	
	FOR(i,0,T)
	{
		in >> R >>N >> M >> K;

		out << "Case #"<<i+1<<": "<<endl;

		FOR(j,0,R)
		{
			ZERO(can);

			FOR(k,0,K)
			{
				int input;
				in >> input;

				FOR(l,0,4*4*4)
				{
					if(0 != ((proc[l][0]*proc[l][1]*proc[l][2]) % input))
					{
							can[l] = 1;
					}
				}
			}

			int l;
			for(l = 0;l < 4*4*4;l++)
			{
				if(0 == can[l])
				{
					out << proc[l][0] <<proc[l][1] <<proc[l][2] <<endl;
					break;
				}
			}

			if(4*4*4 == l)
			{
				out << 2<<3<<4<<endl;
			}
		}
	}

	return true;
}


int main()
{
	bool bSolved;
	time_t timeBegin = time(NULL);

	#ifndef ONLINE_JUDGE
	ifstream in("in.in");
	ofstream out("out.out");
	bSolved = solve(in,out);
	#else
	bSolved = solve(cin,cout);
	#endif
	

	#ifndef ONLINE_JUDGE
	in.close();
	if(!bSolved)
		cout << "not solved Time: " << time(NULL) - timeBegin << endl;
	else
		cout << "solved Time:" << time(NULL) - timeBegin <<endl;
	system("pause");
	#endif
	
	return 0;
}
