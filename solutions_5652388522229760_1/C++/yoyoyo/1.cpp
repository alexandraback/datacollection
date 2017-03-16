#include <stdio.h>
#include <iostream>
#include <string> 
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	int n, calc, count;
	int arr[10];
	for(int t = 1; t <= T; t++)
	{
		cin >> n;
		printf("Case #%d: ", t);

		for(int i = 0; i < 10; i++)
			arr[i] = 0;
		
		for(int i = 1; i < 100; i++){
			calc = n * i;
			string check = to_string(calc);
			for(int j = 0; j < check.length(); j++)
				arr[check[j] - '0'] = 1;

			count = 0;
			for(int j = 0; j < 10; j++)
				if(arr[j] == 1)
					count++;
			if(count == 10)
				break;
		}

		if(count == 10)
			cout << calc << endl;
		else
			cout << "INSOMNIA" << endl;
	}
}