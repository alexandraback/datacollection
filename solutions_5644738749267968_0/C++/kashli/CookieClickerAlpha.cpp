/*
 * DeceitfulWar.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: Ganesh
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#define iter(i, N) for(long long i=0 ; i<N ; i++)

using namespace std;

int main()
{
	long long cases;
	cin>>cases;
	iter(q, cases)
	{
		int N;
		double b;
		cin>>N;
		vector<double> naomi, ken;

		iter(i, N)
		{
			cin>>b;
			naomi.push_back(b);
		}
		iter(i, N)
		{
			cin>>b;
			ken.push_back(b);
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		int d_points=N, u_points=0;
		for(int i=N-1 ; i>=0 ; i--)
		{
			if(ken[i] > naomi[N-1])
				d_points--;
			else
				break;
		}
		for(int i=N-d_points ; i<N; i++)
		{
				if(naomi[i] > ken[0])
					break;
				d_points--;
		}
		bool used[1000];
		iter(i, N)
			used[i] = false;
		int b_i=0,j=N-1;
		for(int i=N-1 ; i>=0 &&  b_i < j; i--)
		{
			if(naomi[i] > ken[j])
			{
				used[b_i++] = true;
				u_points++;
			}
			else
			{
				used[j--] = true;
			}
		}

		cout<<"Case #"<<q+1<<": "<< d_points << " "<< u_points <<"\n";
	}
	return 0;
}




