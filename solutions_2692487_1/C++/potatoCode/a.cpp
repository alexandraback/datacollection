#include<iostream>
#include<cstdlib>

using namespace std;

int Mote;
int n;
int foods[100];
int cmp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int stepper(int curMode, int i)
{
	for(;i<n;i++)
	{
		if(foods[i]<curMode)
			curMode+=foods[i];
		else break;
	}
	if(i==n) return 0;
	int cancelAll=n-i;
	if(curMode<2) return cancelAll;
	
	int stepsToEnlarge=0;
	while(curMode<=foods[i])
	{
		curMode=2*curMode-1;
		stepsToEnlarge++;
	}
	stepsToEnlarge+=stepper(curMode,i);
	return stepsToEnlarge<cancelAll?stepsToEnlarge:cancelAll;
}

int submain()
{
	int i;
	cin >> Mote >> n;
	for(i=0;i<n;i++)
		cin >> foods[i];
	qsort(foods,n,sizeof(int),cmp);
	cout << stepper(Mote,0) << endl;

}

int main()
{
	int t;
	cin >> t;
	for (int a=0;a<t;a++)
	{
		cout << "Case #" << a+1 << ": ";
		submain();
	}
	return 0;
}
