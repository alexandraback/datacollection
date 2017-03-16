#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
using namespace std;


double C;
double F;
double X;
double TotalTime;
double Solve(double cost,double produce,double maxcookies)
{
	TotalTime = 0.0;
	int BuyFarmNum=0;
	double CurProduce=2.0;//current produce
	double WaitTime;
	double AssumeBuyAnotherFarmTime;
	WaitTime = maxcookies/CurProduce;
	AssumeBuyAnotherFarmTime = cost/CurProduce + maxcookies/(CurProduce+produce);
	while(WaitTime>AssumeBuyAnotherFarmTime)
	{
		TotalTime = TotalTime+ cost/CurProduce;
		CurProduce = CurProduce + produce;
		WaitTime = maxcookies/CurProduce;
		AssumeBuyAnotherFarmTime = cost/CurProduce + maxcookies/(CurProduce+produce);
	}
	TotalTime = TotalTime + maxcookies/CurProduce;
	return TotalTime;
}
void main()
{
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(7);
	freopen("B-large.in", "r", stdin);
	//freopen("1.txt", "r", stdin);
	//freopen("B-small-practice0.out", "w", stdout);
	//freopen("2.txt", "w", stdout);
	freopen("B-large.out", "w", stdout);
	
	int i,j;
	int Numcase;
	cin>>Numcase;
	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		cin>>C;
		cin>>F;
		cin>>X;
		cout<<Solve(C,F,X)<<endl;
	}
	fclose(stdout);
}