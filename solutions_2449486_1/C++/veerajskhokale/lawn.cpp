/*
 * lawnmower.cpp
 *
 *  Created on: 13-Apr-2013
 *      Author: veerajskhokale
 */

#include <iostream>
using namespace std;

int T , N , M;
int lawn[1000][1000];

bool Check(int x , int y)
{
	bool flag1 = 0 , flag2 = 0;
	for(int i = 0 ; i < N ; i++)
		if(lawn[i][y] > lawn[x][y])
			flag1 = 1;
	for(int i = 0 ; i < M ; i++)
		if(lawn[x][i] > lawn[x][y])
			flag2 = 1;
	if(flag1 && flag2) return false;
	return true;
}

int main()
{
	bool flag;
	cin >> T;
	for(int i = 0 ; i < T ; i++)
	{
		cin >> N >> M;
		for(int j = 0 ; j < N ; j++)
			for(int k = 0 ; k < M ; k++)
				cin >> lawn[j][k];
		flag = 0;
		for(int j = 0 ; j < N ; j++)
			for(int k = 0 ; k < M ; k++)
				if(!Check(j , k))
				{
					flag = 1;
					break;
				}
		if(flag) cout << "Case #" << i + 1 << ": " << "NO\n";
		else cout << "Case #" << i + 1 << ": " << "YES\n";
	}
	return 0;
}

