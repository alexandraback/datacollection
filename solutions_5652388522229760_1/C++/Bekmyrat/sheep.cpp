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
int v[20];
int Case;
int t;
ll n;

int main()
{
	freopen("sheep.in", "r", stdin);
	freopen("sheep.out", "w", stdout);
	scanf("%d", &t);
	
	while (t--) {
		scanf("%lld", &n);
		
		for (int i = 0; i < 10; i++)
			v[i] = 0;
		
		ll x = 1;
		
		if (n != 0) {
		while (1) {
			ll k = x*n;
			
			while (k)
				v[k%10]++, k/=10;
			
			bool ok = 0;
			for (int i = 0; i < 10; i++)
				if (!v[i]) ok = 1;
			
			if (!ok)
				break;
			
			x++;
		}}
		
		printf("Case #%d: ", ++Case);
		
		if (n == 0)
			printf("INSOMNIA\n");
		else
			printf("%lld\n", x*n);
	}
}

