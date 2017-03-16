#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

int mx(int a, int b)
{
	if(a>b) return a;
	return b;
}
int mn(int a, int b)
{
	if(a<b) return a;
	return b;
}

//Returns maximum gain with gains given by v and current energy C
int maxgain(int C, int E, int R, int N, vector<int> v)
{
	//Look at current energy remaining
	//For each integer up to that, see what happens when we spend that much
	//printf("Called N=%d: C=%d\n",N, C);
	int max = 0;
	int store = 0;
	vector<int> w;

	//If only one activity left, spend all energy
	if(N==1) return v[0]*C;

	//w is remaining activities once first is gone
	for(int k=1;k<=N-1;k++)
	{
		w.push_back(v[k]);
	}

	for(int j = 0;j<=C;j++)
	{
		max = mx(max,  j*v[0] + maxgain(mn(E, (C+R)-j), E, R, N-1, w));
	}
	//printf("N=%d returning %d\n", N, max);
	return max;
}


int main(int argc, char** argv){

	int T;
	scanf(" %d",&T);
	int E, R, N;
	int k;
	vector<int> v;


	for(int i=1;i<=T;i++)
	{
		v.clear();
		scanf(" %d %d %d", &E, &R, &N);
		for(int j = 0;j<N;j++)
		{
			scanf(" %d", &k);
			v.push_back(k);
		}

		printf("Case #%d: %d\n",i, maxgain(E, E, R, N, v));

	}

	return 0;
}
