/*
 * kingdom.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: firat
 */

#include <iostream>
#include <cstdio>

using namespace std;



void find_best_level(int** visit, int& level, int& leveltype, int N, int stars)
{
	int max_type2 = -2;
	int max_type2_who = -1;
	int max_type1 = -2;
	for(int i = 0; i < N; i++)
	{
		if(visit[i][1] != -1 && stars >= visit[i][1] && visit[i][1] >= max_type2 && visit[i][0] > max_type1)
		{
			max_type2 = visit[i][1];
			max_type1 = visit[i][0];
			max_type2_who = i;
		}
	}
	if(max_type2_who == -1)
	{
		int max_type2a = -2;
		int max_type1_who = -1;
		int max_type1a = -2;
		for(int i = 0; i < N; i++)
		{
			if(visit[i][0] != -1 && stars >= visit[i][0] && visit[i][0] >= max_type1a && visit[i][1] > max_type2a)
			{
				max_type2a = visit[i][1];
				max_type1a = visit[i][0];
				max_type1_who = i;
			}
		}
		if(max_type1_who == -1)
		{
			leveltype = -1;
			return;
		}
		else
		{
			leveltype = 1;
			level = max_type1_who;
		}
	}
	else
	{
		leveltype = 2;
		level = max_type2_who;
		return;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		int** visit = new int*[N];
		for(int j = 0; j < N; j++)
		{
			visit[j] = new int[2];
			cin >> visit[j][0];
			cin >> visit[j][1];
		}


		int stars = 0;
		int steps = 0;
		bool failed = false;
		while(stars != 2*N)
		{
			int level, leveltype;
			find_best_level(visit, level, leveltype, N, stars);
			steps++;
			if(leveltype == 1)
			{
				visit[level][0] = -1;
				stars++;
			}
			else if(leveltype == 2)
			{
				if(visit[level][0] == -1)
				{
					stars++;
				}
				else
				{
					visit[level][0] = -1;
					stars = stars + 2;
				}
				visit[level][1] = -1;
			}
			else
			{
				failed = true;
				break;
			}
			//cout << "VISIT:" << stars<<endl;
			//for(int q =0; q < N; q++)
			//{
			//	cout << visit[q][0] << " " << visit[q][1] << endl;
			//}
		}


		if(failed)
		{
			cout << "Case #" << i+1 << ": Too Bad" << endl;
		}
		else
		{
			cout << "Case #" << i+1 << ": " << steps << endl;
		}
		//free memory
		for(int j = 0; j < N; j++)
		{
			delete[] visit[j];
		}
		delete[] visit;
	}
	return 0;
}




