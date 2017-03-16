#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iterator>
#include<fstream>
using namespace std;

double CaseOne(int A,int B,vector<double> p)
{
	int strokes1=B-A+1;
	double expect1=strokes1;
	for(int i=0;i<p.size();i++)
		expect1*=p[i];
	int strokes2=B-A+1+B+1;
	double expect2=strokes2;
	double temp=expect2;
	for(int i=0;i<p.size();i++)
		expect2=expect2*p[i];
	expect2=temp-expect2;
	return expect1+expect2;	
}

double CaseTwo(int A,int B,vector<double> p)
{
	double res=-1;
	for(int i=1;i<=A;i++)
	{
		int strokes1=B-(A-i)+1+i;
		double expect1=strokes1;
		for(int j=0;j<p.size()-i;j++)
			expect1*=p[j];
		int strokes2=B-(A-i)+1+i+B+1;
		double expect2=strokes2;
		double temp=expect2;
		for(int j=0;i<p.size()-j;j++)
			expect2*=p[j];
		expect2=temp-expect2;
		if(expect1+expect2<res || res==-1)
			res=expect1+expect2;
	}
	return res;
}


double CaseThree(int A,int B,vector<double> p)
{
	int strokes=B+1+1;
	double expect=strokes;
	return expect;
}

int main()
{
	ifstream ifs("A-large.in");
	ofstream ofs("A-large.out");
	int testCase;
	ifs>>testCase;
	int id=1;
	while(id<=testCase)
	{
		int A,B;
		ifs>>A>>B;
		vector<double> p(A);
		for(int i=0;i<p.size();i++)
			ifs>>p[i];
		double res1,res2,res3;
		res1=CaseOne(A,B,p);
		res2=CaseTwo(A,B,p);
		res3=CaseThree(A,B,p);
		double res=min(res1,min(res2,res3));
		ofs<<fixed;
		ofs<<"Case #"<<id<<": "<<setprecision(6)<<res<<endl;
		id++;
	}
	ifs.close();
	ofs.close();
	system("pause");
}