/*
 * lawnmower.cpp
 *
 *  Created on: 13-Apr-2013
 *      Author: veerajskhokale
 */

#include <iostream>
using namespace std;

int main()
{
	int T , count;
	long long int A , B;
	long long int fs[] =
	{
		1 ,
		4 ,
		9 ,
		121 ,
		484
	};
	cin >> T;
	for(int i = 0 ; i < T ; i++)
	{
		count = 0;
		cin >> A >> B;
		for(int j = 0 ; j < 5 ; j++)
			if(fs[j] >= A && fs[j] <= B)
				count++;
		cout << "Case #" << i + 1 << ": " << count << "\n";
	}
	return 0;
}

