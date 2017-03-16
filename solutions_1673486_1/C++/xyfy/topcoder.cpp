#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<bitset>
#include<list>
using namespace std;

int main()
{
	 freopen("d:\\A-large.in", "r", stdin);
	 freopen("d:\\A-large.out", "w", stdout);
	int A,B,T;
	vector<double> sum;
	double sm ;
	vector<double>score;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		score.clear();
		sum.clear();
		sm = 1;
		cin >>A>>B;
		double temp=0;
		for(int j = 0;j < A;j++)
		{
			cin>>temp;
			sm =sm* temp;
			sum.push_back(sm);
		}
		int X = B-A+1;
		int Y = 2*B-A+2;
		score.push_back(sum[A-1]*X+(1.0-sum[A-1])*Y);
		score.push_back(B+2);
		int xx = X;
		int yy = Y;
		for(int k = 1;k < A;k++)
		{
			xx+=2;
			yy+=2;
			score.push_back(sum[A-k-1]*xx+((1-sum[A-k-1])*yy));
		}

		double min = 0xFFFFFFFF;
		for(int m = 0;m < score.size();m++)
		{
			if(min > score[m])
				min = score[m];
		}
		printf("Case #%d: %.6lf\n",i,min);
	}
	return 0;
}
