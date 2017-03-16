#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long lint;

int a, b;

int pow10(int len) {
	int res = 1;
	for (int i=0; i<len; i++)
		res *= 10;
	return res;
}

bool check(int n[], int k) {
	for (int i=0; i<k; i++)
		if (n[i] == n[k])
			return false;
	return true;
}

int find(int num) {
	int len = log10(double(num)) + 1;
	int n[10];
	n[0] = num;
	int res = 0;

	for (int i=1; i<len; i++) {
		n[i] = (n[i-1]/10) + (n[i-1]%10)*pow10(len-1);
		if (n[i]>=a && n[i]<=b && check(n,i))
			res++;
	}
	return res;
}

int main() {
	freopen("c-small-attempt0.in", "r", stdin);
	freopen("c-small.out", "w", stdout);

	int t;
	lint res;

	cin>>t; cin.ignore();
	for (int k=1; k<=t; k++) {
		res = 0;
		cin>>a>>b;
		for (int i=a; i<=b; i++)
			res += find(i);

		printf("Case #%d: ", k);
		cout<<res/2<<endl;
	}	
	return 0;
}
