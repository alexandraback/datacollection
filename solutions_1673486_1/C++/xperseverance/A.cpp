// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <omp.h>
#include <time.h>
#include <iomanip>

using namespace std;

double slove(int a, int b, vector<double> & vc)
{
	double ret = a+b+1;	//all backspace
	ret = min(ret, (double)b+2);	// just enter

	int rest = b-a+1;
	for(int i=0; i<a; i++)
	{
		int correct = rest+i*2;
		int error = rest+i*2 + b+1;

		double correct_rate = 1.0;
		for(int j=0; j<a-i; j++)
		{
			correct_rate *= vc[j];
		}

		ret = min(ret, correct_rate*correct + (1.0-correct_rate)*error);
	}
	return ret;
}

int main()
{
	int n,a,b;
	ifstream inf("in-A.txt");
	ofstream outf("out-A.txt");

	inf>>n;
	for(int zi=1; zi<=n; zi++)
	{
		inf>>a>>b;
		vector<double> vc;
		for(int pi=0; pi<a; pi++)
		{
			double s;
			inf>>s;
			vc.push_back(s);
		}
		outf<<setiosflags(ios::fixed);
		outf<<setprecision(10)<<"Case #"<<zi<<": "<<slove(a,b,vc)<<endl;
	}


	inf.close();
	outf.close();

	return 0;
}

