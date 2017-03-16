#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>
#include <climits>
#include <sstream>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define mod 10
#define B 33
#define MAX 100011
#define eps 1e-7
#define ull unsigned long long

double pi = acos(-1);

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

int main() {
	
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		ll a,b,kat;
		ll total =0;

		cin>>a>>b>>kat;

		for (int j = 0; j < a; ++j)
		{
			for (int k = 0; k < b; ++k)
			{
				if((j&k) < kat)
					total++;
			}
		}
		cout<<"Case #"<<i+1<<": "<<total<<endl;


	}
	return 0;
}