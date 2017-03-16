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
double allFirstCorrect[MT];
int typed, total;

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
	double allCorrect=1, typing;
	for(int i=0; i<typed; i++)
		allCorrect*=correct[i];
	typing=allCorrect*(total-typed+1)+(double(1)-allCorrect)*(2*total+2-typed);
	if(result-EPS>typing)
		result=typing;

	//press backspace
	//	erase all typed
	double temp;
	if(result-EPS>typed+total+1)
		result=typed+total+1;

	//	erase some typed
	allFirstCorrect[0]=correct[0];
	for(int i=1; i<typed; i++)
		allFirstCorrect[i]=allFirstCorrect[i-1]*correct[i];
	for(int back=1; back<typed; back++)
	{
		double firstCorrect=allFirstCorrect[typed-back-1];
		temp=firstCorrect				*(back*2+total-typed+1)+
		     (double(1)-firstCorrect)	*((back+total)*2-typed+2);
		if(result-EPS>temp)
			result=temp;
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
