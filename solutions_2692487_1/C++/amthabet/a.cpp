#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
#define LARGE 1

int n;
int arr[200];

int f(int a, int ind) {
	if(ind == n)
		return 0;
	if(arr[ind] < a)
		return f(a+arr[ind], ind+1);
	if(a == 1)
		return n-ind;
	return min(n-ind, f(a+a-1,ind)+1);
}

int main() {
#ifdef LARGE
	freopen("a_large.i", "rt", stdin);
	freopen("a_large.o", "wt", stdout);
#elif SMALL
	freopen("a_small.i", "rt", stdin);
	freopen("a_small.o", "wt", stdout);
#else
	freopen("a_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int a;
		cin>>a>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		cout << "Case #"<<tt<<": "<<f(a,0)<<endl;
	}

	return 0;
}
