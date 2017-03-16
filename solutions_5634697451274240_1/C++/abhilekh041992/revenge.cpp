#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip> 
#include<utility> 
#include<climits>
#include<climits>
#include<cmath>
#include<algorithm>


using namespace std;


#define LL long long int
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pr1(x) printf("%d\n", x)
#define FOR(i, a, n) for(int i=a;i<n;i++)
#define pp pair<int, int>

#define MAX 1000001
#define MOD 1000000007LL

char str[200];


void reverse(int left, int right) {
	while(left <= right) {
		char temp = str[left];
		str[left] = (str[right]=='-') ? '+' : '-';
		str[right] = (temp=='-') ? '+' : '-';
		left++; right--;
	}
}


int func(int left, int right) {
	if(left > right) return 0;

	if(str[right] == '+') return func(left, right-1);
	else if(str[left] == '-') {
		reverse(left, right);
		return 1 + func(left, right-1);
	} else {
		int x = right-1;
		while(x>left) {
			if(str[x] == '+') break;
			x--;			
		}

		reverse(left, x);
		return 1 + func(left, right);
	}
}


int main() {

	int t;


	sc1(t);
	FOR(i, 1, t+1) {
		scanf("%s", str);

		printf("Case #%d: %d\n", i, func(0, strlen(str)-1));
	}
	return 0;
}













