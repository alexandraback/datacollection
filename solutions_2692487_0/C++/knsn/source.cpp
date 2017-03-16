#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define cin(n) scanf("%d",&n)
#define gc getchar
typedef vector<int> VI;
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}
int a, n; 
int idx , ans , temp;
VI  arr; 
int main(){
	int tests=fcin();
	for(int cases = 1 ; cases <= tests; cases ++){
		a = fcin(); 
		n = fcin(); 
		arr.resize(n); 
		for(int i=0;i<n;i++)arr[i] = fcin(); 
		sort(arr.begin(),arr.end()); 
		idx = ans = 0; 
		ans = n; 
		temp = n;
		for(;idx < n && a != 1; idx++, temp --){
			ans = min(ans,temp);
			while (a <= arr[idx]) {
				a = 2*a -1 ; 
				temp ++; 
			}
			a += arr[idx];
		}
		ans = min(temp,ans); 
		printf("Case #%d: %d\n",cases,ans); 
	}
	return 0;
}
