#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200;
const int inf = 2000000;

int motes[MAXN];

int main(){
	int testcases;
	scanf("%d", &testcases);
	
	for(int testcase = 0; testcase < testcases; testcase++){
		int curr, n;
		scanf("%d%d", &curr, &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &motes[i]);
		
		sort(motes, motes + n);
		
		int currbest = inf;
		int c = 0;
		
		for(int i = 0; i < n; i++){
			//printf("%d %d\n", curr, motes[i]);
			if(curr > motes[i])
				curr += motes[i];
			else{
				currbest = min(currbest, c + n-i);
				
				while(curr <= motes[i] && (curr - 1) > 0)
					curr += curr-1, c++;
				
				if(curr - 1 <= 0){
					c = inf;
					break;
					}
				else
						curr += motes[i];
					
				}
			}
		currbest = min(currbest, c);
		
		printf("Case #%d: %d\n", testcase+1, currbest);
		}
	
	
	return 0;
}
