#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>

#include <cmath>
#include <cstring>
#include <cstdio>
#include <time.h>
using namespace std;

#if 0
#include "generic.h"
#define cin fin
#define cout fout
#endif

typedef long double ld;

int main()
{
	//FILE* fp = fopen("c:\\test\\b.out","w");
	int t,ca;
	cin>>t;
	//clock_t f1 = clock();
	for(ca=1;ca<=t;ca++)
	{ //no easy way in recurrence to apply bisection/binary search over real numbers
		ld c,f,x;
		cin>>c>>f>>x;
		ld farmtime = 0.0, gaintime = 0, totaltime=x/2; //t(0)
		ld mintime = totaltime;
		ld mingaintime = gaintime;
		int n = 1;
		int runcounter = 5000;
		int minn;

		ld mintimeb = totaltime;
		ld totaltimeb; //gaintime method

		for(int i=0;i<100000;i++) //stop criteria could be abs value of gaintime on each iteration; or/and difference from min calculated so far
		{ //t(n) = t(n-1) + (c-x)/(2+(n-1)*f) + x/(2+n*f)
			

#ifdef methodb		
			gaintime += 1/(2+(n-1)*f);
			totaltimeb = gaintime*c + x/(2+n*f);
			if(mintime > totaltimeb)
			{
				mintime = totaltimeb;
			}
#else
			totaltime = totaltime + (c-x)/(2+(n-1)*f) + x/(2+n*f);
			if(mintime > totaltime)
			{
				//if(n>99000 && (totaltime-mintime > 1e-7 || totaltime-mintime <-1e-6))
				//	cout<<n<<" =huge="<<totaltime-mintime<<endl;
				mintime = totaltime;
				//mingaintime = gaintime;
				//minn = n;
				//ld ntotaltime = mingaintime*c + x/(2+n*f);
				//ld diff = ntotaltime-mintime;
				//if(diff >1e-10 || diff < -1e-10)
				//	cout<<n<<"\tdiff= "<<ntotaltime-mintime<<"\ttot= "<< totaltime<<endl;
			}
#endif
			else
			{
				if(--runcounter<=0)
					break;
				
			}
			n++;
		}
		//if(mintimeb-mintime > 1e-12 || mintimeb-mintime < -1e-12)
		//	cout<<mintimeb-mintime<<" huge";
		//cout<<c<<" "<<f<<" "<<x<<" "<<n<<endl;
		printf( "Case #%d: %0.7lf\n",ca,mintime);
	}
	//clock_t f2 = clock();
	//cout<<"Time "<<f2-f1;
	return 0;
}