#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;

typedef pair<double,int> pi;

const int maxn = 1010;

double a[maxn];
double b[maxn];

int main() {
	int t;
	cin >> t;
	rep(g,t){
		int n;
		cin >> n;
		rep(i,n)
			cin >> a[i];
		rep(i,n)
			cin >> b[i];
		sort(a,a+n);
		sort(b,b+n);
		int top = n-1, first = 0;
		int cnt = 0;
		for(int i=n-1;i>=0;i--)
			if(a[i] > b[top]){
				cnt++;
				first++;
			}else
				top--;
		int ptr = 0;
		int cnt1 = 0;
		rep(i,n){
			while(ptr < n && a[ptr] < b[i])
				ptr++;
			if(ptr >= n)
				break;
			cnt1++;
			ptr++;
		}
		cout << "Case #" << g+1 << ": " << cnt1 << " " << cnt << endl;
	}
	return 0;
}
