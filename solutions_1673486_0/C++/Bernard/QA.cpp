#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <utility>

#define EPS 1e-6
#define MT 100000

using namespace std;

double correct[MT];
double result;
int typed, total;

double maskToProb(int mask)
{
	double prob=1;
	for(int i=0; i<typed; i++)
		if(mask&(1<<(typed-1-i)))
			prob*=correct[i];
		else
			prob*=double(1)-correct[i];
	return prob;
}
int keepTyping(int mask)
{
	int allCorrect=(1<<typed)-1;
	if(mask==allCorrect)
		return total-typed+1;
	return 2*total+2-typed;
}
int pressBackspace(int back, int mask)
{
	//correct after backspace
	if(mask>>back==((1<<(typed-back))-1))
		return back*2+total-typed+1;
	return (back+total)*2-typed+2;
}
double solve()
{
	//press enter right away
	double result=total+2;

	//keep typing
	int pow=1<<typed;
	double keep=0;
	for(int i=0; i<pow; i++)
		keep+=maskToProb(i)*keepTyping(i);
	if(result-EPS>keep)
		result=keep;

	//press backspace
	for(int backspace=1; backspace<=typed; backspace++)
	{
		double press=0;
		for(int i=0; i<pow; i++)
			press+=pressBackspace(backspace, i)*maskToProb(i);
		if(result-EPS>press)
			result=press;
	}
	return result;
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int c=1; c<=t; c++)
	{
		scanf("%d %d", &typed, &total);
		for(int i=0; i<typed; i++)
			scanf("%lf", correct+i);
		printf("Case #%d: %lf\n", c, solve());
	}
	return 0;
}
