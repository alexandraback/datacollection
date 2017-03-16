#include <iostream>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;
/*int selectionsort(int a[1000], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int temp = a[i], pos = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < temp)
			{
				temp = a[j];
				pos = j;
			}
		}
		a[pos] = a[i];
		a[i] = temp;
	}
}
int binarysearch(int a[10000], int n, int item)
{
	int beg = 0, end = n-1; mid;
	mid = (beg+end)/2;
	while (beg <= end)
	{
		if (a[mid] == item)
			return mid+1;
		else if (a[mid] > item)
			end = mid - 1;
		else
			beg = mid + 1;
		mid = (beg+end)/2;
	}
}*/
int main()
{
	ifstream input_file("/home/aneesh/Downloads/A-small-attempt3.in", ios::in);
	ofstream output_file("output.out", ios::out);
	long long int t, r, c, w, num_places, guess = 0, temp = 0;
	input_file>>t;
	for (long long int i = 1; i <= t; i++)
	{
		input_file>>r>>c>>w;
		num_places = r*(c-w+1);
		//guess += w+(r-1)+(c-w-1);
		if (num_places == r)
			guess = w+(r-1);
		else
		{
			//guess += w+(r-1)*((c-w)/w)+((num_places)/r)-1;
			guess = (r-1)*(c/w) + (w+(c-1)/w);
		}
		output_file<<"Case #"<<i<<": "<<guess<<"\n";
		guess = 0;
	}
}
