#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cmath>
using  namespace std;

#define MAX 100010

double p[MAX];
int A,B;


double add(double a,double b)
{
	return log(a) + log(b);
}
int solve_single(int case_num);

int main(int argc, char**argv)
{
    if (argc != 2)
	{
             printf("usage:%s input file! \n", argv[0]);
             return 0;
	}
	string line;
	ifstream fin(argv[1]);
	if (fin.fail())
	{
		printf("open file %s error!\n", argv[1]);
	}
	int total_case;
	fin >> total_case;
	for(int i = 0; i < total_case; i++)
	{
		fin >> A >> B;
		for(int j = 0; j < A; j++)
		{
			fin >> p[j];
		}
		solve_single(i+1);
	}


	fin.close();
	return 0;

}
int solve_single(int case_num)
{
	double init = 0;
	//continue
	double con = 0;
	double pc = init;
	for(int i = 0; i < A; i++)
	{
		pc += log(p[i]);
	}
	con = (1-exp(pc)) * (B-A + B +2) + exp(pc)*(B-A + 1);

	double ry =  B + 2;
	double d[MAX];
	d[0] = log(p[0]);
	double min = ry < con ? ry:con;
	
	for(int i = 1; i <=A-1; i++)
	{
		d[i] = d[i-1] + log(p[i]);
		double r = exp(d[i-1]) * (2*(A-i) + B-A + 1) + (1-exp(d[i-1])) *(2*(A-i) + B-A+2 + B);
		if (r < min)
		{
			min = r;
		}
 	}
	double da = 2*A + (B-A) + 1;
	if (da < min)
	{
		min = da;
	}

	printf("Case #%d: %.6f\n",case_num,min);



	return 0;
}
