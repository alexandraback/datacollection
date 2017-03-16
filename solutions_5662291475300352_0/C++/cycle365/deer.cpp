#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

int testCases, n, d, h, m, tempn, ans;
vi pos;
vi v;

int main(){
	scanf("%d", &testCases);
	for(int t = 1; t <= testCases; t++){
		pos.clear();
		v.clear();
		scanf("%d", &tempn);
		n = 0;
		for(int i = 0; i < tempn; i++){
			scanf("%d %d %d", &d, &h, &m);
			n += h;
			for(int j = 0; j < h; j++){
				pos.push_back(d);
				v.push_back(m+j);
			}
		}
		
		bool doable = true;
		if(v[0] > v[1]){
			swap(v[0], v[1]);
			swap(pos[0], pos[1]);
		}
		long long slowFin = v[1] * (long long)(360 - pos[1]);
		long long fastFin = v[0] * (long long)(720 - pos[0]);
		if(fastFin <= slowFin){
			ans = 1;
		} else {
			ans = 0;
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
