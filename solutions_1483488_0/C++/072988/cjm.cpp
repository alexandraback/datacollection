#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int T;
int A, B;
int n;
vector <int> tmp;
map <int, bool> Map;

int split(int A, vector <int>& a){
	a.clear();
	int len = 0;
	while(A){
		a.push_back(A % 10);
		A /= 10;
		len ++;
	}
	reverse(a.begin(), a.end());
	return len;
}

int Cal(int val){
	int ans = 0;
	vector <int> num;
	Map.clear();
	int len = split(val, num);
	for(int i = 1; i < len; i ++){
		if(num[i] != 0){
			int tmp = 0;
			for(int j = i; j < len; j ++){
				tmp = tmp * 10 + num[j];
			}
			for(int j = 0; j < i; j ++){
				tmp = tmp * 10 + num[j];
			}
			if(tmp >= A && tmp <= B && Map.find(tmp) == Map.end() && tmp > val){
				Map[tmp] = true;
				ans ++;
			}
		}
	}

	return ans;
}

int main(){
	scanf("%d", &T);

	for(int t = 1; t <= T; t ++){
		scanf("%d%d", &A, &B);
		int ans = 0;
		for(int i = A; i <= B; i ++){

			ans += Cal(i);
		}
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}