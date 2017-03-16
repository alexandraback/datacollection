/*
 * senza nome.cxx
 * 
 * Copyright 2014 Vaush Wolf <healtyerslord@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define ii pair<int,int>
#define iii pair<ii,int>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
using namespace std;

int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int times;
	cin >> times;
	for(int time = 1; time <= times; time++){
		int a, b, k;
		cin >> a >> b >> k;
		int c = 0;
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				if((i & j) < k) c++;
			}
		}
		cout << "Case #" << time << ": " << c << endl;

 

	
	}
	return 0;
}

