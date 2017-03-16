#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for (int st=0; st<t; ++st)
	{
		printf ("Case #%d:", st+1);
		int n;
		cin>>n;
		vector <int> v(n);
		int X=0;

		for (int i=0; i<n; ++i) {
			cin>>v[i];
			X+=v[i];
		}

		vector <double> vv(n);
		int num=0;
		double ost=0;
		for (int i=0; i<n; ++i){
			vv[i]=v[i]/(X+0.0);
			if (vv[i]<(2/(n+0.0))) {++num; ost+=vv[i];}
		}

		for (int i=0; i<n; ++i)
		{
			if (vv[i]>=(2/(n+0.0)))
				printf(" %.6f", 1-1);
			else
			{
				double tr=(1+ost-vv[i]*(num))/(num+0.0);
				printf(" %.6f", 100*tr);
			}


		}

		
		printf("\n");


	}


}