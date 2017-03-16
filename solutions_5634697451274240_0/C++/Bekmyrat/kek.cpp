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

int Case;
int t;
char s[200];
int main()
{
	freopen("kek.in", "r", stdin);
	freopen("kek.out", "w", stdout);
	scanf("%d", &t);
	
	while (t--) {
		scanf("%s", s);
		
		int n = strlen(s);
		
		int ans = 0;
		for (int i = n-1; i >= 0; i--) {
			if (s[i] == '-') {
				for (int h = i; h >= 0; h--)
					s[h] = (s[h] == '-' ? '+' : '-');
				ans++;
			}
		}
		
		printf("Case #%d: ", ++Case);
		printf("%d\n", ans);
	}
}

