#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <string.h>
using namespace std;
#pragma comment(linker, "/STACK:50000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "A-large";

void init(){
	freopen((problem_name+".in").c_str(),"rt",stdin);
	freopen((problem_name+".out").c_str(),"wt",stdout);
}



double mas[222];
double res[222];


int main() {

	init();

	int tst;
	scanf("%d\n",&tst);
	for (int cas=1;cas<=tst;cas++)
	{
		int n;
		scanf("%d",&n);
		double sum=0;
		for (int i=0;i<n;i++) {
			scanf("%lf",&mas[i]);
			sum+=mas[i];
		}
		for (int i=0;i<n;i++)
		{
			double l=0,r=1;
			
			for (int step=1;step<=60;step++)
			{
				double x=(l+r)/2;
				double need= mas[i]+sum*x;
				double tot=x;
				for (int j=0;j<n;j++) if (i!=j)
				{
					double t= (need - mas[j])/sum;
					if (t<0) t=0;
					tot+=t;
				}
				if (tot<=1) l=x; else r=x;
			}		
			res[i]=r;
		}
	
	
		printf("Case #%d: ",cas);
		for (int i=0;i<n;i++)
			printf("%.8lf ",res[i]*100);
		printf("\n");
	}

	
	

	return 0;
}