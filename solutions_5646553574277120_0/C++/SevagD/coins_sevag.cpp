#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int T;
int C, D, V;
int denom[1000];
int targets[1000];

void getCoverage(int i, int amount)
{
	if (i==D){
		targets[amount] =1;
		return;
	}

	for (int c=0; c<=C; c++)
	{
		getCoverage(i+1, amount+c*denom[i]);
	}
	return;
}

int getMinNotCovered(){
	for (int i=1; i<V; i++){
		if (targets[i]==0)
			return i;
	}
	return -1;
}


int main()
{
	ifstream cin;
	cin.open("C-small-attempt0.in");

	ofstream cout;
	cout.open("coins_sevag_small.out");



	cin>>T;

	for (int t=1; t<=T; t++)
	{
		cin>>C>>D>>V;
		for (int i=0; i<D; i++) {
			cin>>denom[i];
		}


		int ans = 0;

		fill(&targets[0], &targets[0]+35, 0);

		getCoverage(0,0);

		int minNot = getMinNotCovered();
		while (minNot !=-1)
		{
			denom[D] = minNot;
			D++;
			ans++;

			getCoverage(0,0);
			minNot = getMinNotCovered();
		}

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}