#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	string winner,input;
	cin >> N;
	char curr[2] = "";
	for( int i = 1 ; i <= N ; i++)
	{
		cin >> input;
		curr[0] = input[0];
		winner = "" + string(curr);
		//cout << winner << endl;
		for( int j = 1 ; j < input.length() ; j++ )
		{
			curr[0] = input[j];
			if( input[j] >= winner[0] )
			{
				winner = string(curr) + winner;
			}
			else
			{
				winner = winner + string(curr);
			}
		}
		cout << "Case #" << i << ": " << winner << endl;
	}
	
	return 0;
}
