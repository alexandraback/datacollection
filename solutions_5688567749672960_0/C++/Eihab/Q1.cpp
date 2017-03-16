// Q1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define FO(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

using namespace std;

int getMin(int arr[], int count)
{
	int min = arr[0];
	for (int i = 1; i < count; i++)
		if (arr[i] < min)
			min = arr[i];

	return min;
}

int getMax(int arr[], int count)
{
	int max = arr[0];
	for (int i = 1; i < count; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

void SortAsc(int arr[], int count)
{
    int temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void SortDesc(int arr[], int count)
{
    int temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

ll flip(ll n)
{
	int nums[20];
	ll number = 0;

	int index = 0;
	while (n > 0)
	{
		nums[index++] = n % 10;
		n = n / 10;
	}

	for (int i = 0; i < index; i++)
	{
		number += nums[i] * pow((double)10, index - i - 1);
	}

	return number;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("q1.in", "r", stdin);
	freopen("q1.out", "w", stdout);

	int t;
	cin >> t;

	FO(i, 0, t)
	{
		cout << "Case #" << i + 1 << ": ";

		ll n;

		cin >> n;

		/*ll count = 0;
		ll num = 1;

		while (num <= n)
		{
			if (flip(num) > num && flip(num) <= n)
				num = flip(num);
			else
				num++;
			count++;
		}*/

		ll num = n % 10;
		if (num == 0)
			num = 10;
		num = n - num + 1;

		ll num2 = flip(num);
		long solution = num2 + 1;
		solution += n - num;
		if (solution > n)
			solution = n;

		cout << solution << endl;
	}

	return 0;
}

