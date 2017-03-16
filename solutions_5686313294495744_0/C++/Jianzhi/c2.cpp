#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
typedef pair<string, string> pi;
int tc, n;
pi word[1005];
set<string> f, s; //first, second words

int arr[16];

int count(){
	int res = 0;
	for (int i = 0; i < n; i++){
		res += (1 - arr[i]);
	}
	return res;
}

bool check(){ //returns true if full
	for (int i = 0; i < n; i++){
		if (arr[i] == 0) return false;
	}
	return true;
}

void addone(){
	for (int i = n - 1; i >= 0; i--){
		if (arr[i] == 0){
			arr[i] += 1;
			break;
		} else {
			arr[i] = 0;
		}
	}
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("csmall.txt", "w", stdout);
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++){
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		s.clear();
		f.clear();
		for (int j = 0; j < n; j++){
			cin >> word[j].first >> word[j].second;
		}
		int answer = 0;
		while (!check()){
			s.clear();
			f.clear();
			bool can = true;
			for (int j = 0; j < n; j++){
				if (arr[j] == 1){
					f.insert(word[j].first);
					s.insert(word[j].second);
				}
			}
			
			for (int j = 0; j < n; j++){
				if (arr[j] == 1) continue;
				if (f.find(word[j].first) == f.end() || s.find(word[j].second) == s.end()){
					can = false;
					break;
				}
			}
			
			if (can){
				answer = max(answer, count());
			}
			addone();
		}
		
		printf("Case #%d: %d\n", i + 1, answer);
		
	}
	
}
