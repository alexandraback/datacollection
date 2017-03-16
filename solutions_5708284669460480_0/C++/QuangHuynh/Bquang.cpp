#include <bits/stdc++.h>
using namespace std;

char xau[7];
std::vector<int> v;
int k, l, s, res, sum, h;
string sl, sk;

int power(int a, int b){
	int res = 1;
	while (b > 0){
		res *= a;
		b--;
	}
	return(res);
}

void recursion(int m){

	if (m==0){
		int res = 0;
		bool check;

		for (int i=0; i < s-l+1; i++){
			check = true;
			for (int j = 0; j < l; j++)
				if (xau[j+i] != sl[j]){
					check = false;
					break;
				}
			if (check){
				res ++;
			}
		}
		v.push_back(res);
		return ;
	}
	for (int i=0; i< k; i++){
		xau[s-m] = sk[i];
		if (m > 0){
			recursion(m-1);
		}
	}
}

int main(){
	int test;
	freopen("B.in", "r",stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &test);
	for (int i=1; i<= test; i++){
		scanf("%d %d %d", &k, &l, &s);
		cin >> sk;
		cin >> sl;
		v.clear();
		int h = power(k, s);
		recursion(s);
		res = 0;
		sum = 0;
		for (int j = 0; j < v.size(); j++){
			res = max(res, v[j]);
		}
		for (int j = 0; j < v.size(); j++){
			sum += (res - v[j]);
		}
		printf("Case #%d: %.10f\n",i, (double) sum / h);
	}
}