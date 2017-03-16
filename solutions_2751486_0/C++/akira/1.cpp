#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

long long compute(char *s, int n){
	vector<int> v;
	int l = strlen(s);
	int b = 0;
	long long r = 0;
	v.push_back(0);
	for(int i = 0; i < l; ++i){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			v.push_back(i + 1);
		}
	}
	v.push_back(l+1);
	for(int i = 0; i < v.size() - 1; ++i){
		int k = v[i + 1] - v[i] - 1;
		if(k < n){
			continue;
		}
		r += (v[i] - b + 1) * (l + 1 - v[i + 1] + 1);
		if(k - 1 >= n){
			r += (v[i] - b + 1) * (k - n);
			r += (l + 1 - v[i + 1] + 1) * (k - n);
			if(k - 2 >= n){
				r += (k - n) * (k - n - 1) / 2;
			}
		}
		b = v[i + 1] - n;
	}
	return r;
}

int main(){
	int T, t, n;
	scanf("%d", &T);
	char *s = (char *)malloc(sizeof(char) * 1000010);
	for(t = 1; t <= T; ++t){
		scanf("%s %d", s, &n);
		printf("Case #%d: %lld\n", t, compute(s, n));
	}
}