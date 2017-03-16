#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		int k,l,s;
		scanf("%d %d %d",&k,&l,&s);
		if(l>s){
			printf("Case #%d: 0.0\n",i);
			continue;
		}
		string keys, target;
		cin >> keys;
		cin >> target;
		double freq[26];
		for(int j = 0; j < 26; j++){
			freq[j] = 0;
		}
		for(int j = 0; j < k; j++){
			freq[(int)(keys[j]-'A')] += 1.0/k;
		}
		int repeat = 0;
		for(int j =1; j < l; j++){
			if(target.substr(0,l-j) == target.substr(j,l-j)){
				repeat = j;
				break;
			}
		}
		double p = 1, q = 1;
		for(int j = 0 ; j < l; j++) p *= freq[(int)(target[j]-'A')];
		for(int j = 0 ; j < repeat; j++) q *= freq[(int)(target[j]-'A')];
		if(repeat == 0) q = 0;
		int max = 0;
		if(repeat == 0) max = s/l;
		else max = (s-l)/repeat + 1;
		double expected = 0;
		for(int j = 1 ; j <= max; j++){
			double probability = 0;
			for(int k = 1; k <= j; k++){
				if(k*l + (j-k)*repeat > s) break;
				probability += pow(p,k)*pow(q,j-k)*pow(k,j-k);
			}
			expected += j*probability;
		}
		printf("Case #%d: %f\n",i,max - expected);
	}
}