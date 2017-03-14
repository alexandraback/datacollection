#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <set>

#define DEBUG 0
#define BUFFER_SIZE 100

using namespace std;

void fillX(double odd, double even, double arr[], double limit)
{
	int i = 0;
	arr[0] = 2*odd;
	do
	{
		i++;
		arr[i] = arr[i-1] + 2*odd + 2*even;
	}
	while(arr[i]<=limit);
	arr[i] = 2*odd + 2*even;
	do
	{
		i++;
		arr[i] = arr[i-1] + 2*odd + 2*even;
	}
	while(arr[i]<=limit);
}

void fillY(double odd, double even, double arr[], double limit)
{
	arr[0] = 0;
	fillX(odd, even, arr+1, limit);
}

int countFirstQuardant(double oddX, double evenX, double oddY, double evenY, double limit)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	double value = 0;
	double arrX[BUFFER_SIZE];
	double arrY[BUFFER_SIZE];
	set<double> myset;

	fillX(oddX, evenX, arrX, limit);
	fillY(oddY, evenY, arrY, limit);
	while (arrX[i+1]<=limit) i++;
	while (arrY[j+1]<=limit) j++;
	k = j;
	while(i>=0)
	{
		j = k;
		while(j>=0)
		{
			if (arrX[i]*arrX[i]+arrY[j]*arrY[j]-limit*limit<=0)
			{
				value = arrY[j]/arrX[i];
				if (myset.find(value)==myset.end())
				{
					myset.insert(value);
				}
			}
			j--;
		}
		i--;
	}
	return myset.size();
}

int main(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int T = 0;
	double H = 0;
	double W = 0;
	double h = 0;//people location
	double w = 0;//people location
	double D = 0;
	int count = 0;
	char buffer[BUFFER_SIZE];

	ifstream inFile("D-small-attempt1.in");
	ofstream outFile("result.out");
	inFile >> T;
	for (i=0;i<T;i++)
	{
		outFile<<"Case #"<<i+1<<": ";
		count = 0;
		inFile >> H >> W >> D;
		inFile.getline(buffer, BUFFER_SIZE);
		for (j=0;j<H;j++)
		{
			inFile.getline(buffer, BUFFER_SIZE);
			for (k=0;k<W;k++)
			{
				if (buffer[k]=='X')
				{
					h = j+1;
					w = k+1;
				}
			}
		}
#if DEBUG
		cout<<H<<W<<h<<w<<D<<endl;
#endif
		count += countFirstQuardant(W-w-0.5, w-1.5, h-1.5, H-h-0.5, D);
		count += countFirstQuardant(h-1.5, H-h-0.5, w-1.5, W-w-0.5, D);
		count += countFirstQuardant(w-1.5, W-w-0.5, H-h-0.5, h-1.5, D);
		count += countFirstQuardant(H-h-0.5, h-1.5, W-w-0.5, w-1.5, D);
		outFile<<count<<endl;
	}
	inFile.close();
	outFile.close();
#if DEBUG
	cin>>i;
#endif
	return 0;
}
