#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/stdc++.h>

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define mod 1000000007
#define pii pair <int, int>
#define all(x) x.begin(), x.end()
//#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

//using namespace __gnu_pbds;

using namespace std;

//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int t, n, j;
int v[70];

int main()
{
	freopen("coin.out", "w", stdout);
	
	scanf("%d%d%d", &t, &n, &j);
	
	v[1] = v[2] = 1;
	v[n] = v[n-1] = 1;
	int a = 2;
	int now = 3;
	cout << "Case #1:\n";
	while (1) {
		for (int i = now; i <= n-2; i+=2) {
			for (int h = now+1; h <= n-2; h+=2) {
				v[i] = v[h] = 1;
				
				if (j > 0) {
					for (int j = 1; j <= n; j++)
						cout << v[j];
					cout << " ";
					for (int j = 3; j <= 11; j++)
						cout << j << " ";
					cout << "\n";
					j--;
				}
				
				v[i] = v[h] = 0;
			}
		}
		
		swap(v[a], v[a+1]);
		a++;
		swap(v[a], v[a+1]);
		a++;
		now = a+1;
		
		if (j == 0)
			break;
	}
}
