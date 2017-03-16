#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
#include <numeric>
using namespace std;

 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 typedef long long ll;
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

bool solve (string train)
{
	bool m[256] = {0};
	m[ (int) train[0]] = 1;
	
	for (int i=1 ; i<sz(train) ; i++)
	{
		if (train[i] != train[i-1] && m[ (int)train[i]]) return 0;
		m[(int)train[i]]=1;
	}
	
	//cout << train << endl;
	return 1;
}

int main ()
{
	freopen("B_small.in","r",stdin);
	//freopen("B_small.out","w",stdout);
	
	int TC;
	cin >> TC;
	int CC=1;
	
	while (TC--)
	{
		int N;
		cin >> N;
		
		vector<string> list;
		vi v;
		
		for (int i=0 ; i<N ; i++)
		{
			string s;
			cin >> s;
			list.pb(s);
			v.pb(i);
		}
		
		ll ways=0;
		
		do
		{
			string train;
			for (int i=0 ; i<sz(v) ; i++)
			{
				train += list[v[i]];
			}
			
			if (solve(train))
			{
				ways++;
			}
		} while (next_permutation(all(v)));
		
		printf("Case #%d: ",CC++);
		
		cout << ways << endl;
	}
}
