#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

int k, l, s;
int same = 0;

int alpha[100];
string keys, target;
char can[1000];

void backtrack(int x){
	
	if(x == s){
		
		can[x] = 0;
		
		for(int i = 0; i <= s-l; i++){
			
			bool legit = true;
			
			for(int j = 0; j < l; j++){
				
				if(can[i + j] != target[j]){
					legit = false;
					break;
				}
				
			}
			
			if(legit){
				same++;
			}
			
		}
		return;
	}
	
	for(int i = 0; i < k; i++){
		can[x] = keys[i];
		backtrack(x+1);
	}
	
	return;
	
}

int main(){

	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);

	int tc;
	cin >> tc;
	
	for(int w = 0; w < tc; w++){
		
		cin >> k >> l >> s;
		cin >> keys >> target;

		
		for (int i = 0; i < 26; i++){
			alpha[i] = 0;
		}
		
		for (int i = 0; i < k; i++){
			alpha[keys[i] - 'A']++;
		}
		
		bool legit = true;
		
		for (int i = 0; i < l; i++){
			if (!alpha[target[i] - 'A']){
				legit = false;
			}
		}
		
		if(!legit){
			printf("Case #%d: 0.000000\n", w + 1);
			continue;
		}
		
		int cmax=0;
		
		for (int i = 1; i <= l; i++){
			legit = true;
			for (int j = 0; i + j < l; j++){
				if (target[i + j] != target[j]){
					legit = false;
					break;
				}
			}
			
			if (legit){
				cmax = (s - (l - i))/i;
				break;
			}
		}
		
		same = 0;
		backtrack(0);
		
		int total = 1;
		
		for(int i = 0; i < s; i++){
			total*=k;
		}
		
		double answer= (double)cmax- ((double)same/(double)total);
		
		printf("Case #%d: %f\n", w + 1, answer);
	}
}
