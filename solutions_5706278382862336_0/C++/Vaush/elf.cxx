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
#include <cstring>
#define ii pair<int,int>
#define iii pair<ii,int>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>

using namespace std;
typedef long long ll;
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int evaluate(ll p, ll q){
	int counter = 0;
	ll temp = gcd(p,q);
	
	p /= temp;
	q /= temp;
	if(p == 1){
		while(q != 1){
			q = (q >> 1);
			counter++;
		}
		return counter;
	}
	ll toev = 1;
	ll den = (q >> 1);
	while(p-toev > den) toev++;
	return 1+min(evaluate(toev, den), evaluate(p-toev, den));
}
int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int times;
	cin >> times;
	for(int time = 1; time <= times; time++){
		ll p, q;
		char bin;
		cin >> p >> bin >> q;
		ll temp = gcd(p,q);
		p /= temp;
		q /= temp;
		if((q & (q-1)) != 0){
			cout << "Case #" << time << ": impossible" << endl;
			continue;
		}

		ll val = evaluate(p, q);
		if(val > 40){
			cout << "Case #" << time << ": impossible" << endl;
		}else{
			cout << "Case #" << time << ": " << val << endl;
		}	
	}
	return 0;
}

